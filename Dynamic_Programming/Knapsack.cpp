// C++ program for to solve 0/1 Knapsack problem without repetition using Dynamic Programming at O(n*C) time complexity

#include <iostream>
using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))

void Knapsack_DP(int n, int items[], int values[], int weights[], int capacity)
{
    // 1) initialization
    int DP[n+1][capacity+1];
    for (int j=0; j<capacity+1; j++)
        for (int i=0; i<n+1; i++)
            DP[i][j] = 0;

    // 2) optimally solve all the sub-problems
    for (int i=1; i<n+1; i++) //items
        for (int j=1; j<capacity+1; j++) //capacities
        {
            int second_part = 0;
            if (weights[i-1] <= j)
                second_part = values[i-1] + DP[i-1][j-weights[i-1]];
            DP[i][j] = max(DP[i-1][j], second_part);
        }

    // 3) print DP table and output
    for (int j=0; j<capacity+1; j++)
    {
        for (int i=0; i<n+1; i++)
            printf("%d ", DP[i][j]);
        printf("\n");
    }
    printf("Optimal knapsack value: %d\n", DP[n][capacity]);

}

// Driver Code 
int main()
{
    /*int n = 4;
    int items[] = {1,2,3,4};
    int values[] = {3,4,5,9};
    int weights[] = {2,1,4,3};
    int capacity = 5;*/
    // Ans: 13

    int n = 3;
    int items[] = {1,2,3};
    int values[] = {10,15,40};
    int weights[] = {1,2,3};
    int capacity = 6;
    // Ans: 65

    Knapsack_DP(n, items, values, weights, capacity);

    printf("Exiting program! \n\n");
    return 0; 
} 