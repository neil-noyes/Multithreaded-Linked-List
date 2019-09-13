#ifndef planetlist_h
#define planetlist_h

#include<iostream>
#include<cstdlib>
#include"planets.h"
using namespace std;


struct node{
  Planet p;

  node* nextMass;
  node* prevMass;

  node* nextDia;
  node* prevDia;

  node* nextDist;
  node* prevDist;
};

class PlanetList{
public:
  //********************************constructors && destructor
  PlanetList();
  /*Narrative: List default constructor
  Pre-condition: n/a
  Post-condition: list is created*/

  PlanetList(const PlanetList& otherList);
  /*Narrative: copy constructor
  Pre-condition: one main list has been created
  Post-condition: calling list creates new list that is comparably the same as caller*/

  ~PlanetList();
  /*Narrative: List destructor
  Pre-condition: a list has been created
  Post-condition: list is destroyed with all memory freed*/

  PlanetList& operator=(const PlanetList& otherList);
  /*Narrative: checks for self assignment then copies other list into this list
  Pre-condition: list created
  Post-condition: this list identical to otherList*/

  //********************************transformers
  void AddPlanetToList(Planet newPlanet);
  /*Narrative: Allocates memory for a new node, fills it with passed in object and calls functions to link nodes in each category
  Pre-condition: list is created
  Post-condition: planet object is added to list and links are patched*/

  void AddPlanetUser();
  /*Narrative: add’s planet to list if name of planet not already in list
  Pre-condition: list created
  Post-condition: fully filled planet added to list given user input if name not in list already*/

  void DeletePlanet(node* delPlanet);
  /*Narrative: delete a node of the list, patching up links and freeing memory
  Pre-condition: list is created
  Post-condition: deletes a given node, frees its memory and patches up links for remaining nodes*/

  void DeletePlanetUser();
  /*Narrative: delete’s planet to list if name of planet in list is in list
  Pre-condition: list created
  Post-condition: planet with name given deleted if there*/

  //********************************observers
  bool IsThere(string name) const;
  /*Narrative: returns true if planet is in list with name given false otherwise
  Pre-condition: list created
  Post-condition: bool indicating inclusivity returned*/

  bool IsEmpty() const;
  /*Narrative: checks to see if the list is empty
  Pre-condition: list created
  Post-condition: bool indicating emptiness is returned*/

  void DisplayDfs() const;
  /*Narrative: Displays list of planets from least to greatest distance from sun
  Pre-condition: list created
  Post-condition: displays planets from least to greatest distance from sun*/

  void DisplayMass() const;
  /*Narrative: Displays list of planets from least to greatest mass
  Pre-condition: list created
  Post-condition: displays planets from least to greatest mass*/

  void DisplayDia() const;
  /*Narrative: Displays list of planets from least to greatest diameter
  Pre-condition: list created
  Post-condition: displays planets from least to greatest diameter*/

  void DisplayRevDist() const;
  /*Narrative: Displays list of planets from greatest to least distance from sun
  Pre-condition: list created
  Post-condition: displays planets from greatest to least distance from sun*/

  node* GetNode(string name) const;
  /*Narrative: Returns the node* of the planet we want to find, passing in a name
  Pre-condition: planet list has been created
  Post-condition: if there is a node that contains a planet with the passed in name, a ptr to this node will be returned*/

private:
  void MassLink(node* newNode);
  /*Narrative: Patches links for mass category when a new node is inserted
  Pre-condition: list is created
  Post-condition: links in mass category will be patched together*/

  void PushMass(node* newNode);
  /*Narrative: If the passed in node’s planet’s mass is less than the first node’s planet mass, we have to make this new node the first planet in the list. This means our mass head ptr now points to pushNode and pushNode’s next mass link points to the old first node in the list
  Pre-condition: list is created
  Post-condition: links in new node before the first node*/

  void AppendMass(node* newNode);
  /*Narrative: If the passed in node’s planet’s mass is greater than the last node’s planet mass, we have to make this new node the last planet in the list. This means our mass tail ptr now points to appNode and appNode’s next mass link points to null
  Pre-condition: list is created
  Post-condition: links in new node after the last node*/

