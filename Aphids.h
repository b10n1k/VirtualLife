/* 
 * File:   Aphids.h
 * Author: b10n1k
 *
 * Created on February 25, 2015, 1:58 AM
 */

#ifndef APHIDS_H
#define	APHIDS_H

#include "Creature.h"
#include "Location.h"
//class Creature;

class Aphids : public Creature
{
	
    public :
        Aphids(Location *);
        ~Aphids();
        
        virtual bool getType(Creature *) const;
        virtual void moveTo(Location *);
        
        virtual bool mustFight() const;
        virtual void leaveLocation(Location &);
        virtual void inNewLocation(Location &);
        virtual bool combat(Creature *) ;
        virtual Creature* procreation(Location *);
        //probabilities
        static float getProbMove() ;
        static float getProbKill() ; 
	static float getProbBirth() ;
        static void setProbMove(float) ;
        static void setProbKill(float) ; 
	static void setProbBirth(float) ;
        static void setProbKillAdditional(float);
        //extra feature
        void decreaseLife();
        int getLife() const;
        
    private:
        static float PKadditional; //probability kill in helping
        static float PM; //probability of move
    	static float PK; //probability of kill
    	static float PB; //probability of procreation
        //extra feature
        int life;
};

#endif	/* APHIDS_H */

