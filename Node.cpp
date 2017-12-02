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
    std::vector<Dijkstra*> v;
    std::vector<Node*> visited;
    dijkstraHandler(v, 0, visited);



}

bool Node::checkContainer(std::vector<Dijkstra*> pContainer, Node* pNode)
{

  for(unsigned int x = 0; x < pContainer.size(); x++)
  {

    if(pContainer[x]->toNode == pNode)
    {

      return true;

    }

  }

  return false;

}

bool Node::wasVisited(std::vector<Node*> pContainer, Node* pNode)
{
  for(unsigned int x = 0; x < pContainer.size(); x++)
  {

    if(pContainer[x] == pNode)
    {
      return true;
    }
  }

  return false;

}

void Node::dijkstraHandler(std::vector<Dijkstra*> container, int currentWeight, std::vector<Node*> visited)
{
  visited.push_back(this);
  Dijkstra* newDijkstra = NULL;

  // Create new dijkstra structs based on the neighbors
  for(unsigned int x = 0; x < neighborStructs.size(); x++)
  {

    // for each neighbor check if they are in the container
    if(!checkContainer(container, neighborStructs[x]->node) && !wasVisited(visited, neighborStructs[x]->node))
    {
      // if it isn't in the container you should add it
      newDijkstra = new Dijkstra();
      newDijkstra->toNode = neighborStructs[x]->node;
      newDijkstra->fromNode = this;
      newDijkstra->weight = neighborStructs[x]->weightBetween;

      container.push_back(newDijkstra);

      std::cout << "Pushed on new node" << std::endl;

    }

  }

  // Update container to have corrected weights for each neighbor
  for(unsigned int x = 0; x < neighborStructs.size(); x++)
  {
    // Each neighbor is now for sure in the container of dijkstra
    // for each of the neighbors go through the container and change info
    for(unsigned int y = 0; y < container.size(); y ++)
    {
        // for neighbor x is this his data y?
        if(neighborStructs[x]->node == container[y]->toNode)
        {
          // if the current weight + weight between is less than that nodes weight then replace
          if(neighborStructs[x]->weightBetween + currentWeight < container[y]->weight && !wasVisited(visited, neighborStructs[x]->node))
          {
            container[y]->weight = neighborStructs[x]->weightBetween + currentWeight;
            std::cout << "Replaced a weight" << std::endl;
          }
        }
    }
  }

  // Pick the correct neighbor to traverse to
  // For each neighbor
  int lowestWeight = 999;
  Node* passToNode = NULL;
  for(unsigned int x = 0; x < neighborStructs.size(); x++)
  {
    // For each container value
    for(unsigned int y = 0; y < container.size(); y ++)
    {
        // if this container item is the neighbor structs data
        // check if this is the lowest path
        if(neighborStructs[x]->node == container[y]->toNode && !wasVisited(visited, neighborStructs[x]->node))
        {
          if(container[y]->weight < lowestWeight)
          {
              lowestWeight = container[y]->weight;
              passToNode = container[y]->toNode;
          }
        }
    }
  }

  passToNode->dijkstraHandler(container, lowestWeight, visited);

/*
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

*/

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
