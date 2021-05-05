using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace Task3
{
    interface IDecorator : IDatabase
    {
        public IDatabase Database { get; set; }
    }

    class Filter : IDecorator
    {
        public IDatabase Database { get; set; }
        private Func<VirusData, bool> FilterFunc { get; set; }

        public Filter(IDatabase database, Func<VirusData, bool> f)
        {
            Database = database;
            FilterFunc = f;
        }

        public IEnumerable Iterate(IGenomeDatabase genomeDatabase)
        {
            foreach (VirusData virus in Database.Iterate(genomeDatabase))
            {
                if (FilterFunc(virus))
                {
                    yield return new VirusData(virus.VirusName, virus.DeathRate, virus.InfectionRate, virus.Genomes);
                }
            }
        }
    }

    class Mapping : IDecorator
    {
        public IDatabase Database { get; set; }
        private Func<VirusData, VirusData> MapFunc { get; set; }

        public Mapping(IDatabase database, Func<VirusData, VirusData> m)
        {
            Database = database;
            MapFunc = m;
        }

        public IEnumerable Iterate(IGenomeDatabase genomeDatabase)
        {
            foreach (VirusData virus in Database.Iterate(genomeDatabase))
            {
                yield return MapFunc(virus);
            }
        }
    }

    class Concat : IDecorator
    {
        public IDatabase Database { get; set; }
        private IDatabase SecondDatabase { get; set; }

        public Concat(IDatabase database1, IDatabase database2)
        {
            Database = database1;
            SecondDatabase = database2;
        }

        public IEnumerable Iterate(IGenomeDatabase genomeDatabase)
        {
            foreach (VirusData virus in Database.Iterate(genomeDatabase))
            {
                yield return virus;
            }
            foreach (VirusData virus in SecondDatabase.Iterate(genomeDatabase))
            {
                yield return virus;
            }
        }
    }
}

