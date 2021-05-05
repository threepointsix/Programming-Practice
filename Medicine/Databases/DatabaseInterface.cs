using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace Task3
{
    public interface IDatabase
    {
        public IEnumerable Iterate(IGenomeDatabase genomeDatabase);
    }
}
