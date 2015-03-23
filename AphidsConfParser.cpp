#include "AphidsConfParser.h"
class Aphids;

/**
 * Parser Ctor
 * 
 * @param infile
 */
AphidsParser::AphidsParser(const char* infile):
	aphids_data(infile, ios::in)
  {
	if( aphids_data.is_open() )
	{
    	parse(aphids_data);
    }
	else
	{
            ifstream aphids_data("defaultaphids.conf", ios::in);
            parse(aphids_data); 
	}
}

/**
 * the main parser function
 * 
 * @param fdata 
 */
void AphidsParser::parse(ifstream &fdata) {
	
    fdata >> pm;

    fdata >> palb; 
        
    fdata >> paln;
    
    fdata >> pb;
    
}

//getters functions
float AphidsParser::getProbMove() {
    return pm;
}

float AphidsParser::getProbKill() {
    return palb;
}

float AphidsParser::getProbAdditional() {
    return paln;
}

float AphidsParser::getProbBirth() {
    return pb;
}
