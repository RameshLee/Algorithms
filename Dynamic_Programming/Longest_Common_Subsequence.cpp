// C++ program to find LCS using Dynamic Programming with O(n*m) complexity

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define max(a,b) (a>b? a:b)

void find_longest_common_subsequence(char a[], char b[])
{
    // memory allocation and initialization
    int DP_array[strlen(a) + 1][strlen(b) + 1];
    for (int i=0; i<strlen(a)+1; i++)
        for (int j=0; j<strlen(b)+1; j++)
            DP_array[i][j] = 0;

    // solve all the subproblems, i.e., fill the cells
    for (int i=1; i<strlen(a)+1; i++)
        for (int j=1; j<strlen(b)+1; j++)
        {
            // if both chars are same
            if (a[i-1] == b[j-1])
                DP_array[i][j] = DP_array[i-1][j-1] + 1;
            else
                DP_array[i][j] =  max(DP_array[i-1][j], DP_array[i][j-1]);
        }

    // print utility
    printf("DP array:\n");
    for (int j=0; j<strlen(b)+1; j++)
    {
        for (int i=0; i<strlen(a)+1; i++)
            printf("%d ", DP_array[i][j]);
        printf("\n");
    }
    printf("Longest Common Subsequence: %d\n", DP_array[strlen(a)][strlen(b)]);

}

// Driver Code 
int main()
{
    char a[100]; char b[100];
    printf("Enter the two words: \n");
    scanf("%s %s", a, b);

    find_longest_common_subsequence(a,b);

    printf("Exiting program! \n\n");
    return 0; 
} 
