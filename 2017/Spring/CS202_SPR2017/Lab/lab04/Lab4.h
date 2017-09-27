#ifndef LAB_3
#define LAB_3

#include <iostream>
using std::cout;
using std::endl;

class Monster
{
public:
  static int totalOfMonsters_; // Declares a static variable of the total of Monsters
  friend void heal(Monster Jim);

  //Constructor for monster
  Monster()
  {
    health_ = 100;
    ++totalOfMonsters_;
  }
  //Overloaded Constructor
  Monster(int newH)
  {
    health_ = newH;
    ++totalOfMonsters_;
  }
  //This gets the health of the Monster Object
  int getHitPoints()
  {
    return health_;
  }
  //This puts damage onto the Monster Object
  int dealDamage(int damageDone)
  {
    health_ -= damageDone;
    return health_;
  }
  //Kills Monster!
  void killMonster()
  {
    health_ = 0;
  }

  void heal(Monster &monsterName, int totalHeal)
  {
    monsterName.health_ += totalHeal;
  }

  //This returns the total of monsters
  static int getTotalOfMonsters()
  {
    return totalOfMonsters_;
  }

private:
  int health_;
};

#endif
