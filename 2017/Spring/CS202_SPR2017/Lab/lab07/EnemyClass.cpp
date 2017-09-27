//
//  main.cpp
//  Lab07
//
//  Created by Jim Samson on 3/23/17.
//  Copyright © 2017 Jim Samson. All rights reserved.
//

#include <iostream>
#include <memory.h>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;

//Base type: Enemy, used to make a monster
class Enemy
{
public:
    //Constructor. Used to make an enemy with 100 health. Health can be modified by calling a
    Enemy(int health = 100): health_(health)
    {
        cout << "Constructing Enemy." << endl;

        //Hah. No one will be too powerful...
        if(health > 200 || health < 0)
        {
            health_ = 100;
        }
    }

    //Destructor
    ~Enemy()
    {
        cout << "Destructing Enemy Class (This will always destruct last)" << endl;
    }
    void virtual describe() const =0;

    void setHealth(int health)
    {
        health_ = health;
    }
    int getHealth()
    {
        return health_;
    }
protected:
    int health_;
};

//Derived class of Enemy. Type: Wolf, very strong, but not capable of flying.
class Wolf : public Enemy
{
public:
    Wolf(int health = 120, int speed = 32) : Enemy(health), speed_(speed)
    {
        cout << "Constructing Wolf Class" << endl;

        if(speed < 0 || speed > 100)
        {
            speed_ = 32;
        }
    }

    ~Wolf()
    {
        cout << "Destructing Wolf Class (This will destruct first)" << endl;
    }

    void virtual describe() const override
    {
        cout << "Wolf speed is " << speed_ << endl;
        cout << "Wolf health is " << health_ << endl;
    }

    void setSpeed(int speed)
    {
        speed_ = speed;
    }
    private:
        int speed_;
};

//Derived class of Enemy. Type: Hawk, strong, but not strong as the Wolf.
class Hawk : public Enemy
{
public:
    Hawk(int health = 70, int speed = 59) : Enemy(health), speed_(speed)
    {
        cout << "Constructing Hawk Class" << endl;

        if(speed > 0 || speed < 100)
        {
            speed = 59;
        }
    }

    ~Hawk()
    {
        cout << "Destructing Hawk Class (This will destruct first)" << endl;
    }

    void virtual describe() const override
    {
        cout << "Hawk health is " << health_ << endl;
        cout << "Hawk speed is " << speed_ << endl;
    }

    void setSpeed(int speed)
    {
        speed_ = speed;
    }
private:
    int speed_;
};

int main()
{
    //Object, James (Wolf, enemy)
    cout << "-Constructing James: " << endl;
    Wolf James(100);
    James.describe();
    cout << endl;

    //Object, John (Hawk, enemy) s
    cout << "-Constructing John: " << endl;
    unique_ptr<Hawk> John = make_unique<Hawk>(20);
    John->describe();
    cout << endl;

    cout << "Now destructing both objects:" << endl;
    return 0;
}
