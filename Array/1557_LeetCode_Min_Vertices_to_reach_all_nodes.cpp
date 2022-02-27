// C++ program for to solve Majority Element II using unordered_map STL Data Structure at O(n) time complexity

//Problem statement: Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
//For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
// Link: https://leetcode.com/problems/majority-element-ii/

//Algo logic: Count the source nodes

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
    {

        int *count = new int[n];
        for (int i=0; i<n; i++)
            count[i] = 0;

        for (int i=0; i<edges.size(); i++)
            count[edges[i][1]]++;

        vector<int> output;
        for (int i=0; i<n; i++)
            if (count[i] == 0)
                output.push_back(i);

        delete[] count;
        return output;

    }
};

int main()
{
    int n = 6;
    vector< vector<int> > edges = {{0,1},{0,2},{2,5},{3,4},{4,2}};

    Solution S;
    vector<int> final;
    final = S.findSmallestSetOfVertices(n, edges);

    printf("\nExited the program!\n");
    return 0;
}