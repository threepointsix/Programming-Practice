using System;
using Enemies;

namespace Defenders
{
    class Warrior : IDefender
    {
        protected readonly string name;
        protected readonly int strength;
        protected static readonly Random rng = new Random(1597);
        
        public Warrior(string name, int strength)
        {
            this.name = name;
            this.strength = strength;
        }

        public virtual void Attack(Giant enemy)
        {
            Console.WriteLine($"Warrior {name} attacked a giant {enemy.Name} and dealt {strength}dmg!");
            enemy.GetDmg(strength);
        }
        public virtual void Attack(Ogre enemy)
        {
            Console.WriteLine($"Warrior {name} attacked an ogre {enemy.Name} and dealt {Math.Max(1, strength - enemy.Armor)}dmg!");
            enemy.GetDmg(strength);
        }
        public virtual void Attack(Rat enemy)
        {
            if (rng.NextDouble() < enemy.Speed / 100)
            {
                Console.WriteLine($"Warrior {name} missed attack on rat {enemy.Name}!");
            }
            else
            {
                Console.WriteLine($"Warrior {name} attacked a rat {enemy.Name} and dealt {strength}dmg!");
                enemy.GetDmg(strength);
            }
        }


    }
}