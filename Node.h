#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>

class Node
{

struct Package{

    Node* startNode;
    Node* destNode;
    std::vector<Node*> vistedNodes;

};

struct Neighbor{

    Node* node;
    int weightBetween;

};

public:

    // constructor/destructor
    Node();
    ~Node();
    std::string printNodeFile();
    std::string printNodeScreen();
    void activateNode(int, int);
    bool isActive();
    void addNeighbor(Node*);
    int getNeighborCount();
    void startPackageDelivery(Node*);
    void setWeight(int);
    int getWeight();

private:

    void packageHandler(Package*);

    bool activeNode;
    int posX;
    int posY;
    int weight;
    std::vector<Neighbor*> neighborStructs;

};


#endif