  void InsertBeforeMass(node* newNode);
  /*Narrative: If the passed in node’s planet’s mass is greater than the the first node’s planet’s mass and also less than the last node’s planet’s mass, we have to find where to insert the new node in the list and patch the links
  Pre-condition: list is created
  Post-condition: links in new node somewhere in list*/

  void DiaLink(node* newNode);
  /*Narrative: Patches links for diameter category when a new node is inserted
  Pre-condition: list is created
  Post-condition: links in diameter category will be patched together*/

  void PushDia(node* newNode);
  /*Narrative: If the passed in node’s planet’s diameter is less than the first node’s planet diameter, we have to make this new node the first planet in the list. This means our diameter head ptr now points to pushNode and pushNode’s next diameter link points to the old first node in the list
  Pre-condition: list is created
  Post-condition: links in new node before the first node*/

  void AppendDia(node* newNode);
  /*Narrative: If the passed in node’s planet’s diameter is greater than the last node’s planet diameter, we have to make this new node the last planet in the list. This means our diameter tail ptr now points to appNode and appNode’s next diameter link points to null
  Pre-condition: list is created
  Post-condition: links in new node after the last node*/

  void InsertBeforeDia(node* newNode);
  /*Narrative: If the passed in node’s planet’s diameter is greater than the the first node’s planet’s mass and also less than the last node’s planet’s diameter, we have to find where to insert the new node in the list and patch the links
  Pre-condition: list is created
  Post-condition: links in new node somewhere in list*/

  void DistLink(node* newNode);
  /*Narrative: Patches links for distance category when a new node is inserted
  Pre-condition: list is created
  Post-condition: links in distance category will be patched together*/

  void PushDist(node* newNode);
  /*Narrative: If the passed in node’s planet’s distance is less than the first node’s planet distance, we have to make this new node the first planet in the list. This means our distance head ptr now points to pushNode and pushNode’s next distance link points to the old first node in the list
  Pre-condition: list is created
  Post-condition: links in new node before the first node*/

  void AppendDist(node* newNode);
  /*Narrative: If the passed in node’s planet’s distance is greater than the last node’s planet distance, we have to make this new node the last planet in the list. This means our distance tail ptr now points to appNode and appNode’s next distance link points to null
  Pre-condition: list is created
  Post-condition: links in new node after the last node*/

  void InsertBeforeDist(node* newNode);
  /*Narrative: If the passed in node’s planet’s distance is greater than the the first node’s planet’s mass and also less than the last node’s planet’s distance, we have to find where to insert the new node in the list and patch the links
  Pre-condition: list is created
  Post-condition: links in new node somewhere in list*/

  node* GetDistHead() const;
  /*Narrative: returns dist head ptr
  Pre-condition: list created
  Post-condition: returns node* to dist head*/

  node* GetDistTail() const;
  /*Narrative: returns dist tail ptr
  Pre-condition: list created
  Post-condition: returns node* to dist tail*/

  node* GetDiaHead() const;
  /*Narrative: returns dia head ptr
  Pre-condition: list created
  Post-condition: returns node* to dia head*/

  node* GetDiaTail() const;
  /*Narrative: returns dia tail ptr
  Pre-condition: list created
  Post-condition: returns node* to dia tail*/

  node* GetMassHead() const;
  /*Narrative: returns mass head ptr
  Pre-condition: list created
  Post-condition: returns node* to mass head*/

  node* GetMassTail() const;
  /*Narrative: returns mass tail ptr
  Pre-condition: list created
  Post-condition: returns node* to mass tail*/

  void ClearList();
  /*Narrative: clears list of all nodes
  Pre-condition: list created
  Post-condition: list now empty*/

  void CopyToMe(const PlanetList& otherList);
  /*Narrative: copies over all nodes from otherList and adds them to list
  Pre-condition: list created
  Post-condition: list and otherList the same*/

  node* hDist;
  node* tDist;
  node* hDia;
  node* tDia;
  node* hMass;
  node* tMass;
};

#endif
