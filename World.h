/* 
 * File:   World.h
 * Author: b10n1k
 *
 * Created on February 21, 2015, 7:58 PM
 */

#ifndef WORLD_H
#define	WORLD_H

#include "Creature.h"
#include "Aphids.h"
#include "Ladybugs.h"
#include "Location.h"
#include <vector>
using std::vector;

#include "WorldConfParser.h"
class WorldParser;

class World
{
public:
    World(WorldParser&);
    
    ~World();
    
    void display_world() const;
    void update(Creature &);
    void create(Location*, Creature *);
    void move(Creature *&, int);
    
    //getter&setter
    int getW_rows() const;
    int getW_cols() const;
    int getNum_aphids() const;
    int getNum_ladybugs() const;
    Creature getCreature(int) const;
    vector<Creature*> &getCreatures() ;
    Location *getCell(int, int) const;
    void insertCreature(Creature &);
    
private:  
    const int w_rows;
    const int w_cols;
    Location **world;
    vector<Creature*> creatures;
    unsigned num_aphids;
    unsigned num_ladybugs;
    
};
#endif	/* WORLD_H */