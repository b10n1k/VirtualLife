

#include "Aphids.h"
#include "AphidsConfParser.h"
//class AphidsParser;

/**
 * Aphids ctor
 * 
 * @param loc
 */
Aphids::Aphids(Location *loc) :
Creature(loc), life(4)
{}

/**
 * Aphids dtor
 */
Aphids::~Aphids(){ }

/**
 * Creature is moved and updates its location
 * 
 * @param loc
 */
void Aphids::moveTo(Location *loc){
    Creature::moveTo(loc);
    currlocation->addAphids(); //setNumberof_aphids
     if(currlocation->getNumberof_aphids()>1)
        Creature::setCreateNewCreature(true);
}

/**
 * alphids call its location hasLadybugs function 
 * to find out if it must fight
 * 
 * @return true if aphid has another ladybug in the same cell
 */
bool Aphids::mustFight() const{
    return getLocation().hasLadybugs();
}

/**
 * Updates the aphids' location information when an aphids come in to the cell.
 * After call the location has updated the number of aphids 
 * in this cell and set the boolean to true
 * 
 * @param loc the current location
 */
void Aphids::inNewLocation(Location &loc){
    loc.incNumberof_aphids();
    loc.setHasAphids(true);
    
}

/**
 * Updates the aphids' location information when an aphids leave the cell.
 * After call the location has updated the number of aphids 
 * in this cell and set the boolean to true. Also ensure that if the 
 * number of aphids are equal to 1 the boolean which track if the aphids must 
 * create a new one is false
 * 
 * @param loc the old location
 */
void Aphids::leaveLocation(Location &loc){
    loc.decNumberof_aphids();
    loc.setHasLadybugs(false);
     if(loc.getNumberof_aphids()<=1)
        Creature::setCreateNewCreature(false);
}

/**
 * this just identify the type of a creature and 
 * return true if the creature is an Aphids. 
 * 
 * @param other
 * @return 
 */
bool Aphids::getType(Creature *other) const { 
    //use dynamic_cast
    Aphids *aphidstype = NULL;
    aphidstype = dynamic_cast<Aphids*>(other);
    if(aphidstype) return true;
    return false;
}

/**
 * 
 * @param enemy
 * @return if the probabiliity to kill is bigger than the 
 * generated value this function return true otherwise false
 */
bool Aphids::combat(Creature *enemy) { //?????????????
    float value_to_kill = rand()*RAND_MAX;
    if (this->PK > value_to_kill){
        enemy->getLocation().decNumberof_ladybugs();
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
Creature* Aphids::procreation(Location *loc){
    Creature::setCreateNewCreature(false);
    return new Aphids(loc);
}

//extra feature
void Aphids::decreaseLife() {
    life--;
}

int Aphids::getLife() const{
    return life;
}

//probabilities getters/setters
float Aphids::getProbMove()  { return PM; }

float Aphids::getProbKill()  { return PK; }
 
float Aphids::getProbBirth()  { return PB; }

void Aphids::setProbMove(float value) {
    Aphids::PM = value;
}

void Aphids::setProbKill(float value) {
    Aphids::PK = value;
}

void Aphids::setProbBirth(float value) {
    Aphids::PB = value;
}

void Aphids::setProbKillAdditional(float value) {
    Aphids::PKadditional = value;
}

float Aphids::PM = 0.0; //AphidsParser::getProbMove(); 
float Aphids::PK = 0.0;//AphidsParser::getProbKill();
float Aphids::PB = 0.0; //AphidsParser::getProbBirth();
float Aphids::PKadditional = 0.0; //AphidsParser::getProbAdditional();