// ============================================================================
// File: mergesort.cpp (Spring 2018)
// ============================================================================
// Programmer: Jennifer King
// Project: MergeInts
// Date: 4/16/2018
// Professor: Scott Edwards
// Class: CSCI 133F | TR 9:30AM
// This program uses the "mergesort" algorithm to sort a dynamically allocated
// array of ints filled with random values into ascending order.
// ============================================================================

#include    <iostream>
#include    <cstring>
#include    <iomanip>
using namespace std;


// field width for displaying the ints
const   int         FIELD_WIDTH = 12;


// function prototypes
void    MergeSort(int  array[], int  first, int  last);
void    MergeArrays(int  array[], int  first, int  middle, int  last);


// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    char        temp;
    int         index;
    int         *arrayPtr;
    int         numInts;

    // start the random number generator
    srand(time(NULL));

    // ask user how many ints to sort, allocate an array and fill it with
    // random values
    cout << "How many ints would you like to sort? ";
    if (!(cin >> numInts))
        {
        cout << "Error reading the integer value..." << endl;
        exit(EXIT_FAILURE);
        }
    else if (numInts <= 0)
        {
        cout << "C'mon, give me something to work with here..." << endl;
        exit(EXIT_FAILURE);
        }

    arrayPtr = new int[numInts];
    for (index = 0; index < numInts; ++index)
        {
        arrayPtr[index] = rand();
        }

    // display the contents of the array before the sort
    cout << "Before mergesort:\n";
    for (index = 0; index < numInts; ++index)
        {
        cout << setw(FIELD_WIDTH) << arrayPtr[index] << endl;
        }

    // sort the array
    cout << "Press the 'Enter' key to sort the array...";
    cin.get(temp);
    cin.get(temp);
    MergeSort(arrayPtr, 0, numInts - 1);

    // display the results
    cout << "\nAfter mergesort:\n";
    for (index = 0; index < numInts; ++index)
        {
        cout << setw(FIELD_WIDTH) << arrayPtr[index] << endl;
        }

    delete []arrayPtr;
    return  0;

}  // end of "main"



// ==== MergeSort =============================================================
//
// This function uses the mergesort algorithm to sort the array of integers.
//
// Input:
//      array [IN/OUT]  -- the base address of the array of integers
//
//      first [IN]      -- the index of the first element in the array parameter
//
//      last [IN]       -- the index of the last element in the array parameter
//
// Output:
//      Nothing
//
// ============================================================================

void    MergeSort(int  array[], int  first, int  last)
{
    int mid;
    if(first < last)
    {
        mid = (first + last)/2;
        MergeSort(array, first, mid);
        MergeSort(array, mid+1, last);
        MergeArrays(array, first, mid, last);
    }
}  // end of "MergeSort"



// ==== MergeArrays ===========================================================
//
// This function uses the index parameters to process the array parameter as if
// it were split into two halves.  The "left" half begins with index value
// "first", and ends with index "middle".  The "right" half begins with
// "middle + 1" and ends with "last".  The array parameter contains the base
// address of an array of integers. The ints in the two subarrays are compared
// and merged into a local array in ascending order. After the merge has
// completed, the local array is copied back to the array parameter.
//
// Input:
//      array [IN/OUT]  -- the base address of the array of ints
//
//      first [IN]      -- the index of the first element in the "left" half
//                         array parameter
//
//      middle [IN]     -- the index of the last element in the "left" half of
//                         array parameter
//
//      last [IN]       -- the index of the last element in the "right" half
//                         of the array parameter
//
// Output:
//      Nothing
//
// ============================================================================

void    MergeArrays(int  array[], int  first, int  middle, int  last)
{
    int temp[last];
    for(int i = first; i <= last; i++)
    {
        temp[i] = array[i];
    }

    int i = first;
    int j = middle + 1;
    int k = first;

    while(i <= middle && j <= last)
    {
        if(temp[i] <= temp[j])
        {
            array[k++] = temp[i++];
        }
        else
        {
            array[k++] = temp[j++];
        }
    }

    while(i <= middle)
    {
        array[k++] = temp[i++];
    }
    while(j <= last)
    {
        array[k++] = temp[j++];
    }


}  // end of "MergeArrays"
