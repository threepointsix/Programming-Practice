using System.Collections;
using System.Collections.Generic;

namespace Task3
{
    public interface INode
    {
        public string VirusName { get; set; }
        public double DeathRate { get; set; }
        public double InfectionRate { get; set; }
        public string GenomeTag { get; set; }
        public List<INode> Children { get; }

    }

    public class StructuredDataNode : INode
    {
        public string VirusName { get; set; }
        public double DeathRate { get; set; }
        public double InfectionRate { get; set; }
        public string GenomeTag { get; set; }
        public List<INode> Children { get; } = new List<INode>();

        public StructuredDataNode(string virusName, double deathRate, double infectionRate, string genomeTag)
        {
            VirusName = virusName;
            DeathRate = deathRate;
            InfectionRate = infectionRate;
            GenomeTag = genomeTag;
        }
    }

    public class OvercomplicatedDatabase : IDatabase
    {
        public INode Root { get; }

        public OvercomplicatedDatabase(INode root)
        {
            Root = root;
        }

        public IEnumerable Iterate(IGenomeDatabase genomeDatabase)
        {
            List<GenomeData> genomes = new List<GenomeData>();
            Stack<INode> nodes = new Stack<INode>();
            INode current;
            nodes.Push(Root);

            genomes = FindTag(Root, genomeDatabase);
            yield return new VirusData(Root.VirusName, Root.DeathRate, Root.InfectionRate, genomes);

            while (nodes.Count > 0)
            {
                current = nodes.Pop();
                foreach (INode node in current.Children)
                {
                    nodes.Push(node);
                    genomes = FindTag(node, genomeDatabase);
                    yield return new VirusData(node.VirusName, node.DeathRate, node.InfectionRate, genomes);
                }
            }
        }

        private List<GenomeData> FindTag(INode node, IGenomeDatabase genomeDatabase)
        {
            List<GenomeData> genomeDatas = new List<GenomeData>();

            foreach (GenomeData genomeData in genomeDatabase.genomeDatas)
            {
                foreach (string tag in genomeData.Tags)
                {
                    if (node.GenomeTag.Equals(tag) && !genomeDatas.Contains(genomeData))
                    {
                        genomeDatas.Add(genomeData);
                    }
                }
            }

            return genomeDatas;
        }
    }
}
