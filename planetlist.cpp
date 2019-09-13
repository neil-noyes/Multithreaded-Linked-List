#include<iostream>
#include<cstdlib>
#include<ctype.h>
#include"planetlist.h"
#include"planets.h"
using namespace std;
//**********constructors & destructor******************
PlanetList::PlanetList(): hDist(NULL), tDist(NULL),
                          hMass(NULL), tMass(NULL),
                          hDia(NULL), tDia(NULL)
{

}

PlanetList::~PlanetList(){

if (!IsEmpty()){
  //create starting point
  node* start = hMass;

  while (start->nextMass != NULL){
    DeletePlanet(GetNode(start->p.Name()));
    start = start->nextMass;
  }
  DeletePlanet(tMass);
}

}

PlanetList::PlanetList(const PlanetList& otherList): hDist(NULL), tDist(NULL),
                                                     hMass(NULL), tMass(NULL),
                                                     hDia(NULL), tDia(NULL)
{
  if (!otherList.IsEmpty()){
    CopyToMe(otherList);
  }
}

PlanetList& PlanetList::operator=(const PlanetList& otherList){

  if (this != &otherList){
    ClearList();
    CopyToMe(otherList);
  }
  return *this;
}

void PlanetList::ClearList(){

if (!IsEmpty()){
  node* start = hMass;
  while(start != NULL){
    DeletePlanet(start);
    start = start->nextMass;
  }
}

}

void PlanetList::CopyToMe(const PlanetList& otherList){

  if (!otherList.IsEmpty()){

    node* tracer = otherList.GetMassHead();

    while (tracer->nextMass != NULL){
      Planet addPlanet = tracer->p;
      AddPlanetToList(addPlanet);
      //does not matter which category we trace, AddPlanetToList handles
      //all categories and their links for each category
      tracer = tracer->nextMass;
    }
    Planet last = otherList.tMass->p;
    AddPlanetToList(last);
  }

}


//**************transformers*******************
void PlanetList::PushDist(node* pushNode){

  //making next of pushNode to head & prev to NULL
  pushNode->nextDist = hDist;
  pushNode->prevDist = NULL;

  //change prev of head to pushNode
  hDist->prevDist = pushNode;

  //move head to point to pushNode
  hDist = pushNode;
}

void PlanetList::AppendDist(node* appNode){

  //get old tail in a new ptr
  node* last = tDist;

  //make the next of last node to appNode
  last->nextDist = appNode;

  //make prevDia of appNode the old last node
  appNode->prevDist = last;

  //make dia tail point to app node
  tDist = appNode;

  //make appNodes next be null
  appNode->nextDist = NULL;
}

void PlanetList::InsertBeforeDist(node* bfNode){

  //get a start for traversal
  node* start = hDist;

  //traverse until next dia is greater than
  while(bfNode->p.DistanceFromSun() > start->p.DistanceFromSun()){
    start = start->nextDist;
  }

  //make new prev the prev of the next node in line
  bfNode->prevDist = start->prevDist;

  //make previous of next node the new node
  start->prevDist = bfNode;

  //make next node in line the next of our new node
  bfNode->nextDist = start;

  //change next of new nodes previous node
  bfNode->prevDist->nextDist = bfNode;

}

void PlanetList::DistLink(node* newNode){

  //empty case
  if (hDist == NULL){
    newNode->nextDist = NULL;
    newNode->prevDist = NULL;
    hDist = newNode;
    tDist = newNode;
    return;
  }

  //head case (our poassed in value is less than head)
  if (newNode->p.DistanceFromSun() < hDist->p.DistanceFromSun()){
    //push
    PushDist(newNode);
  }

  //end case (our passed in value is greater than tail)
  else if (newNode->p.DistanceFromSun() > tDist->p.DistanceFromSun()){
    //append
    AppendDist(newNode);
  }

  //in between case (greater than head, less than tail - need to iterate)
  else{
    //insert before node that has greater value than new nodes
    InsertBeforeDist(newNode);
  }

}

void PlanetList::PushDia(node* pushNode){

  //making next of pushNode to head & prev to NULL
  pushNode->nextDia = hDia;
  pushNode->prevDia = NULL;

  //change prev of head to pushNode
  hDia->prevDia = pushNode;

  //move head to point to pushNode
  hDia = pushNode;
}

void PlanetList::AppendDia(node* appNode){

  //get old tail in a new ptr
  node* last = tDia;

  //make the next of last node to appNode
  last->nextDia = appNode;

  //make prevDia of appNode the old last node
  appNode->prevDia = last;

  //make dia tail point to app node
  tDia = appNode;

  //make appNodes next be null
  appNode->nextDia = NULL;
}

