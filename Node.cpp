#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

// CONSTRUCTOR/DESTRUCTOR

Node::Node()
{

    activeNode = false;
    posX = -1;
    posY = -1;
    weight = 999;

}

Node::~Node()
{


}

void Node::activateNode(int x, int y)
{

    activeNode = true;
    posX = x;
    posY = y;

}

bool Node::isActive()
{

    return activeNode;

}

void Node::addNeighbor(Node* p_Neighbor)
{
    int distanceX = p_Neighbor->posX - posX;
    int distanceY = p_Neighbor->posY - posY;

    if(distanceX < 0)
    {
      distanceX *= -1;
    }

    if(distanceY < 0)
    {
      distanceY *= -1;
    }

    // Set up new Neighbor and fill data
    Neighbor* newNeighbor = new Neighbor();
    newNeighbor->node = p_Neighbor;
    newNeighbor->weightBetween = distanceX + distanceY;

    neighborStructs.push_back(newNeighbor);

}

int Node::getNeighborCount()
{

    return neighborStructs.size();

}

void Node::startPackageDelivery(Node* destNode)
{

    // Package is received
    std::cout << "Received package at postion (" << posX << ", " << posY << ")" << std::endl;

    //  Build a package with both start node, destination node,
    Package* newPackage = new Package();
    newPackage->startNode = this;
    newPackage->destNode = destNode;

    // starting node always has a weight of 0
    weight = 0;

    // packageHandler
    packageHandler(newPackage);

}

void Node::packageHandler(Package* p_Package)
{

    // Set each neighbors weight
    for(int x = 0; x < neighborStructs->size(); x++)
    {
        if(neighborStructs[x]->node->getWeight() > neighborStructs[x]->weightBetween)
        {
          neighborStructs[x]->node->setWeight(neighborStructs[x]->weightBetween + weight);
        }
    }

}

void Node::setWeight(int value)
{

    weight = value;

}

int Node::getWeight()
{

    return weight;

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
