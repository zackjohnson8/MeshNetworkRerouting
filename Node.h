#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

struct Neighbor{

    int xPos;
    int yPos;

};

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
    void addNeighbor(int, int);

private:

    bool activeNode;
    int gridPosX;
    int gridPosY;
    std::vector<Neighbor> neighborStructs;

};


#endif