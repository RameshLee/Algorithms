// C++ program for building Heap from Array 

#include <iostream>
#include <vector>
using namespace std;

#include "heap.h"

// Driver Code 
int main() 
{ 
    // Sample array
    int arr[] = { 7,5,1,4,8,2};//1, 5, 6, 8, 9, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap h(n, arr);
    h.print();
    h.buildHeap(1);
    h.print();
    h.deleteRoot();
    h.insertNode(11);

    return 0; 
} 
