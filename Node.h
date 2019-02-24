//
//  Node.h
//  Project 1
//
//  Created by Eric Hyson on 2/8/19.
//  Copyright © 2019 Eric Hyson. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <iostream>
#include <iomanip>

using namespace std;

class Node{
    
public:
    int value;
    Node *next;
    Node( int info, Node* ptr );
};





/*****************************************************************************
 *                            constructors                                   *
 ****************************************************************************/
Node::Node( int info, Node* ptr)
{
    value = info;
    next = ptr;
}



#endif /* Node_h */
