

#include "main.h"

using namespace std;


int main(int argc, const char * argv[])
{

    int *inputArray = nullptr;
    int *queryArray = nullptr;

    int listSize = 0;
    int querySize = 0;
    
    Timer orderedTimer = Timer();
    Timer MTFTimer = Timer();
    
    double totalOrderedTime = 0;
    double MTFTime = 0;
    

    //Open File
    string file = argv[1];
    ifstream inFile;
    inFile.open(file.c_str());
    
    if ( !inFile )
        throw invalid_argument("ERROR: Data file failed to open.");
    



    //Read in size
    inFile >> listSize;
    inputArray = new int[listSize];

    //Add all elements to inputArray
    for (int i = 0; i < listSize; i++)
    {
        int add = 0;
        inFile >> add;
        inputArray[i] = add;
    }

    //Read in query size
    inFile >> querySize;
    queryArray =new int[querySize];

    //Add all elements to queryArray
    for (int i = 0; i < querySize; i++)
    {
        int add;
        inFile>> add;
        queryArray[i] = add;
    }

    inFile.close();



    
    
    
    //Create Ordered List
    OrderedList list1(listSize, inputArray);

    //Record time for all queries
    orderedTimer.setStart( clock() );
    for (int i = 0; i < querySize; i++)
    {
        list1.search(queryArray[i]);
    }
    orderedTimer.setEnd( clock() );
    
    
    
    
    
    totalOrderedTime = (list1.mergeTime + orderedTimer.getElapsed());
    cout << "Time to sort and search with OrderedList:" << endl  << totalOrderedTime << " sec." << endl;
    

    //Create MTF List
    MTFList list2(listSize, inputArray);
    
    
    //Record time for all queries
    MTFTimer.setStart(clock());
    for (int i = 0; i < querySize; i++)
    {
        list2.search(queryArray[i]);
    }
    MTFTimer.setEnd(clock());
    

    
    
    
    cout << endl;
    cout << "Time to search with MTFList:" << endl << MTFTimer.getElapsed() << " sec." << endl << endl;
    
    MTFTime = MTFTimer.getElapsed();
    
    if (totalOrderedTime > MTFTime)
    {
        cout << "MTFList search faster by " << totalOrderedTime - MTFTime  << " seconds" <<
        endl << endl;
    }
    else if (totalOrderedTime < MTFTime)
    {
        cout << "OrderedList searched faster by " << MTFTime - totalOrderedTime << " seconds" <<
        endl << endl;
    }
    else
    {
        cout << "OrderedList and MTFList searches took the same amount of time." << endl << endl;
    }
   
    

}
