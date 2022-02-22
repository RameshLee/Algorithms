// C++ program to find LIS using the LCS Dynamic Programming at O(n^2) time complexity

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

#include "../Sorting/merge_sort.h"

#define max(a,b) (a>b? a:b)

void find_longest_common_subsequence(int n, vector<int> a, vector<int> b)
{
    // memory allocation and initialization
    int DP[n + 1][n + 1];
    for (int i=0; i<n+1; i++)
        for (int j=0; j<n+1; j++)
            DP[i][j] = 0;

    // solve all the sub-problems
    for (int i=1; i<n+1; i++)
        for (int j=1; j<n+1; j++)
        {
            // if both chars are same
            if (a[i-1] == b[j-1])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] =  max(DP[i-1][j], DP[i][j-1]);
        }

    // print utility
    printf("DP array:\n");
    for (int j=0; j<n+1; j++)
    {
        for (int i=0; i<n+1; i++)
            printf("%d ", DP[i][j]);
        printf("\n");
    }
    printf("Longest Increasing Subsequence: %d\n", DP[n][n]);

}

// Driver Code 
int main()
{
    vector<int> a{1, 4, 2, 3, 1, 8}; // LIS of a is 4 -> {1,2,3,8}
    vector<int> b(a.begin(), a.end());

    // 1) sort the vector b in ascending order: O(n*log(n))
    int n = a.size();
    MergeSort MS;
    MS.fill_input(n, b);
    MS.queue.print();
    MS.merge_sort();
    MS.queue.print();
    b  = MS.queue.q[0];

    // 2) run the LCS routine on vectors a & b to find the LIS of a: O(n^2)
    find_longest_common_subsequence(n,a,b);

    printf("Exiting program! \n\n");
    return 0; 
} 
