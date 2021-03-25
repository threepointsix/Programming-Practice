using System;
using Enemies;

namespace Defenders
{
    class RatCatcher : IDefender
    {
        protected readonly string name;
        private bool hasRat;

        public RatCatcher(string name)
        {
            this.name = name;
            hasRat=false;
        }

        public void Attack(Giant enemy)
        {
            Console.WriteLine($"RatCatcher {name} attacked a giant {enemy.Name} and nothing happened");
        }
        public void Attack(Ogre enemy)
        {
            if (hasRat)
            {
                Console.WriteLine($"RatCatcher {name} threw a rat on ogre {enemy.Name}!");
                enemy.GetDmg(enemy.HP);
                hasRat = false;
            }
            else
            {
                Console.WriteLine($"RatCatcher {name} met an ogre {enemy.Name}, but doesn't have a rat");
            }
        }
        public void Attack(Rat enemy)
        {
            if (hasRat)
            {
                Console.WriteLine($"RatCatcher {name} is currently holding a rat, so he can't attack a rat {enemy.Name}!");
            }
            else
            {
                Console.WriteLine($"RatCatcher {name} attacked a rat {enemy.Name}, killed him and took his body!");
                enemy.GetDmg(enemy.HP);
                hasRat = true;
            }
        }
    }
}