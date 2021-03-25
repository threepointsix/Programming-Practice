using System;
using Defenders;

namespace Enemies
{
    class Rat : Enemy
    {
        public int Speed { get; private set; }

        public Rat(string name, int hp, int speed) : base(name, hp)
        {
            Speed = speed;
        }
        public override void AttackedBy(IDefender defender)
        {
            defender.Attack(this);
        }
        public void GetDmg(int damage)
        {
            GetDamage(damage);
            Speed += damage;
        }
    }
}