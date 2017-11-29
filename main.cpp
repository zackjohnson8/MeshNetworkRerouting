#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include "Node.h"

const int nodeTotal = 16; // Number of nodes in the program

void printNodes(Node **array)
{

    std::ofstream outputFile;

    outputFile.open("output.txt", std::ios_base::app);

    std::cout << "---------------------------------------------------" << std::endl;
    outputFile << "-----------------------NEW PRINT NODE STATUS OUTPUT---------------------" << std::endl;

    for(int x = 0; x < nodeTotal; x++)
    {
        for(int y = 0; y < nodeTotal; y++)
        {

            outputFile << array[x][y].printNodeFile() << std::endl;

        }

    }

    for(int x = 0; x < nodeTotal; x++)
    {
        for(int y = 0; y < nodeTotal; y++)
        {
            std::cout << "| ";
            std::cout << array[x][y].printNodeScreen();

        }

        std::cout << " |" << std::endl;

    }


}

// Hard code neighbor position
void setNeighbors(Node **array)
{

    // Node 1
    array[0][0].addNeighbor(&array[0][3]);
    array[0][0].addNeighbor(&array[3][0]);

    // Node 2
    array[0][3].addNeighbor(&array[0][0]);
    array[0][3].addNeighbor(&array[3][3]);
    array[0][3].addNeighbor(&array[2][8]);

    // Node 3
    array[3][0].addNeighbor(&array[0][0]);
    array[3][0].addNeighbor(&array[3][3]);

    // Node 4
    array[3][3].addNeighbor(&array[0][3]);
    array[3][3].addNeighbor(&array[3][0]);
    array[3][3].addNeighbor(&array[8][3]);

    // Node 5
    array[2][8].addNeighbor(&array[0][3]);
    array[2][8].addNeighbor(&array[5][8]);
    array[2][8].addNeighbor(&array[0][13]);
    
    // Node 6
    array[0][13].addNeighbor(&array[2][8]);

    // Node 7 
    array[5][8].addNeighbor(&array[2][8]);
    array[5][8].addNeighbor(&array[7][6]);
    
    // Node 8
    array[7][6].addNeighbor(&array[5][8]);
    array[7][6].addNeighbor(&array[8][3]);
    array[7][6].addNeighbor(&array[10][9]);
    
    // Node 9
    array[8][3].addNeighbor(&array[3][3]);
    array[8][3].addNeighbor(&array[7][6]);
    array[8][3].addNeighbor(&array[12][5]);
    
    // Node 10
    array[12][5].addNeighbor(&array[8][3]);
    array[12][5].addNeighbor(&array[10][9]);
    
    // Node 11
    array[10][9].addNeighbor(&array[7][6]);
    array[10][9].addNeighbor(&array[12][5]);
    array[10][9].addNeighbor(&array[7][12]);

    // Node 12
    array[7][12].addNeighbor(&array[10][9]);
    array[7][12].addNeighbor(&array[11][14]);
    array[7][12].addNeighbor(&array[11][15]);
    
    // Node 13
    array[11][14].addNeighbor(&array[7][12]);
    array[11][14].addNeighbor(&array[14][11]);
    
    // Node 14
    array[11][15].addNeighbor(&array[7][12]);
    array[11][15].addNeighbor(&array[14][11]);
    
    // Node 15
    array[14][11].addNeighbor(&array[11][14]);
    array[14][11].addNeighbor(&array[11][15]);
    array[14][11].addNeighbor(&array[15][15]);
    
    // Node 16
    array[15][15].addNeighbor(&array[14][11]);


}

void activateNodes(Node **array)
{

    // Saying that position 0,0 in the grid should activate as a node.
    array[0][0].activateNode(0,0); // 1 and are labeled on hand drawn sheet
    array[0][3].activateNode(0,3); // 2
    array[3][0].activateNode(3,0); // 3
    array[3][3].activateNode(3,3); // 4
    array[2][8].activateNode(2,8); // 5
    array[0][13].activateNode(0,13); // 6
    array[5][8].activateNode(5,8); // 7
    array[7][6].activateNode(7,6); // 8
    array[8][3].activateNode(8,3); // 9
    array[12][5].activateNode(12,5); // 10
    array[10][9].activateNode(10,9); // 11
    array[7][12].activateNode(7,12); // 12
    array[11][14].activateNode(11,14); // 13
    array[11][15].activateNode(11,15); // 14
    array[14][11].activateNode(14,11); // 15
    array[15][15].activateNode(15,15); // 16

}



int main()
{


    // Delete old output file from previous run
    if( remove( "output.txt" ) != 0 )
    {

        std::cout << "Output file does not exist yet, no need to delete" << std::endl;

    }else
    {

        std::cout << "Successfully deleted ouput file" << std::endl;

    }

    // 2D Pointer Array Implementation Below 
    Node** nodeGrid;
    nodeGrid = new Node *[nodeTotal];

    for(int x = 0; x < nodeTotal; x++)
    {

        nodeGrid[x] = new Node[nodeTotal];

    }

    // Activate nodeTotal amount of position in the array
    activateNodes(nodeGrid);

    // Give neighbors to each active node
    setNeighbors(nodeGrid);

    nodeGrid[0][0].deliverPackage(&nodeGrid[15][15]);

    // Based on how many nodes are selected create nodes in the grid
    // To keep the nodes far enough and spread out, break the grid into quadrants
    printNodes(nodeGrid);


    return 0;

}



/*
    NOTES:
    - Build the graph based on default 80 character long width

*/



