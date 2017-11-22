#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include "Node.h"


void printNodes(Node **array, int size)
{

    std::ofstream outputFile;

    outputFile.open("output.txt", std::ios_base::app);

    std::cout << "---------------------------------------------------" << std::endl;
    outputFile << "-----------------------NEW PRINT NODE STATUS OUTPUT---------------------" << std::endl;

    for(int x = 0; x < size; x++)
    {
        for(int y = 0; y < size; y++)
        {

            outputFile << array[x][y].printNodeFile() << std::endl;

        }

    }

    for(int x = 0; x < size; x++)
    {
        for(int y = 0; y < size; y++)
        {
            std::cout << "| ";
            std::cout << array[x][y].printNodeScreen();

        }

        std::cout << " |" << std::endl;

    }


}

bool takenPosition(Node **array, int posX, int posY)
{

    if(array[posX][posY].isActive())
    {

        return true;

    }

    return false;

}

int main()
{

    srand(time(NULL));

    // Delete old output file
    if( remove( "output.txt" ) != 0 )
    {

        std::cout << "Output file does not exist yet, no need to delete" << std::endl;

    }else
    {

        std::cout << "Successfully deleted ouput file" << std::endl;

    }
    


    // Initialize User Input Parameters
    int nodeTotal = 0;
    do
    {
        std::cout << "Choose the total number of nodes from the options (8, 16, 32) : ";
        std::cin >> nodeTotal;

    }while(nodeTotal != 8 && nodeTotal != 16 && nodeTotal != 32);

    // 2D Pointer Array Implementation Below 
    Node** nodeGrid;
    nodeGrid = new Node *[nodeTotal];

    for(int x = 0; x < nodeTotal; x++)
    {

        nodeGrid[x] = new Node[nodeTotal];

    }

    // Activate nodeTotal amount of position in the array
    int holdRandX;
    int holdRandY;
    for(int x = 0; x < nodeTotal; x++)
    {

        do
        {
            holdRandX = rand()%nodeTotal;
            holdRandY = rand()%nodeTotal;
        }while(takenPosition(nodeGrid, holdRandX, holdRandY));

        // activate said node
        nodeGrid[holdRandX][holdRandY].activateNode(holdRandX, holdRandY);


    }

    // Give neighbors to each active node
    int xDif;
    int yDif;
    for(int x = 0; x < nodeTotal; x++)
    {
        for(int y = 0; y < nodeTotal; y++)
        {

            if(nodeGrid[x][y].isActive())
            {

                // Check active nodes to see if they are a neighbor
                for(int a = 0; a < nodeTotal; a++)
                {

                    for(int b = 0; b < nodeTotal; b++)
                    {

                        if(nodeGrid[a][b].isActive())
                        {

                            if(x == a && y == b)
                            {

                                // do nothing, self

                            }else
                            {

                                // check if within distance
                                xDif = x - a;
                                yDif = y - b;

                                if(xDif < 0)
                                {
                                    // change to positive
                                    xDif *= -1;
                                }

                                if(yDif < 0)
                                {
                                    // change to positive
                                    yDif *= -1;
                                }

                                if((xDif+yDif) <= (nodeTotal/2))
                                {

                                    // make a,b node a neighbor of x,y node
                                    nodeGrid[x][y].addNeighbor(a,b);

                                }

                            }
                            

                        }

                    }

                }

            }

        }
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



