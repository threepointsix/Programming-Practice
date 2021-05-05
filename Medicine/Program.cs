using System;
using System.Collections.Generic;
using Task3.Subjects;
using Task3.Vaccines;

namespace Task3
{
    class Program
    {

        public class MediaOutlet
        {
            IGenomeDatabase SimpleGenomeDatabase { get; set; }

            public MediaOutlet(IGenomeDatabase genomeDatabase)
            {
                SimpleGenomeDatabase = genomeDatabase;
            }

            public void Publish(IDatabase database)
            {
                foreach (VirusData virus in database.Iterate(SimpleGenomeDatabase))
                {
                    Console.WriteLine(virus.ToString());
                }
            }
        }

        public class Tester
        {
            public void Test()
            {
                var vaccines = new List<IVaccine>() { new AvadaVaccine(), new Vaccinator3000(), new ReverseVaccine() };

                foreach (var vaccine in vaccines)
                {
                    Console.WriteLine($"Testing {vaccine}");
                    var subjects = new List<ISubject>();
                    int n = 5;
                    for (int i = 0; i < n; i++)
                    {
                        subjects.Add(new Cat($"{i}"));
                        subjects.Add(new Dog($"{i}"));
                        subjects.Add(new Pig($"{i}"));
                    }

                    foreach (var subject in subjects)
                    {
                        subject.GetVaccine(vaccine);
                        // process of vaccination
                    }

                    var genomeDatabase = Generators.PrepareGenomes();
                    var simpleDatabase = Generators.PrepareSimpleDatabase(genomeDatabase);
                    // iteration over SimpleGenomeDatabase using solution from 1)
                    // subjects should be tested here using GetTested function


                    foreach (VirusData virus in simpleDatabase.Iterate(genomeDatabase))
                    {
                        foreach (var subject in subjects)
                        {
                            subject.GetTested(virus);
                        }
                    }

                    int aliveCount = 0;
                    foreach (var subject in subjects)
                    {
                        if (subject.Alive) aliveCount++;
                    }
                    Console.WriteLine($"{aliveCount} alive!");
                }
            }
        }
        public static void Main(string[] args)
        {
            var genomeDatabase = Generators.PrepareGenomes();
            var simpleDatabase = Generators.PrepareSimpleDatabase(genomeDatabase);
            var excellDatabase = Generators.PrepareExcellDatabase(genomeDatabase);
            var overcomplicatedDatabase = Generators.PrepareOvercomplicatedDatabase(genomeDatabase);
            var mediaOutlet = new MediaOutlet(genomeDatabase);

            Console.WriteLine("------ Simple database ------\n");
            mediaOutlet.Publish(simpleDatabase);
            Console.WriteLine("\n------ Excel database ------\n");
            mediaOutlet.Publish(excellDatabase);
            Console.WriteLine("\n------ Overcomplicated database ------\n");
            mediaOutlet.Publish(overcomplicatedDatabase);

            Console.WriteLine("\n------ Decorators: filter Excel by DeathRate > 15 ------\n");
            Func<VirusData, bool> f = virus => virus.DeathRate > 15;
            IDecorator filteredByDeathRate = new Filter(excellDatabase, f);
            mediaOutlet.Publish(filteredByDeathRate);


            Console.WriteLine("\n------ Decorators: increased death rate of each Excel virus by 10 and then filtered by DeathRate > 15 ------\n");
            Func<VirusData, VirusData> m = virus => new VirusData(virus.VirusName, virus.DeathRate + 10, virus.InfectionRate, virus.Genomes);
            IDecorator MappingAndFiltering = new Mapping(excellDatabase, m);
            MappingAndFiltering = new Filter(MappingAndFiltering, f); // or we can declare two different IDecorator objects: IDecorator NotMappingAndFiltering = new Filter(MappingAndFiltering...);
            mediaOutlet.Publish(MappingAndFiltering);

/*            Console.WriteLine("\n------ Decorators: concat excel and overcomplicated databases ------");
            IDecorator concat = new Concat(excellDatabase, overcomplicatedDatabase);
            mediaOutlet.Publish(concat);*/

            Console.WriteLine();

            // testing animals
            var tester = new Tester();
            tester.Test();
        }
    }
}
