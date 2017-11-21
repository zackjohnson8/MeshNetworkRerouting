#include <cstdlib>
#include <iostream>
#include <vector>
#include "Node.h"

void printNodes(Node **array, int size)
{

    std::cout << "--------------------------------------------------------------------------------" << std::endl;

    for(int x = 0; x < size; x++)
    {
        std::cout << "|";
        for(int y = 0; y < size; y++)
        {

            std::cout << array[x][y].printNode() << "|";

        }
        std::cout << std::endl;
    }


}

int main()
{

    // Initialize Parameters
    int nodeTotal = 0;
    
    do
    {
        std::cout << "Choose the total number of nodes from the options (8, 16, 32) : ";
        std::cin >> nodeTotal;

    }while(nodeTotal != 8 && nodeTotal != 16 && nodeTotal != 32);

    // 2D Vector to hold the nodes within a grid system
    Node** nodeGrid;
    nodeGrid = new Node *[nodeTotal];

    for(int x = 0; x < nodeTotal; x++)
    {

        nodeGrid[x] = new Node[nodeTotal];

    }

    // Based on how many nodes are selected create nodes in the grid
    // To keep the nodes far enough and spread out, break the grid into quadrants
    printNodes(nodeGrid, nodeTotal);


    return 0;

}



/*
    NOTES:
    - Build the graph based on default 80 character long width

*/



