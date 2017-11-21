#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{

public:

    // constructor/destructor
    Node();
    ~Node();
    const std::string printNode();

private:

    bool activeNode;

};


#endif