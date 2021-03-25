using System;
using Enemies;

namespace Defenders
{
    class FireMage : Mage
    {
        private double killChance;
        protected static readonly Random rng = new Random(1597);

        public FireMage(string name, int mana, int manaRegen, int spellPower, double killChance) : base(name, mana, manaRegen, spellPower)
        {
            this.killChance = killChance;
        }

        public override void Attack(Giant enemy)
        {
            if (rng.NextDouble() < killChance)
            {
                Console.WriteLine($"FireMage {name} instantly killed a giant {enemy.Name}");
                enemy.GetDmg(enemy.HP);
            }
            else
            {
                if (CanCastSpell())
                {
                    Console.WriteLine($"FireMage {name} attacked a giant {enemy.Name} and dealt {spellPower}dmg");
                    enemy.GetDmg(spellPower);
                    mana -= spellPower;
                }
            }
        }
        public override void Attack(Ogre enemy)
        {
            if (rng.NextDouble() < killChance)
            {
                Console.WriteLine($"FireMage {name} instantly killed an ogre {enemy.Name}");
                enemy.GetDmg(enemy.HP + enemy.Armor);
            }
            else
            {
                if (CanCastSpell())
                {
                    Console.WriteLine($"FireMage {name} attacked an ogre {enemy.Name} and dealt {spellPower}dmg");
                    enemy.GetDmg(spellPower);
                    mana -= spellPower;
                }
            }
        }
        public override void Attack(Rat enemy)
        {
            if (rng.NextDouble() < killChance)
            {
                Console.WriteLine($"FireMage {name} instantly killed a rat {enemy.Name}");
                enemy.GetDmg(enemy.HP);
            }
            else
            {
                if (CanCastSpell())
                {
                    Console.WriteLine($"FireMage {name} attacked a rat {enemy.Name} and dealt {spellPower}dmg");
                    enemy.GetDmg(spellPower);
                    mana -= spellPower;
                }
            }
        }
    }
}