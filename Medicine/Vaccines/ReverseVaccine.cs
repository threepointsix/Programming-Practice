using System;
using System.Collections.Generic;
using System.Text;
using Task3.Subjects;

namespace Task3.Vaccines
{
    class ReverseVaccine : IVaccine
    {
        public string Immunity => "ACTGAGACAT";

        public double DeathRate => 0.05f;
        private int DeathRateMultiplier = 0;

        private Random randomElement = new Random(0);
        public override string ToString()
        {
            return "ReverseVaccine";
        }

        public void Vaccinate(Dog dog)
        {
            char[] immArr = Immunity.ToCharArray();
            Array.Reverse(immArr);

            dog.Immunity = new string(immArr);
        }

        public void Vaccinate(Cat cat)
        {
            cat.Alive = false;
            Console.WriteLine($"Cat {cat.ID} has died from {ToString()}");
        }

        public void Vaccinate(Pig pig)
        {
            char[] immArr = Immunity.ToCharArray();
            Array.Reverse(immArr);
            string pigimmune = Immunity + new string(immArr);
            pig.Immunity = pigimmune;

            if (DeathRateMultiplier * DeathRate > randomElement.NextDouble())
            {
                pig.Alive = false;
                Console.WriteLine($"Pig {pig.ID} has died from {ToString()}");
            }
            DeathRateMultiplier++;
        }
    }
}
