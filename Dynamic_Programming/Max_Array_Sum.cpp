// C++ program to find Max Array Sum using Dynamic Programming with O(n) complexity

#include <iostream>
#include <vector>
using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))

// Problem statement: Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset. It is possible that the maximum sum is 0, the case when all elements are negative.

int find_max_array_sum(int arr[], int n)
{
        int DP[n];
        if(n==1)
            return arr[0];
        else if(n==2)
            return max(arr[0],arr[1]);
        else if(n==3)
        {
            DP[0]=arr[0];
            DP[1]=arr[1];
            DP[2]=arr[2]+arr[0];
            return max(DP[2],DP[0]);
        }
        else
        {
            DP[0]=max(0,arr[0]);
            DP[1]=max(0,arr[1]);
            DP[2]=max(0,arr[2])+max(0,arr[0]);
            for(int i=3;i<n;i++)
                DP[i]=max(0,arr[i])+max(DP[i-2],DP[i-3]);
            return max(DP[n-1],DP[n-2]);
        }
}

// Driver Code 
int main()
{
    int n = 5;
    int a[] = {3, 5, -7, 8, 10}; //Ans: 15
    int b[] = {3, 7, 4, 6, 5}; //Ans: 13
    int c[] = {-2, 1, 3, -4, 5}; //Ans: 8
    int d[] = {2, 1, 5, 8, 4}; //Ans: 11
    int e[] = {-2, -1, -5, -8, -4}; //Ans: 0

    printf("Max Array Sum: %d\n", find_max_array_sum(a, n));
    printf("Max Array Sum: %d\n", find_max_array_sum(b, n));
    printf("Max Array Sum: %d\n", find_max_array_sum(c, n));
    printf("Max Array Sum: %d\n", find_max_array_sum(d, n));
    printf("Max Array Sum: %d\n", find_max_array_sum(e, n));
    printf("Exiting program! \n\n");
    return 0; 
} 
