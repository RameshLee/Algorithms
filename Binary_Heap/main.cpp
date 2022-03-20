// C++ program for building Heap from Array 

#include <iostream>
#include <vector>
using namespace std;

#include "heap.h"

// Driver Code 
int main() 
{ 
    // Sample array
    int arr[] = { 7,7,7,7,7,7};//7,5,1,4,8,2};//1, 5, 6, 8, 9, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    maxHeap h(n, arr);
    h.print();
    h.buildHeap();
    h.print();
    //h.deleteRoot();
    //h.insertNode(11);
    //h.deleteNode(5);
    //h.deleteNode(11);

    h.peek();
    h.nums[0] = 3;
    h.deleteRoot();

    h.insertNode(3);
    h.print();
    return 0; 
} 
