/* 
 * File:   AphidsConfParser.h
 * Author: b10n1k
 *
 * Created on February 27, 2015, 2:58 AM
 */

#ifndef APHIDSCONFPARSER_H
#define	APHIDSCONFPARSER_H

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

//#include "Aphids.h"

class AphidsParser
{
public:
    AphidsParser(const char*);
    
    void parse(ifstream&);
    float getProbMove() ;
    float getProbKill() ;
    float getProbAdditional() ;
    float getProbBirth() ;
    
private:
    ifstream aphids_data;
    float pm; //probability move
    float palb; //probability kill
    float paln; //addditional probability kill in the cell
    float pb; //probability birth
};

#endif	/* APHIDSCONFPARSER_H */


