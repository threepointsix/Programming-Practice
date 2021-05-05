using System;
using System.Collections;
using System.Collections.Generic;

namespace Task3
{
    public class ExcellDatabase : IDatabase
    {
        public string Names { get; }
        public string DeathRates { get; }
        public string InfectionRates { get; }
        public string GenomeIds { get; }

        public ExcellDatabase(string names, string deathRates, string infectionRates, string genomeIds)
        {
            Names = names;
            DeathRates = deathRates;
            InfectionRates = infectionRates;
            GenomeIds = genomeIds;
        }

        public IEnumerable Iterate(IGenomeDatabase genomeDatabase)
        {
            string[] namesArr = Names.Split(';');   
            string[] deathsArr = DeathRates.Split(';');
            string[] infectionsArr = InfectionRates.Split(';');
            string[] genomesArr = GenomeIds.Split(';');

            for (int i = 0; i < namesArr.Length; i++)
            {
                foreach (GenomeData genomeData in genomeDatabase.genomeDatas)
                {
                    if (Guid.Parse(genomesArr[i]).Equals(genomeData.Id))
                    {
                        yield return new VirusData(namesArr[i], double.Parse(deathsArr[i]), double.Parse(infectionsArr[i]), new List<GenomeData> { genomeData });
                    }
                }
            }

        }
    }

    public class SimpleDatabaseRow
    {
        public string VirusName { get; set; }
        public double DeathRate { get; set; }
        public double InfectionRate { get; set; }
        public Guid GenomeId { get; set; }
    }

    public class SimpleDatabase : IDatabase
    {
        public IReadOnlyList<SimpleDatabaseRow> Rows { get; }
        public SimpleDatabase(IEnumerable<SimpleDatabaseRow> simpleDatabaseRows)
        {
            var list = new List<SimpleDatabaseRow>();
            list.AddRange(simpleDatabaseRows);

            Rows = list;
        }

        public IEnumerable Iterate(IGenomeDatabase genomeDatabase)
        {
            foreach (SimpleDatabaseRow row in Rows)
            {
                foreach (GenomeData genomeData in genomeDatabase.genomeDatas)
                {
                    if (row.GenomeId.Equals(genomeData.Id))
                    {
                        yield return new VirusData(row.VirusName, row.DeathRate, row.InfectionRate, new List<GenomeData> { genomeData });
                    }
                }
            }
        }
    }
}
