#include "Ladybugs.h"
#include "LadybugsConfParser.h"
//class LadybugsParser;

/**
 * Ladybugs ctor
 * 
 * @param loc
 */
Ladybugs::Ladybugs(Location *loc):
Creature(loc), life(6)
{} 

/**
 * Ladybugs dtor
 */
Ladybugs::~Ladybugs(){ }

/**
 * Creature is moved and updates its location
 * 
 * @param loc
 */
void Ladybugs::moveTo(Location *loc){
    Creature::moveTo(loc);
    loc->addLadybugs();
     if(currlocation->getNumberof_ladybugs()>1)
        Creature::setCreateNewCreature(true);
}

/**
 * ladybugs call its location hasAphids function 
 * to find out if it must fight
 * 
 * @return true if ladybug has another aphid in the same cell
 */
bool Ladybugs::mustFight() const{
    return getLocation().hasAphids();
}

/**
 * Updates the aphids' location information when an aphids come in to the cell.
 * After call the location has updated the number of aphids 
 * in this cell and set the boolean to true
 * 
 * @param loc the current location
 */
void Ladybugs::inNewLocation(Location &loc){
    loc.incNumberof_ladybugs();
    loc.setHasLadybugs(true);
}

/**
 * Updates the ladybugs' location information when an ladybug leave the cell.
 * After call the location has updated the number of ladybugs 
 * in this cell and set the boolean to true. Also ensure that if the 
 * number of ladybugs are equal to 1 the boolean which track if the aphids must 
 * create a new one is false
 * 
 * @param loc the old location
 */
void Ladybugs::leaveLocation(Location &loc){
    loc.decNumberof_ladybugs();
    loc.setHasLadybugs(false);
    if(loc.getNumberof_ladybugs()<=1)
        Creature::setCreateNewCreature(false);
}

/**
 * Ladybugs first check if the direction is changed and after 
 * they choose one out of three possibly positions of this direction
 * @return return the direction of the ladybugs
 */
Ladybugs::DIRECTION Ladybugs::getDirection() { 
    #include <cstdlib>
    
    int randmove = rand()%4;
    int wd = 0;
    switch(randmove){
        case 1:
            wd = rand()%3;
            if(wd == 0) 
                return WS;
            if(wd == 1)
                return W;
            if(wd == 2)
                return WN;
            break;
        case 3:
            wd = rand()%3;
            if(wd == 0) 
                return WS;
            if(wd == 1)
                return S;
            if(wd == 2)
                return NE;
            break;
        case 5:
            wd = rand()%3;
            if(wd == 0) 
                return SE;
            if(wd == 1)
                return E;
            if(wd == 2)
                return NE;
            break;
        case 7:
            wd = rand()%3;
            if(wd == 0) 
                return NE;
            if(wd == 1)
                return N;
            if(wd == 2)
                return WN;
            break;
        default:
            break;
    }   
}

/**
 * this just identify the type of a creature and 
 * return true if the creature is an Aphids. 
 * 
 * @param other
 * @return 
 */
bool Ladybugs::getType(Creature *other) const { 
    //use dynamic_cast
    Ladybugs *ladybugstype = NULL;
    ladybugstype = dynamic_cast<Ladybugs*>(other);
    if(ladybugstype) return true;
    return false;
}

/**
 * 
 * @param enemy
 * @return if the probabiliity to kill is bigger than the 
 * generated value this function return true otherwise false
 */
bool Ladybugs::combat(Creature *enemy) {
    float value_to_kill = rand()*RAND_MAX;
    if (this->PK > value_to_kill){
        enemy->getLocation().decNumberof_aphids();
        return true;
    }
    return false;
}

/**
 * Creature cant create other more than ones
 * 
 * @param loc the location of the new Aphids
 * @return a new pointer of Aphids 
 */
Creature* Ladybugs::procreation(Location *loc){
    Creature::setCreateNewCreature(false);
    return new Ladybugs(loc);
}

//extra feature
void Ladybugs::decreaseLife() {
    life--;
}

int Ladybugs::getLife() const{
    return life;
}

//probabilities getters/setters
float Ladybugs::getProbMove()  { return PM; }

float Ladybugs::getProbKill()  { return PK; }
 
float Ladybugs::getProbBirth()  { return PB; }

void Ladybugs::setProbMove(float value) {
    Ladybugs::PM = value;
}

void Ladybugs::setProbKill(float value) {
    Ladybugs::PK = value;
}

void Ladybugs::setProbBirth(float value) {
    Ladybugs::PB = value;
}

void Ladybugs::setProbDirection(float value) {
    Ladybugs::Pcd = value;
}

float Ladybugs::Pcd = 0.0; //LadybugsParser::getProbDirection(); //probability of direction
float Ladybugs::PM = 0.0; //LadybugsParser::getProbMove(); //probability of move
float Ladybugs::PK = 0.0; //LadybugsParser::getProbKill(); //probability of kill
float Ladybugs::PB = 0.0; //LadybugsParser::getProbBirth();