//
//  OrderedList.h
//  Project 1
//
//  Created by Eric Hyson on 2/8/19.
//  Copyright © 2019 Eric Hyson. All rights reserved.
//

#ifndef OrderedList_h
#define OrderedList_h

#include <iostream>
#include <string>
#include <iomanip>
#include "Timer.h"

using namespace std;


class OrderedList{

public:
    OrderedList( int size, int copyArray[]);
    ~OrderedList();
    
    void merge( int mergeArray[], int left, int middle, int right );
    void mergeSort( int copyArray[], int left, int right );
    
    bool empty();
    bool search( int query );
    
    double mergeTime;

private:
    int size;
    int *array;
    
    
    
};


/*****************************************************************************
 *                            constructors                                   *
 ****************************************************************************/

OrderedList::OrderedList( int size, int copyArray[] )
{
    this->size = size;
    array = new int[size];
    
    for( int i = 0; i < size; i ++ )
    {
        array[i] = copyArray[i];
    }
    
    Timer timer = Timer();
    timer.setStart( clock() );
    mergeSort( array, 0, size-1 );
    timer.setEnd( clock() );
    mergeTime = timer.getElapsed();
    
}




/****************************************************************************
 *                            public methods                                *
 ****************************************************************************/
bool OrderedList::empty()
{
    if( size == 0 )
        return true;
    else
        return false;
}





bool OrderedList::search( int query )
{
    bool found = false;
    
    int first = 0;
    int last = this->size-1;
    int middle = 0;
    
    while( first <= last && !found )
    {
        middle = (first+last)/2;
        
        if( this->array[middle] == query )
        {
            return true;
        }
        else if( this->array[middle] > query )
        {
            last = middle-1;
        }
        else
        {
            first = middle+1;
        }
    }
    
    return found;

}



/****************************************************************************
 *                            private methods                               *
 ****************************************************************************/

void OrderedList::mergeSort( int copyArray[], int left, int right )
{
    if( left < right )
    {
        int middle = left + (right-left)/2;
        
        mergeSort( copyArray, left, middle );
        mergeSort( copyArray, middle+1, right );
        merge( copyArray, left, middle, right );
    }
}


void OrderedList::merge( int mergeArray[], int left, int middle, int right )
{
    int size1 = middle - left + 1;
    int size2 = right - middle;
    
    int temp1[size1];
    int temp2[size2];
    
    int i = 0;
    int j = 0;
    int k = left;
    
    
    for( i = 0; i < size1; i++ )
    {
        temp1[i] = mergeArray[left+i];
    }
    for( j = 0; j < size2; j++ )
    {
        temp2[j] = mergeArray[middle + j + 1];
    }
    
    
    while( i < size1 && j < size2 )
    {
        if( temp1[i] <= temp2[j] )
        {
            mergeArray[k++] = temp1[i++];
        }
        else
        {
            mergeArray[k++] = temp2[j++];
        }
    }
    
    
    while( i < size1 )
    {
        mergeArray[k++] = temp1[i++];
    }
    
    while( j < size2 )
    {
        mergeArray[k++] = temp2[j++];
    }
    
}






/*****************************************************************************
 *                            destructors                                   *
 ****************************************************************************/

OrderedList::~OrderedList()
{
    size = 0;
    delete [] array;
}





#endif /* OrderedList_h */
