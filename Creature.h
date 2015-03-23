/* 
 * File:   Creature.h
 * Author: b10n1k
 *
 * Created on February 21, 2015, 8:57 PM
 */

#ifndef CREATURE_H
#define	CREATURE_H

#include "Location.h"


#include <string>
#include <iostream>

using std::string;

class Location;

#include <vector>
using std::vector;
class World;

class Creature
{
private:
    
    vector<Creature> killed; //track kills
    int size_of_killed; //the size of killed array
    bool creature_in_the_same_location;
   
protected:
    Location *currlocation; //store the creature's location
    
public:
     enum DIRECTION{W=1,WN,N,NE,E,SE,S,WS};
    
    Creature(Location *);
    virtual ~Creature();

    virtual void moveTo(Location *);
    virtual vector<Creature> reportKills();
    virtual bool mustBorn();
    virtual void setCreateNewCreature(bool);
    
    virtual Location &getLocation() const;
    virtual bool mustFight() const;
    virtual void inNewLocation(Location &);
    virtual void leaveLocation(Location &);
    
    
    virtual DIRECTION getDirection() ;
    virtual Creature* procreation(Location *);
    virtual bool combat(Creature *) ;
    
    //Not really used by Creature class
    virtual bool getType(Creature *) const;
    static float getProbMove()  ;
    static float getProbKill()  ;
    static float getProbBirth()  ;
    static void setProbMove(float) ;
    static void setProbKill(float) ; 
    static void setProbBirth(float) ;

    //extra
    virtual void decreaseLife();
    virtual int getLife() const;
               
};
#endif	/* CREATURE_H */


