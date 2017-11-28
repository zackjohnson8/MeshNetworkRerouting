#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

// CONSTRUCTOR/DESTRUCTOR 

Node::Node()
{

    activeNode = false;

}

Node::~Node()
{


}

void Node::activateNode()
{

    activeNode = true;

}

bool Node::isActive()
{

    return activeNode;

}

void Node::addNeighbor(Node* newNeighbor)
{

    neighborStructs.push_back(newNeighbor);

}

int Node::getNeighborCount()
{

    return neighborStructs.size();

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

