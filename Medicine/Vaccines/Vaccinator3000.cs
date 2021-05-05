using System;
using System.Collections.Generic;
using System.Text;
using Task3.Subjects;

namespace Task3.Vaccines
{
    class Vaccinator3000 : IVaccine
    {
        public string Immunity => "ACTG";
        public double DeathRate => 0.1f;

        private Random randomElement = new Random(0);
        public override string ToString()
        {
            return "Vaccinator3000";
        }

        public void Vaccinate(Dog dog)
        {
            string dogimmune = "";
            for (int i = 0; i < 3000; i++)
            {
                dogimmune += Immunity[randomElement.Next(0, 4)];
            }
            dog.Immunity = dogimmune;

            if (DeathRate > randomElement.NextDouble())
            {
                dog.Alive = false;
                Console.WriteLine($"Dog {dog.ID} has died from {ToString()}");
            }
        }

        public void Vaccinate(Cat cat)
        {
            string catimmune = "";
            for (int i = 0; i < 300; i++)
            {
                catimmune += Immunity[randomElement.Next(0, 4)];
            }
            cat.Immunity = catimmune;

            if (DeathRate > randomElement.NextDouble())
            {
                cat.Alive = false;
                Console.WriteLine($"Cat {cat.ID} has died from {ToString()}");
            }
        }

        public void Vaccinate(Pig pig)
        {
            string pigimmune = "";
            for (int i = 0; i < 15; i++)
            {
                pigimmune += Immunity[randomElement.Next(0, 4)];
            }
            pig.Immunity = pigimmune;

            if (3 * DeathRate > randomElement.NextDouble())
            {
                pig.Alive = false;
                Console.WriteLine($"Pig {pig.ID} has died from {ToString()}");
            }
        }
    }
}
