#include "AphidsConfParser.h"
#include "LadybugsConfParser.h"
#include "WorldConfParser.h"
#include "World.h"
#include "Aphids.h"
#include "Ladybugs.h"

#include <vector>
using std::vector;

#include "Location.h"

#include <iostream>
#include <unistd.h>

int main(){

    /**
     * create and run parsers. They are going to keep the
     * config data for each class. 
     */
    WorldParser wparser("aphidsAndLadybugs.conf");
	//home/b10n1k/workspace/VirtualLife/VirtualLife/
    AphidsParser aparser("aphids.conf");
    LadybugsParser lparser("ladybugs.conf");
    
    //initialize the Aphids' static member for its probabilities
    Aphids::setProbMove(aparser.getProbMove());
    Aphids::setProbKill(aparser.getProbKill()) ;
    Aphids::setProbBirth(aparser.getProbBirth()) ;
    Aphids::setProbKillAdditional(aparser.getProbAdditional());
    
    //initialize the Ladybugs' static member for its probabilities
    Ladybugs::setProbMove(lparser.getProbMove());
    Ladybugs::setProbKill(lparser.getProbKill()) ;
    Ladybugs::setProbBirth(lparser.getProbBirth()) ;
    Ladybugs::setProbDirection(lparser.getProbDirection());
    
    World game(wparser);
    vector<Creature*> alive = game.getCreatures();		  
	
    while(game.getNum_aphids() != 0 || game.getNum_ladybugs() != 0){ //run until all creatures will be disappeared
		
		for(int ind=0; ind<alive.size(); ind++){
                    
                    //creatures are moved to new location
                    double pr_to_move = (double)rand()/(double)RAND_MAX;
                    if(alive[ind]->getProbMove() > pr_to_move){
                        int newdirection = alive[ind]->getDirection();
                        
                        game.move(alive[ind], newdirection);
                    }
                 
                    //start fight if the location has an enemy 
                    if(alive[ind]->mustFight()){
                        
                        //find how is the enemy                       
                        for(int others=0;others<alive.size();others++){
                            Location enemy_loc = alive[others]->getLocation();
                            
                            if(alive[ind]->getType(alive[others]) ) 
                                if(enemy_loc == alive[ind]->getLocation()){
                                    bool kill = alive[ind]->combat(alive[others]);
                            
                                if(kill){
                                    //call world function kill - MUSTDO
                                    
                                        alive[others]->getLocation().decCreature(alive[others]);
                                        //delete alive[others];
                                        alive.erase(alive.begin()+others);
                                    
                                }
                            }
                        }
                        
                    } //end of fight
                    
                    //Need to create new Creature
                    if(alive[ind]->getLocation().hasFamily(alive[ind])){
                        game.create(&alive[ind]->getLocation(), alive[ind]);
                    }
                    //extra feature
                    alive[ind]->decreaseLife();
                    if(alive[ind]->getLife() == 0){
                        alive[ind]->getLocation().decCreature(alive[ind]);
                        //delete alive[ind];
                        alive.erase(alive.begin()+ind);
                    }
                    
                    //game.display_world();
                    //sleep(1);
                    
                    
		} //end of precreation
		//uncomment the lines below to have output in each turn(more fast!!)
                game.display_world();
                sleep(1);
                
                
	} //while end    
    
}