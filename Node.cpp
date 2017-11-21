#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

// CONSTRUCTOR/DESTRUCTOR 

Node::Node()
{

    activeNode = false;

}

Node::~Node()
{


}

const std::string Node::printNode()
{

    if(activeNode)
    {

        return "N";

    }

    return std::string();

}


#endif

