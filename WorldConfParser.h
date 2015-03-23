/* 
 * File:   WorldConfParser.h
 * Author: b10n1k
 *
 * Created on February 27, 2015, 1:02 AM
 */

#ifndef WORLDCONFPARSER_H
#define	WORLDCONFPARSER_H
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
//#include "Ladybugs.h"
#include "Location.h"

class WorldParser
{
public:
    WorldParser(const char*);
    
    void parse(ifstream&);
    int getRows() const;
    int getColumns() const;
    int getNumofaphids() const;
    int getNumofladybugs() const;
    vector<Location> getAphPositions() const;
    vector<Location> getLadyPositions() const;
    
    vector<Location> ladypositions;
    vector<Location> aphpositions;
    
private:
    ifstream world_data;
    unsigned rows;
    unsigned columns;
    unsigned numofaphids;
    unsigned numofladybugs;

};


#endif	/* WORLDCONFPARSER_H */

