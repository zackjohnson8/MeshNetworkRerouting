/**
  * @developers Zachary L. Johnson, Rony Calderon, and Logan Long
  *
  * @details Self repairing Mesh Network
  *
  * @version 1.00
  *          Original development (December 6, 2017)
  *
*/

#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>

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

struct Dijkstra
{

    Node* toNode;
    Node* fromNode;
    int weight;

};

struct MST
{

  Node* toNode;
  Node* fromNode;
  int weight;
  bool visited;

};

public:

    // constructor/destructor
    Node();
    ~Node();
    std::string printNodeFile();
    std::string printNodeScreen();
    void activateNode(int, int);
    bool isActive();
    void setActive(bool);
    void addNeighbor(Node*);
    int getNeighborCount();
    void startPackageDelivery(Node*);

private:

    void packageHandler(Package*);
    void dijkstraHandler(std::vector<Dijkstra*>, int, std::vector<Node*>, Node*);
    bool checkContainer(std::vector<Dijkstra*>, Node*);
    bool wasVisited(std::vector<Node*>, Node*);
    void sendBackToStart(std::vector<Node*>, int);
    void sendPackageToDestination(Package*, std::vector<Node*>, Node*, Node*);
    void MSTHandler(std::vector<MST*>, Node*, Node*);
    bool checkContainerMST(std::vector<MST*>, Node*);
    bool allVisited(std::vector<MST*>);

    bool activeNode;
    int posX;
    int posY;
    std::vector<Neighbor*> neighborStructs;
    std::vector<Node*> pathToDestination;

    int passBackCount;

};


#endif
