using System;
using Enemies;

namespace Defenders
{
    class Archer : Warrior
    {
        private int arrows;

        public Archer(string name, int strength, int arrows) : base(name, strength)
        {
            this.arrows = arrows;
        }
        public override void Attack(Giant enemy)
        {
            if (arrows > 0)
            {
                Console.WriteLine($"Archer {name} attacked a giant {enemy.Name} and dealt {strength}dmg!");
                enemy.GetDmg(strength);
                arrows--;
            }
            else
            {
                Console.WriteLine($"Archer {name} has no arrows left!");
            }
        }
        public override void Attack(Ogre enemy)
        {
            if (arrows > 0)
            {
                Console.WriteLine($"Archer {name} attacked an ogre {enemy.Name} and dealt {Math.Max(1, strength - enemy.Armor)}dmg!");
                enemy.GetDmg(strength);
                arrows -= 2;
            }
            else
            {
                Console.WriteLine($"Archer {name} has no arrows left!");
            }
        }
        public override void Attack(Rat enemy)
        {
            if (arrows > 0)
            {
                if (rng.NextDouble() < enemy.Speed / 100)
                {
                    Console.WriteLine($"Archer {name} missed attack on rat {enemy.Name}!");
                }
                else
                {
                    Console.WriteLine($"Archer {name} attacked a rat {enemy.Name} and dealt {strength}dmg!");
                    enemy.GetDmg(strength);
                    arrows--;
                }
            }
            else
            {
                Console.WriteLine($"Archer {name} has no arrows left!");
            }
        }
    }
}