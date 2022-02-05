// C++ program for Merge Sort using Queue

#include <iostream>
#include <vector>
using namespace std;
#include "merge_sort.h"

// Driver Code 
int main() 
{

    int arr[] = {0, 9, 6, 4, 1, 4, 22, 17, 3, 7, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    MergeSort MS;
    MS.fill_input(size, arr);
    MS.queue.print();
    MS.merge_sort();
    MS.queue.print();

    printf("Exiting program! \n\n");
    return 0; 
} 
