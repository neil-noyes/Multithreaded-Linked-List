#ifndef planets_h
#define planets_h

#include<iostream>
using namespace std;

class Planet{
  public:

    Planet();
    /*Narrative: planet default constructor
    Pre-condition: n/a
    Post-condition: n/a UNUSED*/
    Planet(string n, double m, int d, double dfs);
    /*Narrative: Planet parameterized constructor
    Pre-condition: n/a
    Post-condition: planet is created*/
    string Name() const;
    /*Narrative: returns planet name
    Pre-condition: planet created
    Post-condition: returns string with planet name*/
    double DistanceFromSun() const;
    /*Narrative: returns planet distance from sun
    Pre-condition: planet created
    Post-condition: returns double with planet distance from sun*/
    double Mass() const;
    /*Narrative: returns planet mass
    Pre-condition: planet created
    Post-condition: returns double with planet mass*/
    int Diameter() const;
    /*Narrative: returns planet diameter
    Pre-condition: planet created
    Post-condition: returns int with planet diameter*/

  private:
    string name;
    double mass;
    int diameter;
    double distanceFromSun;
};

#endif
