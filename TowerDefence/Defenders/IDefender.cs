using Enemies;

namespace Defenders
{
    interface IDefender
    {
        public abstract void Attack(Giant enemy);
        public abstract void Attack(Ogre enemy);
        public abstract void Attack(Rat enemy);
    }
}