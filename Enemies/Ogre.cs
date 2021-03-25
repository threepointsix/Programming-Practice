using System;
using Defenders;

namespace Enemies
{
    class Ogre : Enemy
    {
        public int Armor { get; }

        public Ogre(string name, int hp, int armor) : base(name, hp)
        {
            Armor = armor;
        }
        public override void AttackedBy(IDefender defender)
        {
            defender.Attack(this);
        }
        public void GetDmg(int damage)
        {
            GetDamage(Math.Max(1, damage - Armor));
        }
    }
}