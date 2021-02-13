using System;
using System.IO;
using System.Xml.Serialization;
using System.Text;


namespace Lab13
{
    public class Database
    {
        private readonly string _baseDir;

        private static int UserNum = 0;
        private static int ProductNum = 0;
        private static int OrderNum = 0;


        public Database(string baseDir)
        {
            _baseDir = baseDir;

            if (!Directory.Exists(_baseDir))
            {
                Directory.CreateDirectory(_baseDir);
            }
        }

        /// <summary>
        /// Adds new object to the database.
        /// If the object with the given Id and the same type exists, the exception should be thrown.
        /// If Id == 0 the value of Id should be replaced by te max Id value for TEntity object type + 1
        /// </summary>

        // TODO: Implement Add method

        public void Add<TEntity>(TEntity entity) where TEntity : IEntity
        {
            var typeName = typeof(TEntity).Name;

            if (entity.Id == 0)
            {
                if (entity is Order)
                {
                    entity.Id = OrderNum;
                    OrderNum++;
                }
                if (entity is Product)
                {
                    entity.Id = ProductNum;
                    ProductNum++;
                }
                if (entity is User)
                {
                    entity.Id = UserNum;
                    UserNum++;
                }
            }

            else
            {
                if (entity is Order)
                {
                    OrderNum++;
                }
                if (entity is Product)
                {
                    ProductNum++;
                }
                if (entity is User)
                {
                    UserNum++;
                }
            }
            
            StringBuilder path2 = new StringBuilder();

            path2.Append(typeName);
            path2.Append("_");
            path2.Append(entity.Id);

            string path = Path.Combine(_baseDir, path2.ToString());

            if (File.Exists(path)) throw new Exception();

            FileStream fs = new FileStream(path, FileMode.Create);
            XmlSerializer xs = new XmlSerializer(typeof(TEntity));
            xs.Serialize(fs, entity);
            fs.Close();
        }

        /// <summary>
        /// Get retrieves an object from the database. 
        /// If the object with the given Id does not exist, the exception should be thrown.
        /// </summary>

        // TODO: Implement Get method

        public TEntity Get<TEntity>(int id) where TEntity : IEntity
        {

            var typeName = typeof(TEntity).Name;
            StringBuilder path2 = new StringBuilder();

            path2.Append(typeName);
            path2.Append("_");
            path2.Append(id);

            string path = Path.Combine(_baseDir, path2.ToString());

            if (!File.Exists(path)) throw new Exception();

            FileStream fs = new FileStream(path, FileMode.Open);
            XmlSerializer xs = new XmlSerializer(typeof(TEntity));
            TEntity returnVal = (TEntity)xs.Deserialize(fs);
            fs.Close();

            return returnVal;
        }


        /// <summary>
        /// Updates object in the database.
        /// If the object with the given Id does not exist, the exception should be thrown.
        /// </summary>

        // TODO: Implement Update method

        public void Update<TEntity>(TEntity entity) where TEntity : IEntity
        {
            var typeName = typeof(TEntity).Name;

            StringBuilder path2 = new StringBuilder();

            path2.Append(typeName);
            path2.Append("_");
            path2.Append(entity.Id);

            string path = Path.Combine(_baseDir, path2.ToString());

            if (!File.Exists(path)) throw new Exception();

            FileStream fs = new FileStream(path, FileMode.Truncate);
            XmlSerializer xs = new XmlSerializer(typeof(TEntity));
            xs.Serialize(fs, entity);
            fs.Close();
        }

        /// <summary>
        /// Deletes object from the database.
        /// If the object with the given Id does not exist, the exception should be thrown.
        /// </summary>

        // TODO: Implement Delete method

        public void Delete<TEntity>(int id)
        {
            var typeName = typeof(TEntity).Name;
            StringBuilder path2 = new StringBuilder();

            path2.Append(typeName);
            path2.Append("_");
            path2.Append(id);

            string path = Path.Combine(_baseDir, path2.ToString());


            if (!File.Exists(path)) throw new Exception();

            File.Delete(path);
        }
    }

    public class User : IEntity
    {
        public int Id { get; set; }

        public string FirstName { get; set; }

        public string LastName { get; set; }

        /// <summary>
        /// Property computed from FirstName and LastName.
        /// It should not be serialized to the file.
        /// </summary>
        
        [XmlIgnore] // Not neccessary? (xml file ignore this field even without this attribute)
        public string FullName => $"{FirstName} {LastName}";

        public override string ToString()
        {
            return $"USER: Id {Id}, FullName: {FullName}";
        }
    }

    public class Product : IEntity
    {
        public int Id { get; set; }

        public string Name { get; set; }

        public override string ToString()
        {
            return $"PRODUCT: Id: {Id}, Name {Name}";
        }
    }

    public class Order : IEntity
    {
        public Order() {}

        public Order(User user, Product product, int amount)
        {
            UserId = user.Id;
            ProductId = product.Id;
            Amount = amount;
        }

        public int Id { get; set; }

        public int UserId { get; set; }

        public int ProductId { get; set; }

        public int Amount { get; set; }

        public override string ToString()
        {
            return $"ORDER: Id {Id}, UserId: {UserId}, ProductId: {ProductId}, Amount: {Amount}";
        }
    }
}
