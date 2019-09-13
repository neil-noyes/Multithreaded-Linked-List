#include<iostream>
#include "planets.h"
using namespace std;

Planet::Planet(){

}

Planet::Planet(string n, double m, int d, double dfs):
                name(n),mass(m),diameter(d),distanceFromSun(dfs)
{

}

string Planet::Name() const{
  return name;
}

double Planet::DistanceFromSun() const{
  return distanceFromSun;
}

double Planet::Mass() const{
  return mass;
}

int Planet::Diameter() const{
  return diameter;
}
