#include "LadybugsConfParser.h"
class Ladybugs;

/**
 * Parser Ctor
 * 
 * @param infile
 */
LadybugsParser::LadybugsParser(const char* infile):
	ladybugs_data(infile, ios::in)
  {
	  if( ladybugs_data.is_open() )
	{
    parse(ladybugs_data);
    }
	else
	{
            ifstream ladybugs_data("defaultladybugs.conf", ios::in);
            parse(ladybugs_data);
	}
    
}

/**
 * the main parser function
 * 
 * @param fdata
 */
void LadybugsParser::parse(ifstream &fdata) {
    fdata >> pm;
    
    fdata >> pcd;
        
    fdata >> pla;
    
    fdata >> pb;
}

//getters
float LadybugsParser::getProbMove() {
    return pm;
}

float LadybugsParser::getProbDirection() {
    return pcd;
}

float LadybugsParser::getProbKill() {
    return pla;
}

float LadybugsParser::getProbBirth() {
    return pb;
}
