#include "World.h"

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setfill;
using std::setw;

#include <cstdlib>

//using std::setw;
/**
 * Create a 2d array and initialize attributes with
 * the values. The values are come from config file.
 * 
 * @param width how many places for x-axis
 * @param height how many places for y-axis
 * @param naphids total num of aphids
 * @param nlbugs total num of ladybugs
 */
//World::World(const int rw, const int cl, const int naphids, const int nlbugs)
//:w_rows(rw), w_cols(cl), num_aphids(naphids), num_ladybugs(nlbugs)
World::World(WorldParser &wparser): 
w_rows(wparser.getRows()), w_cols(wparser.getColumns()), num_aphids(wparser.getNumofaphids()), num_ladybugs(wparser.getNumofladybugs())
{
    //set a 2d array formed by Locations. Location keeps the location
    //and the creatures' info
    world=new Location*[w_rows];

 	for(unsigned rp=0;rp<w_rows;rp++){
	 	world[rp] = new Location[w_cols];
 	}    
    
    for(unsigned x_axis=0;x_axis<w_rows;x_axis++){
        for(int y_axis=0;y_axis<w_cols;y_axis++){
            world[x_axis][y_axis]= Location(x_axis, y_axis);
            //cout << world[x_axis][y_axis].print_info();
            
        }
        cout << endl;
    }
    
   //create creature
 	
 	for(unsigned aphidsIndex=0; aphidsIndex < wparser.aphpositions.size() ;aphidsIndex++){
	    int cellx = wparser.aphpositions[aphidsIndex].getPosX();
	    int celly = wparser.aphpositions[aphidsIndex].getPosY();
	    
	    Location *loc = getCell(cellx, celly);
            Aphids *creature_tmp = new Aphids(loc); //(cellx,celly);
            creatures.push_back(creature_tmp);
	    loc->addAphids();
	    //creatures.push_back(creature_tmp);
	    
    }
    
    for(unsigned ladybugsIndex=0; ladybugsIndex < wparser.ladypositions.size() ;ladybugsIndex++){
	    int cellx = wparser.ladypositions[ladybugsIndex].getPosX();
	    int celly = wparser.ladypositions[ladybugsIndex].getPosY();
	   
	    Location *loc = getCell(cellx, celly);
            Ladybugs *creature_tmp = new Ladybugs(loc); //(cellx,celly);
            creatures.push_back(creature_tmp);
	    loc->addLadybugs();
	    //creatures.push_back(creature_tmp);
    }
    
    //locate each creature
    
}

World::~World(){
    for(unsigned i; i<w_rows;i++){
        //for(int j; j<w_cols;j++){
            delete world[i];//[j];
        //}
    }
}

void World::display_world() const{
	cout << "_____________________________________________________________" << endl;
	
    for(unsigned x_axis=0;x_axis<w_rows ;x_axis++){    
        for(int y_axis=0;y_axis<w_cols;y_axis++){
	        cout << "|";
            world[x_axis][y_axis].print_info(); 
        }
        cout << "|" << endl;
        cout << "_____________________________________________________________" << endl;
        
    }
   // cout << "_______________________________________________________________" << endl;
}

void World::update(Creature &creature){
	double pr_to_move = (double)rand()/(double)RAND_MAX;
	//cout<< pr_to_move <<endl ;
      //  int dir = creature.getDirection();
    if(creature.getProbMove() > pr_to_move)
    	//creature.moveTo(dir);
        cout<< pr_to_move <<endl ;
    	else 
    	cout<< creature.getProbMove() << endl;
}

void World::create(Location *loc, Creature *alive){///////////////////////////
    Creature* baby = alive->procreation(loc);
    creatures.push_back(baby);
    //dynamic_cast
    Aphids *aphidstype = NULL;
    aphidstype = dynamic_cast<Aphids*>(baby);
    if(aphidstype){
        loc->addAphids();
    }
    else{
        loc->addLadybugs();
    }
}

void World::move(Creature *&alive, int moveto){
    Location &curr = alive->getLocation(); //is it the same locatio in the world
    
    
    curr.decCreature(alive); 
    Location next = curr.setDirection(moveto, w_rows, w_cols); //included boundaries
    
    alive->moveTo(getCell(next.getPosX(),next.getPosY()));
    //TODOremove from vector
    //next.incCreature(alive); //Problem here!
    //insert to new location
}

int World::getW_rows() const{ return w_rows; }

int World::getW_cols() const{ return w_cols; }

int World::getNum_aphids() const{ return num_aphids; }

int World::getNum_ladybugs() const{ return num_ladybugs; }

//Creature* World::getCreature_list() const{}

Creature World::getCreature(int index) const{}

/*
void insertCreature(Creature &creature){
	int x = creature.getPosition_x();
	int y = creature.getPosition_y();	
}
*/
vector<Creature*> &World::getCreatures() {
	return creatures;
}

Location *World::getCell(int x, int y) const{
	return &world[x][y];
}
