using System;
using System.Collections.Generic;
using System.Text;
using Task3.Subjects;

namespace Task3.Vaccines
{
    class AvadaVaccine : IVaccine
    {
        public string Immunity => "ACTAGAACTAGGAGACCA";

        public double DeathRate => 0.2f;

        private Random randomElement = new Random(0);

        public override string ToString()
        {
            return "AvadaVaccine";
        }

        public void Vaccinate(Dog dog)
        {
            dog.Immunity = Immunity;
        }

        public void Vaccinate(Cat cat)
        {
            string catimmune = Immunity.Substring(3);
            cat.Immunity = catimmune;

            if (DeathRate > randomElement.NextDouble())
            {
                cat.Alive = false;
                Console.WriteLine($"Cat {cat.ID} has died from {ToString()}!");
            }
        }

        public void Vaccinate(Pig pig)
        {
            pig.Alive = false;
            Console.WriteLine($"Pig {pig.ID} has died from {ToString()}!");
        }
    }
}
