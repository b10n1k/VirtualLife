#include "WorldConfParser.h"

WorldParser::WorldParser(const char* infile) 
	: world_data(infile, ios::in) {
	if( world_data.is_open() )
	{
    	parse(world_data);
	}
	else
	{
            ifstream world_data("defaultladybugs.conf", ios::in);
            parse(world_data);
	}
}

void WorldParser::parse(ifstream &fdata) {
    fdata >> rows >> columns;
    //cout<< rows <<" "<< columns <<endl;

    fdata >> numofaphids;
    //cout<< numofaphids <<endl;

    for (size_t counter = 0; counter < numofaphids; counter++) {
        int r;
        int c;
        
        fdata >> r >> c;
        Location aphidsHasLocation(r,c);
        aphpositions.push_back(aphidsHasLocation);
    }
    //    for (int counter=0;counter<numofaphids;counter++)
    //        cout << aphids[counter] << endl;

    fdata >> numofladybugs;
    //    cout<< numofladybugs <<endl;

    for (size_t counter = 0; counter < numofladybugs; counter++) {
        int r;
        int c;
        
        fdata >> r >> c;
        Location ladybugsHasLocation(r,c);
        ladypositions.push_back(ladybugsHasLocation);
    }
}

int WorldParser::getRows() const{
    return rows;
}

int WorldParser::getColumns() const{
    return columns;
}

int WorldParser::getNumofaphids() const{
    return numofaphids;
}

int WorldParser::getNumofladybugs() const{
    return numofladybugs;
}

vector<Location> WorldParser::getLadyPositions() const{
    return ladypositions;
}

vector<Location> WorldParser::getAphPositions() const{
    return aphpositions;
}
