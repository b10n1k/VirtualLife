/* 
 * File:   Ladybugs.h
 * Author: b10n1k
 *
 * Created on February 25, 2015, 1:59 AM
 */

#ifndef LADYBUGS_H
#define	LADYBUGS_H

#include "Creature.h"
#include "Location.h"

class Ladybugs: public Creature
{
    public :
        Ladybugs(Location *);
        ~Ladybugs();

        void update();
        virtual bool getType(Creature *) const;
        virtual void moveTo(Location *);
        
        virtual DIRECTION getDirection() ;
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
        static void setProbDirection(float);
        //extra feature
        void decreaseLife();
        int getLife() const;
        
    private:
       static float Pcd; //probability of direction
       static float PM; //probability of move
       static float PK; //probability of kill
       static float PB; //probability of procreation
       //extra feature
       int life;
};


#endif	/* LADYBUGS_H */

