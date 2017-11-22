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

void setNeighbors(Node **array, int size)
{

    int xDif;
    int yDif;
    for(int x = 0; x < size; x++)
    {
        for(int y = 0; y < size; y++)
        {

            if(array[x][y].isActive())
            {

                // Check active nodes to see if they are a neighbor
                for(int a = 0; a < size; a++)
                {

                    for(int b = 0; b < size; b++)
                    {

                        if(array[a][b].isActive())
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

                                if((xDif+yDif) <= (size/2))
                                {

                                    // make a,b node a neighbor of x,y node
                                    array[x][y].addNeighbor(a,b);

                                }

                            }
                            

                        }

                    }

                }

            }

        }
    }

    // Check to see that all nodes have atleast one neighbor
    int holdX;
    int holdY;
    for(int x = 0; x < size; x++)
    {
        for(int y = 0; y < size; y++)
        {
            if(array[x][y].haveNeighbor())
            {

                // has atleast one neighbor

            }else
            {
                // doesn't have a neighbor, fix that.
                holdX = x;
                holdY = y;
                while(array[x][y].haveNeighbor())
                {

                    // TODO

                }

            }
        }

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

void activateNodes(Node **array, int size)
{

    int holdRandX;
    int holdRandY;
    for(int x = 0; x < size; x++)
    {

        do
        {
            holdRandX = rand()%size;
            holdRandY = rand()%size;
        }while(takenPosition(array, holdRandX, holdRandY));

        // activate said node
        array[holdRandX][holdRandY].activateNode(holdRandX, holdRandY);


    }

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
    activateNodes(nodeGrid, nodeTotal);

    // Give neighbors to each active node
    setNeighbors(nodeGrid, nodeTotal);

    // Based on how many nodes are selected create nodes in the grid
    // To keep the nodes far enough and spread out, break the grid into quadrants
    printNodes(nodeGrid, nodeTotal);


    return 0;

}



/*
    NOTES:
    - Build the graph based on default 80 character long width

*/



