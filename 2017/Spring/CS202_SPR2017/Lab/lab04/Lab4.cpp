//Jim Samson
//Febraury 9, 2017
//Computer Science
//This lab is about making monster classes, using the classes and what it does
#include "Lab4.h"

//Like a prototype, this is declared up here
int Monster::totalOfMonsters_ = 0;

int main()
{
  cout << "There are " << Monster::getTotalOfMonsters() << " Monsters." << endl;
  //This makes a monster
  Monster Mike;
  Monster Jim;
  Monster Cameron;
  Monster Professor(2000);

  //This gets the total of monsters and cout it
  cout << "Now there are " << Monster::totalOfMonsters_ << " Monsters."<< endl;
  cout << "Again, a total of " << Monster::getTotalOfMonsters() << " Monsters."<< endl;

  //Mike's health, damage, and new health
  cout << endl;
  cout << "Mike's Health: " << Mike.getHitPoints() << endl;
  cout << "Damage!: " << Mike.dealDamage(50) << endl;
  cout << "Mike's Health: " << Mike.getHitPoints() << endl;
  cout << endl;

  Cameron = Mike; //Copies Mike's object

  //Jim's health, damage, and new health
  cout << "Jim's Health: " << Jim.getHitPoints() << endl;
  cout << "Jim fights a dragon with his bare hands" << endl;
  Jim.killMonster(); //Cool feature. It kills the monster!
  cout << "Jim's Health: " << Jim.getHitPoints() << endl;
  cout << "Revive!" << endl;
  Jim.heal(Jim,100);
  cout << "Jim's Health: " << Jim.getHitPoints() << endl;
  cout << endl;

  //Cameron's health, damage, and new heatlh
  cout << "Cameron's Health: " << Cameron.getHitPoints() << endl;
  cout << "Cameron fights with Jim" << endl;
  cout << "Damage!: " << Cameron.dealDamage(49) << endl;
  cout << "Cameron's Health: " << Cameron.getHitPoints() << endl;
  cout << "Cameron is crippled." << endl;
  cout << endl;

  cout << "Professor's Health: " << Professor.getHitPoints() << endl;
  cout << "Haha you cannot defeat me!!" << endl;
  cout << "*Jim does homework*" << endl;
  cout << "Professor takes damage!" << endl;
  cout << "Damage!: " << Professor.dealDamage(100) << endl;
  cout << "Professor's Health:" << Professor.getHitPoints() << endl;
  cout << endl;

  return 0;
}