void PlanetList::InsertBeforeDia(node* bfNode){

  //get a start for traversal
  node* start = hDia;

  //traverse until next dia is greater than
  while(bfNode->p.Diameter() > start->p.Diameter()){
    start = start->nextDia;
  }

  //make new prev the prev of the next node in line
  bfNode->prevDia = start->prevDia;

  //make previous of next node the new node
  start->prevDia = bfNode;

  //make next node in line the next of our new node
  bfNode->nextDia = start;

  //change next of new nodes previous node
  bfNode->prevDia->nextDia = bfNode;

}

void PlanetList::DiaLink(node* newNode){

  //empty case
  if (hDia == NULL){
    newNode->nextDia = NULL;
    newNode->prevDia = NULL;
    hDia = newNode;
    tDia = newNode;
    return;
  }

  //head case (our poassed in value is less than head)
  if (newNode->p.Diameter() < hDia->p.Diameter()){
    //push
    PushDia(newNode);
  }

  //end case (our passed in value is greater than tail)
  else if (newNode->p.Diameter() > tDia->p.Diameter()){
    //append
    AppendDia(newNode);
  }

  //in between case (greater than head, less than tail - need to iterate)
  else{
    //insert before node that has greater value than new nodes
    InsertBeforeDia(newNode);
  }

}

void PlanetList::PushMass(node* pushNode){

  //making next of pushNode to head & prev to NULL
  pushNode->nextMass = hMass;
  pushNode->prevMass = NULL;

  //change prev of head to pushNode
  hMass->prevMass = pushNode;

  //move head to point to pushNode
  hMass = pushNode;

}

void PlanetList::AppendMass(node* appNode){

  //get old tail in a new ptr
  node* last = tMass;

  //make the next of last node to appNode
  last->nextMass = appNode;

  //make prevMass of appNode the old last node
  appNode->prevMass = last;

  //make mass tail point to app node
  tMass = appNode;

  //make appNodes next be null
  appNode->nextMass = NULL;
}

void PlanetList::InsertBeforeMass(node* bfNode){

  //get a start for traversal
  node* start = hMass;

  //traverse until next mass is greater than
  while(bfNode->p.Mass() > start->p.Mass()){
    start = start->nextMass;
  }

  //make new prev the prev of the next node in line
  bfNode->prevMass = start->prevMass;

  //make previous of next node the new node
  start->prevMass = bfNode;

  //make next node in line the next of our new node
  bfNode->nextMass = start;

  //change next of new nodes previous node
  bfNode->prevMass->nextMass = bfNode;

}

void PlanetList::MassLink(node* newNode){

  //empty case
  if (hMass == NULL){
    newNode->nextMass = NULL;
    newNode->prevMass = NULL;
    hMass = newNode;
    tMass = newNode;
    return;
  }

  //head case (our poassed in value is less than head)
  if (newNode->p.Mass() < hMass->p.Mass()){
    //push
    PushMass(newNode);
  }

  //end case (our passed in value is greater than tail)
  else if (newNode->p.Mass() > tMass->p.Mass()){
    //append
    AppendMass(newNode);
  }

  //in between case (greater than head, less than tail - need to iterate)
  else{
    //insert before node that has greater value than new nodes
    InsertBeforeMass(newNode);
  }

}

void PlanetList::AddPlanetToList(Planet newPlanet){

  //allocate new node
  node* newNode = new node();

  //load it with the new planet
  newNode->p = newPlanet;


  MassLink(newNode);
  DiaLink(newNode);
  DistLink(newNode);


  return;
}

node* PlanetList::GetNode(string name) const{

  //make name pretty
  name[0] = toupper(name[0]);
  for (int i = 1; i < name.length(); ++i){
    name[i] = tolower(name[i]);
  }

  //create return pointer
  node* retPtr;

  node* massHead = GetMassHead();
  //iterate through until we find the planet we need
  if (massHead != NULL){

    retPtr = massHead;
    while(retPtr->p.Name() != name){
      retPtr = retPtr->nextMass;
    }

  }
  else{
    retPtr = NULL;
  }

  return retPtr;

}

void PlanetList::DeletePlanet(node* delPlanet){

  if (!IsEmpty() && delPlanet != NULL){

      //check if node to be deleted is the head of each cat
      if (hMass == delPlanet)
        hMass = delPlanet->nextMass;
      if (hDia == delPlanet)
        hDia = delPlanet->nextDia;
      if (hDist == delPlanet)
        hDist = delPlanet->nextDist;

      //check if node to be deleted is the tail of each cat
      if (tMass == delPlanet)
        tMass = delPlanet->prevMass;
      if (tDia == delPlanet)
        tDia = delPlanet->prevDia;
      if (tDist == delPlanet)
        tDist = delPlanet->prevDist;

      //patch up next in each category if delPlanet *isnt* last node
      if (delPlanet->nextMass != NULL)
        delPlanet->nextMass->prevMass = delPlanet->prevMass;
      if (delPlanet->nextDia != NULL)
        delPlanet->nextDia->prevDia = delPlanet->prevDia;
      if (delPlanet->nextDist != NULL)
        delPlanet->nextDist->prevDist = delPlanet->prevDist;

      //patch up prev in each category if delPlanet *isnt* first node
      if (delPlanet->prevMass != NULL)
        delPlanet->prevMass->nextMass = delPlanet->nextMass;
      if (delPlanet->prevDia != NULL)
        delPlanet->prevDia->nextDia = delPlanet->nextDia;
      if (delPlanet->prevDist != NULL)
        delPlanet->prevDist->nextDist = delPlanet->nextDist;

      delete delPlanet;
  }

}





