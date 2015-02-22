/* 
 * File:   Creature.h
 * Author: b10n1k
 *
 * Created on February 21, 2015, 8:57 PM
 */

#ifndef CREATURE_H
#define	CREATURE_H

#include <string>
#include <iostream>

using std::string;

class Creature
{
private:
    static float PM; //probability of move
    static float PK; //probability of kill
    static float PB; //probability of procreation
    const string type;
public:
    //constructors
    Creature();
    ~Creature();
    
    void update();
    bool isAlive() const;
    void move();
};
#endif	/* CREATURE_H */

