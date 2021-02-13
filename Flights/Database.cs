using System;
using System.Collections.Generic;

namespace Lab14
{
    public class Transport
    {
        public uint Id { get; set; }
        public string Name { get; set; }
        // amount of money per 1 km needed for a maintenance of the transport
        public double Cost { get; set; }

        public Transport(uint id, string name, double cost)
        {
            this.Id = id;
            this.Name = name;
            this.Cost = cost;
        }

        //public override string ToString()
        //{
        //    return $"[{Id}] {Name} ({Maintenance})";
        //}
    }

    public class Courier
    {
        public uint Id { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public uint TransportId { get; set; }

        public Courier(uint id, string firstName, string lastName, uint transportId)
        {
            Id = id;
            FirstName = firstName;
            LastName = lastName;
            TransportId = transportId;
        }

        //public override string ToString()
        //{
        //    return $"[{Id}] {FirstName} {LastName} on ({TransportId})";
        //}
    }

    public class Delivery
    {
        public uint Id { get; set; }
        public string Customer { get; set; }
        public double Distance { get; set; }
        public double Weight { get; set; }
        public double Price { get; set; }
        public DateTime Date { get; set; }
        public uint CourierId { get; set; }

        public Delivery(uint id, string customer, double distance, double weight, double price, DateTime date, uint courierId)
        {
            Id = id;
            Customer = customer;
            Distance = distance;
            Weight = weight;
            Price = price;
            Date = date;
            CourierId = courierId;
        }

        //public override string ToString()
        //{
        //    return $"[{Id}] to {Customer} in {Distance:#.##}km with {Weight:#.#}kg for ${Price:#.##} on {Date:d} by ({CourierId})";
        //}
    }

    public static class NameGenerator
    {
        // common last names
        static readonly List<string> cln = new List<string>
        {
            "Smith", "Nowak", "Melnyk", "Ivanov", "Garcia", "Wang", "Kim",
            "Da Silva", "Gonzalez", "Ahmed", "Muller", "Sato", "Sari",
            "Devi", "Ali"
        };

        // common first names
        static readonly List<string> cfn = new List<string>
        {
            "Mohamed", "Fatima", "Santiago", "José", "Sofía", "Olivia",
            "Gabrielle", "Ali", "An", "Cheng", "Aarav", "Minato", "Cai",
            "Jing", "Sara", "Antoni", "Jack", "Thomas", "Bohdan", "Nora",
            "Zuzanna", "Hanna", "Mia"
        };

        private static readonly Random random = new Random(5);

        public static string GetFirstName()
        {
            return cfn[random.Next(cfn.Count)];
        }

        public static string GetLastName()
        {
            return cln[random.Next(cln.Count)];
        }

        public static string GetFullName()
        {
            return GetFirstName() + " " + GetLastName();
        }
    }

    public class Database
    {
        public List<Transport> Transports { get; private set; }
        public List<Courier> Couriers { get; private set; }
        public List<Delivery> Deliveries { get; private set; }

        public static Database GetInstance()
        {
            Random rnd = new Random(7);

            Database db = new Database();

            db.Transports = new List<Transport>();
            db.Transports.Add(new Transport(1, "Bicycle", 0.1));
            db.Transports.Add(new Transport(2, "Scooter", 1));
            db.Transports.Add(new Transport(3, "Car", 3));
            db.Transports.Add(new Transport(4, "Cargo", 7));

            db.Couriers = new List<Courier>();
            for (int i = 1, n = rnd.Next(10, 20); i <= n; i++)
            {
                db.Couriers.Add(new Courier(
                    (uint)i,
                    NameGenerator.GetFirstName(),
                    NameGenerator.GetLastName(),
                    db.Transports[rnd.Next(db.Transports.Count)].Id));
            }

            db.Deliveries = new List<Delivery>();
            for (int i = 1, n = rnd.Next(100); i <= n; i++)
            {
                var dst = rnd.NextDouble() * 100;
                var cur = db.Couriers[rnd.Next(db.Couriers.Count - 2)];
                var price = (db.Transports[(int)cur.TransportId - 1].Cost + rnd.Next(5) / 10.0) * dst;
                db.Deliveries.Add(new Delivery(
                    (uint)i, NameGenerator.GetFullName(),
                    dst, rnd.NextDouble() * 50,
                    price,
                    DateTime.Today - TimeSpan.FromDays(rnd.Next(365)),
                    cur.Id
                    ));
            }

            return db;
        }
    }
}
