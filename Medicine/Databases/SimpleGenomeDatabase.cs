using System.Collections.Generic;

namespace Task3
{
    public class SimpleGenomeDatabase : IGenomeDatabase
    {
        public List<GenomeData> genomeDatas { get; }

        public SimpleGenomeDatabase(List<GenomeData> genomeDatas)
        {
            this.genomeDatas = genomeDatas;
        }
    }
}
