//
//  MTFList.h
//  Project 1
//
//  Created by Eric Hyson on 2/8/19.
//  Copyright © 2019 Eric Hyson. All rights reserved.
//

#ifndef MTFList_h
#define MTFList_h

#include <iostream>
#include <iomanip>
#include "Node.h"


class MTFList{
    
public:
    MTFList(int sz, int array[]);
    ~MTFList();
    
    void addFront(int value);
    void addBack(int value);
    void remove( unsigned index );
    
    int& at(unsigned long index) const;
    bool empty() const;
    void clear();
    
    bool search( int query );
    

private:
    int size;
    Node *frontPtr = nullptr;
    
};



/*****************************************************************************
 *                            constructors                                   *
 ****************************************************************************/

MTFList::MTFList(int sz, int array[])
{
    this->size = sz;
    
    for( int i = 0; i < sz; i++ )
    {
        addBack( array[i] );
    }
}



/****************************************************************************
 *                            public methods                                *
 ****************************************************************************/

bool MTFList::search( int query )
{
    bool found = false;
    
    for( int i = 0; i < size; i ++ )
    {
        if( at(i) == query )
        {
            found = true;
            remove(i);
            addFront(query);
            break;
        }
    }
    
    return found;
}

void MTFList::addFront( int value )
{
    if (frontPtr == nullptr)
    {
        frontPtr = new Node(value, nullptr);
        size++;
    }
    else
    {
        Node *n = new Node(value, frontPtr);
        frontPtr = n;
    }
}





void MTFList::addBack( int value )
{
    if( frontPtr == nullptr )
    {
        frontPtr = new Node( value, nullptr );
    }
    else
    {
        Node *current = frontPtr;
        while( current->next != nullptr )
        {
            current = current->next;
        }
        
        current->next = new Node( value, nullptr );
    }
    
}





void MTFList::remove( unsigned index )
{
    if( index > static_cast<unsigned long>(size) || empty() )
        throw out_of_range("An Error occured while removing node");
    
    Node *current = frontPtr;
    Node *trail = frontPtr;
    
    if( index == 0 )
    {
        frontPtr = trail->next;
        delete trail;
    }
    else
    {
        current = current->next;
        
        for( unsigned long i = 0; i < index-1; i++ )
        {
            current = current->next;
            trail = trail->next;
        }
        
        trail->next = current->next;
        delete current;
    }
    
    size--;
}





int& MTFList::at( unsigned long index ) const
{
    if( index > static_cast<unsigned long>(size) || empty() )
        throw out_of_range("An Error occured while removing node");
    
    Node *current = frontPtr;
 
    for( unsigned long i = 0; i < index; i++ )
    {
        current = current->next;
    }
    
    return current->value;
}





bool MTFList::empty() const
{
    if( frontPtr == nullptr )
        return true;
    else
        return false;
}





void MTFList::clear()
{
    Node *current = frontPtr;
    int delCount = 0;
    
    while( current != nullptr )
    {
        current = current->next;
        delete frontPtr;
        delCount++;
        size--;
        frontPtr = current;
    }
}




/*****************************************************************************
 *                            destructors                                   *
 ****************************************************************************/

MTFList::~MTFList()
{
    clear();
}







#endif /* MTFList_h */
