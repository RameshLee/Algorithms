// C++ program for building Heap from Array

#include <iostream>
#include <vector>
using namespace std;

#include "heap.h"

// Driver Code
int main()
{
    // Sample array
    int arr[] = { 7,5,1,4,8,2,9,10,12};//1, 5, 6, 8, 9, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 1) build heap: O(n)
    maxHeap h(n, arr);
    h.buildHeap();
    h.print();

    // 2) extract max element for k times: O(k * log(n))
    int k = 3;
    for (int i=0; i<k; i++)
    {
        h.peek();
        h.deleteRoot();
    }

    // total complexity = O(n + k*log(n))

    return 0;
}
