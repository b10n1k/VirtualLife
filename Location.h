/*                                                                                                                                                                                                                                            
 * File:   Location.h                                                                                                                                                                                                                         
 * Author: b10n1k                                                                                                                                                                                                                             
 *                                                                                                                                                                                                                                            
 * Created on February 21, 2015, 7:58 PM                                                                                                                                                                                                      
 */                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                              
#ifndef LOCATION_H                                                                                                                                                                                                                            
#define LOCATION_H                                                                                                                                                                                                                            
                            
#define CREATURE_ZERO '_'
#define CREATURE_NINE '~'
                                                                                                                                                                                                                  
//#include "Aphids.h"                                                                                                                                                                                                                           
//#include "Ladybugs.h"                                                                                                                                                                                                                         
#include <string>                                                                                                                                                                                                                             
using std::string;                                                                                                                                                                                                                            

#include "Creature.h"
class Creature;

#include <vector>
using std::vector;
                                    
class Aphids;
class Ladybugs;

class Location                                                                                                                                                                                                                                                                                                                                  
{                                                                                                                                                                                                                                              
public:                                                                                                                                                                                                                                       
    //setters                                                                                                                                                                                                                                 
 
    void incCreature(Creature *);
    void decCreature(Creature *);
    void incNumberof_aphids();
    void decNumberof_aphids();
    void incNumberof_ladybugs();
    void decNumberof_ladybugs();
    //getters                                                                                                                                                                                                                                 
    //string getLocationName(void) const;                                                                                                                                                                                                     
                                                                                                                                                                                                                                              
    int getNumberof_aphids(void) const;                                                                                                                                                                                                       
    int getNumberof_ladybugs(void) const;  
    
    int getPosX(void) const;                                                                                                                                                                                                                  
    int getPosY(void) const;                                                                                                                                                                                                                  
    bool hasAphids() const;                                                                                                                                                                                                                   
    bool hasLadybugs() const;                                                                                                                                                                                                                 
    void setHasAphids(bool);                                                                                                                                                                                                                  
    void setHasLadybugs(bool);                                                                                                                                                                                                                
    void addAphids();                                                                                                                                                                                                                   
    void addLadybugs();                                                                                                                                                                                                               
    //bool hasEnemy(Aphids *aphids);
    //bool hasEnemy(Ladybugs *ladybugs);
    bool hasEnemy(Creature *);
    //bool hasFamily(Aphids *aphids);
    //bool hasFamily(Ladybugs *ladybugs);
    bool hasFamily(Creature *);
    Creature &getEnemy(Creature*);
    Location setDirection(int, int, int);
    //constructors                                                                                                                                                                                                                            
    Location();                                                                                                                                                                                                                               
    Location(int, int);
    Location(int, int, Creature&);                                                                                                                                                                                                                   
    ~Location();                                                                                                                                                                                                                              
    Location(const Location & loc);                                                                                                                                                                                                           
                                                                                                                                                                                                                                              
    void print_info(void);
    
     friend bool operator== (Location &loc, Location &other);
private:                                                                                                                                                                                                                                      
    unsigned pos_x;                                                                                                                                                                                                                                
    unsigned pos_y;                                                                                                                                                                                                                                
    unsigned numberof_aphids;                                                                                                                                                                                                                      
    unsigned numberof_ladybugs;                                                                                                                                                                                                                    
    bool has_aphids;                                                                                                                                                                                                                          
    bool has_ladybugs;                                                                                                                                                                                                                        
                                                                                                                                                                                                                 
};                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                              
#endif  /* LOCATION_H */          