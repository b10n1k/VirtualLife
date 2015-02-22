/* 
 * File:   Location.h
 * Author: b10n1k
 *
 * Created on February 21, 2015, 7:58 PM
 */

#ifndef LOCATION_H
#define	LOCATION_H

#include <string>

using std::string;
        
class Location
{
private:
    int numberof_aphids;
    int numberof_ladybugs;
    string location_name;
    
public:
    //setters
    void setLocationName(string);
    void setNumberof_aphids(int);
    void setNumberof_ladybugs(int);
    
    //getters
    string getLocationName(void) const;
    int getNumberof_aphids(void) const;
    int getNumberof_aphids(void) const;
    
    //constructors
    Location();
    Location(string, int=0, int=0);
    ~Location();
    
    void print_info(void);
};

#endif	/* LOCATION_H */

