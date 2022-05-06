// C++ program for building Heap from Array

#include <iostream>
#include <vector>
using namespace std;

#include "heap.h"

// Driver Code
int main()
{
    // Sample array
    int arr1[] = { 5,4,3,2};
    int arr2[] = { 8,7,6,1};
    int arr3[] = { 12,11,10,9};

    int total = 3;

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    int total_size = n1 + n2 + n3;

    // 1) put first element of each array for building a heap

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
