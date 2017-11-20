#include <cstdlib>
#include <iostream>
#include <vector>
#include "Node.h"

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
    Node* nodeGrid[nodeTotal][nodeTotal];

    // Set all nodes to NULL for prep
    for(int x = 0; x < nodeTotal; x++)
    {
        for(int y = 0; y < nodeTotal; y++)
        {

            nodeGrid[x][y] = NULL;

        }
    }

    // Based on how many nodes are selected create nodes in the grid
    // To keep the nodes far enough and spread out, break the grid into quadrants


    return 0;

}



