#include<iostream>
#include "planets.h"
#include "planetlist.h"
using namespace std;

int main(){


  //create list my way
  PlanetList list = PlanetList();

  //create planets
  Planet saturn = Planet("Saturn",627,74897,890.8);
  Planet uranus = Planet("Uranus",95.7,31763,1784.8);
  Planet jupiter = Planet("Jupiter",2093,88846,483.8);
  Planet neptune = Planet("Neptune",113,30775,2793.1);
  Planet pluto = Planet("Pluto",0.0161,1464,3670.0);
  Planet mercury = Planet("Mercury",0.364,3032,36.0);
  Planet venus = Planet("Venus",5.37,7521,67.2);
  Planet earth = Planet("Earth",6.58,7926,93.0);
  Planet mars = Planet("Mars",0.708,4221,141.6);




  //add planets
  list.AddPlanetToList(mercury);
  list.AddPlanetToList(venus);
  list.AddPlanetToList(earth);
  list.AddPlanetToList(mars);
  list.AddPlanetToList(jupiter);
  list.AddPlanetToList(saturn);
  list.AddPlanetToList(uranus);
  list.AddPlanetToList(neptune);
  list.AddPlanetToList(pluto);

int option;
while(option != 7){
  cout << "\nPrint Options\n\n";
  cout << "1. By Distance From the Sun\n";
  cout << "2. By Mass\n";
  cout << "3. By Diameter\n";
  cout << "4. By Reverse Distance From the Sun\n";

  cout << "\nOther Options\n\n";
  cout << "5. Add Planet\n";
  cout << "6. Delete Planet\n";
  cout << "7. Exit\n";

    cin >> option;

    if (option == 1)
      list.DisplayDfs();
    else if (option == 2)
      list.DisplayMass();
    else if (option == 3)
      list.DisplayDia();
    else if (option == 4)
      list.DisplayRevDist();
    else if (option == 5)
      list.AddPlanetUser();
    else if (option == 6)
      list.DeletePlanetUser();
    else if (option == 7)
      cout << "Exiting...\n";
    else {
      cout << "Try again...\n";
    }

  }



/* Code for testing script
Planet jupiter = Planet("Jupiter",2093,88846,483.8);
cout << "PN01: ";
cout << jupiter.Name() << endl;

cout << "DFS01: ";
cout << jupiter.DistanceFromSun() << endl;

cout << "M01: ";
cout << jupiter.Mass() << endl;

cout << "D01: ";
cout << jupiter.Diameter() << endl;

cout << "\n\nConstruct List\n";
PlanetList testList = PlanetList();

cout << "AP01: ";
testList.AddPlanetToList(jupiter);

cout << "confirmiration by printing list by mass...\n";
testList.DisplayMass();

cout << "APU01: \n";
testList.AddPlanetUser();

cout << "APU02: \n";
testList.AddPlanetUser();

cout << "IE01: \n";
cout << testList.IsEmpty();

cout << "CL02: \n";
testList.ClearList();

cout << "IE02: ";
cout << testList.IsEmpty();

cout << "\nCL01: \n";
testList.ClearList();

cout << "Test Displays when empty...\n";
cout << "DDfs01: \n";
testList.DisplayDfs();
cout << "DM01: \n";
testList.DisplayMass();
cout << "DRD01: \n";
testList.DisplayRevDist();
cout << "DDia01: \n";
testList.DisplayDia();
cout << endl << endl;


Planet saturn = Planet("Saturn",627,74897,890.8);
Planet mercury = Planet("Mercury",0.364,3032,36.0);
Planet pluto = Planet("Pluto",0.0161,1464,3670.0);
Planet earth = Planet("Earth",6.58,7926,93.0);
Planet mars = Planet("Mars",0.708,4221,141.6);
Planet venus = Planet("Venus",5.37,7521,67.2);

cout << "clear list and load in diameter test group...\n";
testList.ClearList();
//saturn
Planet neptune = Planet("Neptune",113,30775,2793.1);
//jupiter
Planet uranus = Planet("Uranus",95.7,31763,1784.8);

cout << "DiaL01: add saturn\n";
testList.AddPlanetToList(saturn);
cout << "PDia01 & DiaL01: add neptune\n";
testList.AddPlanetToList(neptune);
cout << "ADia01 & DiaL03: add jupiter\n";
testList.AddPlanetToList(jupiter);
cout << "IBDia01 & DiaL04: add uranus\n\n";
testList.AddPlanetToList(uranus);

cout << "DDia02: confirm with diameter print...\n";
testList.DisplayDia();
cout << endl;

cout << "clear list and load in mass test group...\n";
testList.ClearList();
//Saturn
//Uranus
//Jupiter
//Neptune
cout << "ML01: add saturn\n";
testList.AddPlanetToList(saturn);
cout << "PM01 & ML02: add uranus\n";
testList.AddPlanetToList(uranus);
cout << "AM01 & ML03: add jupiter\n";
testList.AddPlanetToList(jupiter);
cout << "IBM01 & ML04: add neptune\n\n";
testList.AddPlanetToList(neptune);

cout << "DM02: confirm with mass print...\n";
testList.DisplayMass();
cout << endl;

cout << "clear list and load in dist test group...\n";
testList.ClearList();

cout << "DL01: add saturn\n";
testList.AddPlanetToList(saturn);
cout << "PDist01 & DL02: add mercury\n";
testList.AddPlanetToList(mercury);
cout << "ADist01 & DL03: add pluto\n\n";
testList.AddPlanetToList(pluto);

cout << "IBDist01 & DL04: add earth\n";
testList.AddPlanetToList(earth);

cout << "DDfs02: confirm with distance print...\n";
testList.DisplayDfs();
cout << endl;
cout << "DRD02: confirm with revdistance print...\n";
testList.DisplayRevDist();
cout << endl;

cout << "\n\nClear list\n";
testList.ClearList();

cout << "GN01: ";
node* nullNode = testList.GetNode("somePlanet");
if (nullNode == NULL){
  cout << "Very much null\n";
}

cout << "\nAdd all 9 back\n";
testList.AddPlanetToList(mercury);
testList.AddPlanetToList(venus);
testList.AddPlanetToList(earth);
testList.AddPlanetToList(mars);
testList.AddPlanetToList(jupiter);
testList.AddPlanetToList(saturn);
testList.AddPlanetToList(uranus);
testList.AddPlanetToList(neptune);
testList.AddPlanetToList(pluto);

cout << "IT01: " << testList.IsThere("bill") << endl;
cout << "IT02: " << testList.IsThere("pluto") << endl;

cout << endl;

cout << "\n\nTesting heads && tails with filled list..\n";
  node* mh = testList.GetMassHead();
  if (mh == NULL)
    cout << "Very Null\n";
  else
    cout << "GMH02: "<< "mh: " << mh->p.Name() << endl;

  node* mt = testList.GetMassTail();
  if (mt == NULL)
    cout << "Very Null\n";
  else
    cout << "GMT02: " << "mt: " << mt->p.Name() << endl;

  node* dh = testList.GetDiaHead();
  if (dh == NULL)
    cout << "Very Null\n";
  else
    cout << "GDiaH02: " << "dh: " << dh->p.Name() << endl;

  node* dt = testList.GetDiaTail();
  if (dt == NULL)
    cout << "Very Null\n";
  else
    cout << "GDiaT02: " << "dt: " << dt->p.Name() << endl;

  node* dih = testList.GetDistHead();
  if (dih == NULL)
    cout << "Very Null\n";
  else
    cout << "GDistH02: " << "dih: " << dih->p.Name() << endl;

  node* dit = testList.GetDistTail();
  if (dit == NULL)
    cout << "Very Null\n";
  else
    cout << "GDistT02: " << "dit: " << dit->p.Name() << endl;


cout << "\n\nConfirm starting planets with dist print...\n";
testList.DisplayDfs();
cout << endl;

node* testDel = NULL;
cout << "DP01: \n";
testList.DeletePlanet(testDel);
cout << "confirm no deletion with dist print...\n";
testList.DisplayDfs();
cout << endl;


cout << "GN02 & DP02: ";
testList.DeletePlanet(testList.GetNode("mercury"));
cout << "confirm mercury deletion with dist print...\n";
testList.DisplayDfs();
cout << endl;

cout << "DP03: ";
testList.DeletePlanet(testList.GetNode("pluto"));
cout << "confirm pluto deletion with dist print...\n";
testList.DisplayDfs();
cout << endl;

cout << "DP04: ";
testList.DeletePlanet(testList.GetNode("jupiter"));
cout << "confirm jupiter deletion with dist print...\n";
testList.DisplayDfs();
cout << endl;


cout << "DPU01: (random name)";
testList.DeletePlanetUser();

cout << "\nDPU02: (neptune)";
testList.DeletePlanetUser();


cout << "\n\nClear list\n\n";
testList.ClearList();

cout << "\n\nTesting heads && tails with empty list..\n";
  node* mh2 = testList.GetMassHead();
  if (mh2 == NULL)
    cout << "Very Null\n";
  else
    cout << "GMH02: "<< "mh: " << mh2->p.Name() << endl;

  node* mt2 = testList.GetMassTail();
  if (mt2 == NULL)
    cout << "Very Null\n";
  else
    cout << "GMT02: " << "mt: " << mt2->p.Name() << endl;

  node* dh2 = testList.GetDiaHead();
  if (dh2 == NULL)
    cout << "Very Null\n";
  else
    cout << "GDiaH02: " << "dh: " << dh2->p.Name() << endl;

  node* dt2 = testList.GetDiaTail();
  if (dt2 == NULL)
    cout << "Very Null\n";
  else
    cout << "GDiaT02: " << "dt: " << dt2->p.Name() << endl;

  node* dih2 = testList.GetDistHead();
  if (dih2 == NULL)
    cout << "Very Null\n";
  else
    cout << "GDistH02: " << "dih: " << dih2->p.Name() << endl;

  node* dit2 = testList.GetDistTail();
  if (dit2 == NULL)
    cout << "Very Null\n";
  else
    cout << "GDistT02: " << "dit: " << dit2->p.Name() << endl;



  cout << "\nCreate new list for cc & ovass...\n";
  PlanetList list = PlanetList();

  cout << "\n CC01: \n";
  PlanetList empList = PlanetList(list);

  cout << "\nDisplay list dfs: \n";
  list.DisplayDfs();
  cout << "\nDisplay empList dfs: \n";
  empList.DisplayDfs();

  cout << "\nOA01: \n";
  list = empList;
  cout << "\nDisplay list dfs: \n";
  list.DisplayDfs();
  cout << "\nDisplay empList dfs: \n";
  empList.DisplayDfs();


  cout << "\nAdd Planets to list: ";
  list.AddPlanetToList(mercury);
  list.AddPlanetToList(venus);
  list.AddPlanetToList(earth);
  list.AddPlanetToList(mars);
  list.AddPlanetToList(jupiter);
  list.AddPlanetToList(saturn);
  list.AddPlanetToList(uranus);
  list.AddPlanetToList(neptune);
  list.AddPlanetToList(pluto);

  cout << "\nDisplay list dfs\n";
  list.DisplayDfs();

  cout << "\n CC02: \n";
  PlanetList list2 = PlanetList(list);

  cout << "\nDisplay list dfs\n";
  list.DisplayDfs();
  cout << "\nDisplay list2 dfs\n";
  list2.DisplayDfs();

  cout <<"\nOA02: ";
  empList = list2;
  cout << "\nDisplay list2 dfs\n";
  list2.DisplayDfs();
  cout << "\nDisplay empList dfs: \n";
  empList.DisplayDfs();
*/
  return 0;
}
