#include <cstdlib>
#include <iostream>
#include <vector>
#include "Node.h"

int main()
{

    int nodeTotal = 0;

    std::cout << "Input the number of nodes in this system" << std::endl;
    std::cin >> nodeTotal;

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

    return 0;

}