//**************observers*******************
bool PlanetList::IsEmpty() const{

  bool empty = false;

  if (hDist == NULL || hMass == NULL || hDia == NULL)
    empty = true;

  return empty;
}

node* PlanetList::GetDistHead() const{
  return hDist;
}

node* PlanetList::GetDistTail() const{
  return tDist;
}

void PlanetList::DisplayDfs() const{

  if (!IsEmpty()){
    node* start = GetDistHead();
    while (start->nextDist != NULL){
      cout << start->p.Name() << " " << start->p.DistanceFromSun() << endl;
      start = start->nextDist;
    }
    node* end = GetDistTail();
    cout << end->p.Name() << " " << end->p.DistanceFromSun() << endl;
  }

}

node* PlanetList::GetDiaHead() const{
  return hDia;
}

node* PlanetList::GetDiaTail() const{
  return tDia;
}

void PlanetList::DisplayDia() const{

  if (!IsEmpty()){
    node* start = GetDiaHead();
    while (start->nextDia != NULL){
      cout << start->p.Name() << " " << start->p.Diameter() << endl;
      start = start->nextDia;
    }
    node* end = GetDiaTail();
    cout << end->p.Name() << " " << end->p.Diameter() << endl;
  }

}

node* PlanetList::GetMassHead() const{
  return hMass;
}

node* PlanetList::GetMassTail() const{
  return tMass;
}

void PlanetList::DisplayMass() const{

  if (!IsEmpty()){
    node* start = GetMassHead();
    while (start->nextMass != NULL){
      cout << start->p.Name() << " " << start->p.Mass() << endl;
      start = start->nextMass;
    }
    node* end = GetMassTail();
    cout << end->p.Name() << " " << end->p.Mass() << endl;
  }
}

void PlanetList::DisplayRevDist() const{

if (!IsEmpty()){
    node* start = GetDistTail();
    while (start->prevDist != NULL){
      cout << start->p.Name() << " " << start->p.DistanceFromSun() << endl;
      start = start->prevDist;
    }
    node* end = GetDistHead();
    cout << end->p.Name() << " " << end->p.DistanceFromSun() << endl;
  }

}

void PlanetList::AddPlanetUser(){

  cout << "\nAdding Planet...\n\n";
  cout << "Enter Name: ";
  string name;
  cin >> name;

  //make name pretty
  name[0] = toupper(name[0]);
  for (int i = 1; i < name.length(); ++i){
    name[i] = tolower(name[i]);
  }

  //check if already exists
  if(IsThere(name)){
    cout << "\nERROR:Planet Name Already Exists\n";
  }
  else{
    cout << "\nEnter Mass: ";
    double mass;
    cin >> mass;

    cout << "\nEnter Diameter: ";
    int diameter;
    cin >> diameter;

    cout << "\nEnter Distance From Sun: ";
    int dfs;
    cin >> dfs;

    Planet newPlanet = Planet(name,mass,diameter,dfs);
    AddPlanetToList(newPlanet);
    cout << "Added " << name << "\n";
  }


}

void PlanetList::DeletePlanetUser(){
  cout << "Enter name of planet to delete: ";
  string name;
  cin >> name;

  //make name pretty
  name[0] = toupper(name[0]);
  for (int i = 1; i < name.length(); ++i){
    name[i] = tolower(name[i]);
  }

  if (IsThere(name)){
    DeletePlanet(GetNode(name));
  }
  else{
    cout << "\nPlanet not in list\n";
  }

}

bool PlanetList::IsThere(string name) const{

  //make name pretty
  name[0] = toupper(name[0]);
  for (int i = 1; i < name.length(); ++i){
    name[i] = tolower(name[i]);
  }


  bool found = false;


  if(!IsEmpty()){

    if (name == hMass->p.Name())
      found = true;
    else if (name == tMass->p.Name())
      found = true;
    else{

      node* start = GetMassHead();
      while (start->nextMass != NULL && found == false){

        if (start->p.Name() == name)
          found = true;

        start = start->nextMass;
      }
    }
  }

  return found;
}
