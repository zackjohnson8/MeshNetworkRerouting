#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

// CONSTRUCTOR/DESTRUCTOR 

Node::Node()
{

    activeNode = false;
    gridPosX = -1;
    gridPosY = -1;

}

Node::~Node()
{


}

void Node::activateNode(int posX, int posY)
{

    activeNode = true;
    gridPosX = posX;
    gridPosY = posY;

}

bool Node::isActive()
{

    return activeNode;

}

void Node::addNeighbor(int x, int y)
{

    Neighbor* newNeighbor = new Neighbor();
    newNeighbor->xPos = x;
    newNeighbor->yPos = y;

    neighborStructs.push_back(*newNeighbor);

}

std::string Node::printNodeScreen()
{

    if(activeNode)
    {

        return "N";

    }

    //return std::string();
    return " ";

}

// TODO: Modify the output to specify the node being printed and its neighbors
std::string Node::printNodeFile()
{

    if(activeNode)
    {

        return "N";

    }

    //return std::string();
    return " ";

}

#endif

