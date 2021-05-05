using System;
using System.Collections.Generic;
using System.Text;

namespace Task3
{
    public interface IGenomeDatabase
    {
        // Some common methods for all Genome Databases
        List<GenomeData> genomeDatas { get; }
    }
}
