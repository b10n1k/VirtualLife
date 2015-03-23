#include "Creature.h"
#include "Location.h"
#include "World.h"
#include <cstdlib>

using std::cout;
using std::endl;

/**
 * Creature ctor
 * @param loc the location in the cell which the creature is located
 */
Creature::Creature(Location *loc) 
{
    currlocation=loc;
    size_of_killed = 0;
    creature_in_the_same_location = false;
    
}

/**
 * Creature dtor
 */
Creature::~Creature(){ delete currlocation; }

/**
 * Creature is moved and updates its location
 * @param loc
 */
void Creature::moveTo(Location *loc){
    currlocation = loc;
}

/**
 * returns a vector with its kills
 * NOTE: this has not been implemented
 * 
 * @return a vector of killed creatures
 */
vector<Creature> Creature::reportKills(){
    return killed;    
}

/**
 * 
 * @return if this return true then it means that
 * the cell which the creature exists has another 
 * else of the same type and should create a new
 * creature
 */
bool Creature::mustBorn(){
    return creature_in_the_same_location;
}

/**
 * setter for the member which defines if creature cell 
 * contains more than two creature of the same type
 * 
 * @param b
 */
void Creature::setCreateNewCreature(bool b){
    creature_in_the_same_location=b;
}

/**
 * 
 * @return a pointer to the location in the world
 */
Location& Creature::getLocation() const{
    return *currlocation;
}

bool Creature::mustFight() const{}

void inNewLocation(Location &loc){}

void leaveLocation(Location &loc){}

/**
 * 
 * @return return the direction of the creature
 */
Creature::DIRECTION Creature::getDirection() {

    int direction = rand()%8;
    enum DIRECTION go;
    switch(direction){
        case 1:
            go = W;
            break;
        case 2:
            go = WN;
            break;
        case 3:
            go = N;
            break;
        case 4:
            go = NE;
            break;
        case 5:
            go = E;
            break;
        case 6:
            go = SE;
            break;
        case 7:
            go = S;
            break;
        case 8:
            go = WS;
            break;
        default:
            
            break;
    }
    return go;
}

Creature* Creature::procreation(Location *loc){}

//functions that are used by inherited classes
bool Creature::getType(Creature *) const{ }
bool Creature::combat(Creature *enemy){}
void Creature::leaveLocation(Location &loc){}
void Creature::inNewLocation(Location &loc){}
 
float Creature::getProbMove()  {}
float Creature::getProbKill()  {}
float Creature::getProbBirth()  {}
void Creature::setProbMove(float) {}
void Creature::setProbKill(float) {} 
void Creature::setProbBirth(float) {}

//extra feature
void Creature::decreaseLife() {}

int Creature::getLife() const{}