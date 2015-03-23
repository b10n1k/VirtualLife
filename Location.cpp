/**
 * Location class keeps data of the each cell. These data
 * indicates the cell itself and how many aphids and ladybugs 
 * are located in that.
 */
#include "Location.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setw;

#include <typeinfo>

//Default Ctor
Location::Location() {}

/**
 * Location Ctor 
 * 
 * @param x this integer indicates the x-axis in the World
 * @param y this integer indicates the y-axis in the World
 */
Location::Location(int x, int y):
pos_x(x), pos_y(y)
{
    numberof_aphids = 0;
    numberof_ladybugs = 0;
    has_aphids = false;
    has_ladybugs = false;
   
}

/**
 * Location copy Ctor 
 * @param loc
 */
Location::Location(const Location & loc):
	pos_x(loc.pos_x), pos_y(loc.pos_y), numberof_aphids(loc.numberof_aphids), numberof_ladybugs(loc.numberof_ladybugs)
{
}

/**
 * Location dtor
 */
Location::~Location(){}
    
//getters
int Location::getNumberof_aphids(void) const{
    return numberof_aphids;
}

int Location::getNumberof_ladybugs(void) const{
    return numberof_ladybugs;   
}

int Location::getPosX(void) const{
    return pos_x;
}

int Location::getPosY(void) const{
    return pos_y;   
}

void Location::setHasAphids(bool b){
    has_aphids = b;
    if(numberof_aphids==0) //very tricky
	has_aphids = false;
}

void Location::setHasLadybugs(bool b){
    has_aphids = b;
    if(numberof_ladybugs==0) //very tricky
	has_ladybugs = false;
}

/**
 * print_info prints the numbers of each creature 
 * that the cell contains. The red represent the Aphids 
 * and the green are the ladybugs
 */
void Location::print_info(void){
        
        cout << left << setw(3);
        if (numberof_aphids == 0) cout << "\033[1;31m" << CREATURE_ZERO << "\033[0m ";//"\033[1;31mbold red text\033[0m\n"
	else if(numberof_aphids >=9 ) cout << "\033[1;31m" << CREATURE_NINE << "\033[0m ";
	else cout << "\033[1;31m" << numberof_aphids << "\033[0m ";
	cout << right << setw(3);
        if (numberof_ladybugs == 0) cout << "\033[1;32m " << CREATURE_ZERO << "\033[0m ";
	else if(numberof_ladybugs >=9 ) cout << "\033[1;32m " << CREATURE_NINE << "\033[0m ";
	else cout << "\033[1;32m " << numberof_ladybugs <<  "\033[0m ";
}


bool Location::hasAphids() const{
	return has_aphids;
}

bool Location::hasLadybugs() const{
	return has_ladybugs;
}

void Location::addAphids(){
	numberof_aphids++; //it s not updated
	has_aphids = true;
        
}

void Location::addLadybugs(){
	numberof_ladybugs++;
	has_ladybugs = true;
}

bool Location::hasEnemy(Creature *creature){
    bool state = creature->mustFight();
    
    return state;
}

bool Location::hasFamily(Creature *creature){
    bool state = creature->mustBorn();
    
    return state;
}

void Location::incCreature(Creature *creature){
    creature->inNewLocation(*this);
}

/**
 * it is called by the world in the function move. 
 * it provides a connection between world and the creature
 * through the location of the creature
 *   
 * @param creature
 */
void Location::decCreature(Creature *creature){
    creature->leaveLocation(*this);
}

void Location::incNumberof_aphids(){ numberof_aphids++; }

void Location::decNumberof_aphids(){ numberof_aphids--;}

void Location::incNumberof_ladybugs(){ numberof_ladybugs++; }

void Location::decNumberof_ladybugs(){ numberof_ladybugs--; }

/**
 * returns the new Cell according to the direction. When it identifies 
 * what is the new direction it updates the x-axis and y-axis values to show to
 * the new Location.
 * 
 * @param toDirection the direction of the creature
 * @param rows the x-axis boundaries of the world
 * @param cols the y-axis boundaries of the world
 * @return the new location of the creature
 */
Location Location::setDirection(int toDirection, int rows, int cols){
    Location next = *this;
    switch(toDirection){
        case 1: //West
            if(next.pos_x > 0){ //remove magic numbers
                next.pos_x--;
            }
            else
            {
                next.pos_x++;
            }
            break;
        case 2: //WestNorth
            if(next.pos_x > 0 && next.pos_y > 0){ //remove magic numbers
                next.pos_x--;
                next.pos_y--;
            }
            else
            {
                next.pos_x++;
                next.pos_y--;
            }
            break;
        case 3: //North
            if(next.pos_y >0){ //remove magic numbers
                next.pos_y--;
            }
            else
            {
                next.pos_y++;
            }
            break;
        case 4: //NorthEast
            if(next.pos_x < rows && next.pos_y > 0){ //remove magic numbers
                next.pos_x++;
                next.pos_y--;
            }
            else
            {
                next.pos_x--;
                next.pos_y++;
            }
            break;
        case 5: //East
            if(next.pos_x < rows){ //remove magic numbers
                next.pos_x++;
            }
            else
            {
                next.pos_x--;
            }
            break;
        case 6: //SouthEast
            if(next.pos_x < rows && next.pos_y < cols){ //remove magic numbers
                next.pos_x++;
                next.pos_y++;
            }
            else
            {
                next.pos_x--;
                next.pos_y--;
            }
            break;
        case 7: //South
            if(next.pos_y < cols){ //remove magic numbers
                next.pos_y++;
            }
            else
            {
                next.pos_y--;
            }
            break;
        case 8: //WestSouth
            if(next.pos_x > 0 && next.pos_y < cols){ //remove magic numbers
                next.pos_x--;
                next.pos_y++;
            }
            else
            {
                next.pos_x++;
                next.pos_y--;
            }
            break;
    } //end switch
    return next;
}

/**
 * override equal operator to compare if two locations
 * are the same cell 
 * @param loc
 * @param other
 * @return true if loc == other else false
 */
bool operator== (Location &loc, Location &other){
    if((loc.pos_x == other.pos_x) && (loc.pos_y == other.pos_y))
        return true;
    return false;
}