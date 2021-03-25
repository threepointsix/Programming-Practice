using System;
using Defenders;

namespace Enemies
{
    class Giant : Enemy
    {

        public Giant(string name, int hp) : base(name, hp) {}
        public override void AttackedBy(IDefender defender)
        {
           //Console.WriteLine($"{defender.GetType()} {defender.Name} attacked {this.GetType()} {this.Name} ");
            defender.Attack(this);
        }
        public void GetDmg(int damage)
        {
            GetDamage(damage);
        }
    }
}