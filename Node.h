#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

class Node
{

public:

    // constructor/destructor
    Node();
    ~Node();
    std::string printNodeFile();
    std::string printNodeScreen();
    void activateNode();
    bool isActive();
    void addNeighbor(Node*);
    int getNeighborCount();

private:

    bool activeNode;
    std::vector<Node*> neighborStructs;

};


#endif