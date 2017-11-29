#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>

class Node
{

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
    void deliverPackage(Node*);

private:

    bool activeNode;
    int posX;
    int posY;
    std::vector<Node*> neighborStructs;

};


#endif