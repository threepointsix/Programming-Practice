using System;
using Enemies;

namespace Defenders
{
    class Mage : IDefender
    {
        protected readonly string name;
        protected int mana;
        protected readonly int manaRegen;
        protected readonly int spellPower;

        public Mage(string name, int mana, int manaRegen, int spellPower)
        {
            this.name = name;
            this.mana = mana;
            this.manaRegen = manaRegen;
            this.spellPower = spellPower;
        }

        protected bool CanCastSpell()
        {
            if (mana >= spellPower)
            {
                mana -= spellPower;
                return true;
            }

            Console.WriteLine($"Mage {name} is recharging mana");
            RechargeMana();
            return false;
        }

        private void RechargeMana()
        {
            mana += manaRegen;
        }

        public virtual void Attack(Giant enemy)
        {
            if (CanCastSpell())
            {
                Console.WriteLine($"Mage {name} attacked a giant {enemy.Name} and dealt {spellPower}dmg");
                enemy.GetDmg(spellPower);
                mana -= spellPower;
            }
        }
        public virtual void Attack(Ogre enemy)
        {
            if (CanCastSpell())
            {
                Console.WriteLine($"Mage {name} attacked an ogre {enemy.Name} and dealt {spellPower}dmg");
                enemy.GetDmg(spellPower);
                mana -= spellPower;
            }
        }
        public virtual void Attack(Rat enemy)
        {
            if (CanCastSpell())
            {
                Console.WriteLine($"Mage attacked a rat {enemy.Name} and dealt {spellPower}dmg");
                enemy.GetDmg(spellPower);
                mana -= spellPower;
            }
        }
    }
}