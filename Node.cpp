#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

// CONSTRUCTOR/DESTRUCTOR

Node::Node()
{

    activeNode = false;
    posX = -1;
    posY = -1;

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

    // packageHandler
    packageHandler(newPackage);

}

void Node::packageHandler(Package* p_Package)
{

    // Populate Dijkstra's Table
    std::vector<Dijkstra>* v;
    dijkstraHandler(v, 0);



}

void Node::dijkstraHandler(std::vector<Dijkstra>* container, int currentWeight)
{

  Dijkstra* newDijkstra;
  int lowestWeight = 999;

  // Base case 0 things in Dijkstra graph
  if(container->size() == 0)
  {
    std::cout << "Base Case:" << std::endl;

    // add all neighbors
    for(unsigned int x = 0; x < neighborStructs.size(); x++)
    {
      std::cout << "Add new neighbor," << std::endl;

      // add neighbor x into the container
      newDijkstra = new Dijkstra();
      newDijkstra->toNode = neighborStructs[x].node;
      newDijkstra->fromNode = this;
      newDijkstra->weight = neighborStructs[x].weightBetween;
      container.push_back(newDijkstra)

      if(newDijkstra->weight < lowestWeight)
      {
        lowestWeight = newDijkstra->weight;
      }

    }

    // Check the container and choose the lowest path
    std::cout << "All neighbors added, lowest weight chosen: " << lowestWeight << std::endl;
    findLowestWeightNode()->dijkstraHandler(container, lowestWeight + currentWeight);


  }



}

Node* Node::findLowestWeightNode(std::vector<Dijkstra>* container)
{

  Node* holdNode = container[0]->toNode;
  int currentWeight = container[0]->weight;
  for(int x = 1; x < container.size(); x++)
  {

    if(container[x]->weight < currentWeight)
    {

      // switch hold node and currentWeight data
      holdNode = container[x]->toNode;
      currentWeight = container[x]->weight;

    }

  }

  return holdNode;

}

bool Node::compareNeighbors(Node* one, Node* two)
{

  if(one == two)
  {
    return true;
  }

  return false;

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
