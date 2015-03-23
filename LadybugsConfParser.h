/* 
 * File:   LadybugsConfParser.h
 * Author: b10n1k
 *
 * Created on February 27, 2015, 3:47 AM
 */

#ifndef LADYBUGSCONFPARSER_H
#define	LADYBUGSCONFPARSER_H

#include <cstdlib>
#include <string>
#include <fstream>
using std::ifstream;

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::ios;

#include <vector>
using std::vector;

//#include "Ladybugs.h"

class LadybugsParser
{
public:
    LadybugsParser(const char*);
    
    void parse(std::ifstream&);
    float getProbMove() ;
    float getProbDirection() ;
    float getProbKill() ;
    float getProbBirth() ;
    
private:
    ifstream ladybugs_data;
    float pm; //probability move
    float pcd; //probability kill
    float pla; //addditional probability kill in the cell
    float pb; //probability birth
};

#endif	/* LADYBUGSCONFPARSER_H */



