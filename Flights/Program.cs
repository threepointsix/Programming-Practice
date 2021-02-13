using System;
using System.Linq;

namespace Lab14
{
    class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine();
            var db = Database.GetInstance();


            Console.WriteLine("****** Task 1 ******");

            // TODO: Write a query to find all deliveries shorter than 15km
            // and output the full name of the courier, distance and the transport used.

            // query and output here...

            var query1 = from delivery in db.Deliveries
                         join courier in db.Couriers on delivery.CourierId equals courier.Id
                         join transport in db.Transports on courier.TransportId equals transport.Id
                         where delivery.Distance < 15
                         orderby courier.FirstName
                         select new { courier.FirstName, courier.LastName, delivery.Distance, transport.Name };

            foreach (var q in query1)
            {
                Console.WriteLine($"{q.FirstName} {q.LastName} made {Math.Round(q.Distance, 2)}km with {q.Name}");
            }

            Console.WriteLine("****** Task 2 ******");

            // TODO: Calculate profit for every delivery made within last 30 days
            // and output it in descending order along with the courier full name and the delivery date.
            // Requirement: do not calculate the same thing twice (a let clause may be used)

            // query and output here...

            var query2 = from delivery in db.Deliveries
                         join courier in db.Couriers on delivery.CourierId equals courier.Id
                         join transport in db.Transports on courier.TransportId equals transport.Id
                         let profit = delivery.Price - (transport.Cost * delivery.Distance)
                         where delivery.Date.Year == DateTime.Today.Year
                         where DateTime.Today.Month - delivery.Date.Month <= 1
                         where delivery.Date.Day - DateTime.Today.Day <= 30
                         orderby profit descending
                         select new {profit, courier.FirstName, courier.LastName, delivery.Date};

            foreach (var q in query2)
            {
                Console.WriteLine($"{q.FirstName} {q.LastName} made {Math.Round(q.profit, 2)} on {q.Date.Year}-{q.Date.Month, 2}-{q.Date.Day}");
            }


            Console.WriteLine();
            Console.WriteLine("****** Task 3 ******");

            // TODO: Calculate total weight carried by bikes for the entire period and write it out.

            // query and output here...


            Console.WriteLine();
            Console.WriteLine("****** Task 4 ******");

            // TODO: Find 3 couriers working for the longest period of time,
            // output their full names and a date of the first delivery.
            // Print them ordered ascending by dates.

            // query and output here...


            Console.WriteLine();
            Console.WriteLine("****** Task 5 ******");

            // TODO: Output full names of all couriers that haven't made any delivery yet.
            // Order the output alafabetically basing on the last name and then the first name.
            // Hint: join...into clause, Count() method

            // query and output here...


            Console.WriteLine();
            Console.WriteLine("****** Task 6 ******");

            // TODO: Calculate and output for every transport its maximal profit made in a single day.
            // Delivery profit is equal to distance multiplied by cost per km substracted from delivery price.

            // query and output here...

            Console.WriteLine();
        }
    }
}
