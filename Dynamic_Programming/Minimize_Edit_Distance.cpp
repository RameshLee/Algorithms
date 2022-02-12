// C++ program to find Min Edit Distance using Dynamic Programming with O(n*m) complexity

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))


void find_edit_distance(char a[], char b[])
{
    // memory allocation and initialization
    int DP_array[strlen(a) + 1][strlen(b) + 1];
    for (int i=0; i<strlen(a)+1; i++)
        for (int j=0; j<strlen(b)+1; j++)
            DP_array[i][j] = 0;

    // 1) initialize the first row and column
    for (int i=0; i<strlen(a)+1; i++)
        DP_array[i][0] = i;
    for (int j=0; j<strlen(b)+1; j++)
        DP_array[0][j] = j;

    // 2) solve all other subproblems, i.e., fill other cells
    for (int j=1; j<strlen(b)+1; j++)
        for (int i=1; i<strlen(a)+1; i++)
        {
            // if both chars are same
            if (b[j-1] == a[i-1])
                DP_array[i][j] = DP_array[i-1][j-1];
            else
            {
                int deletion = 1 + DP_array[i-1][j]; // carry, bark, => carr, bark
                int replace = 1 + DP_array[i-1][j-1]; // carry, bark => carrk, bark
                int insertion = 1 + DP_array[i][j-1]; // carry, bark => carryk, bark

                DP_array[i][j] =  min(min(deletion, replace), insertion);
            }
        }

    // print utility
    printf("DP array:\n");
    for (int j=0; j<strlen(b)+1; j++)
    {
        for (int i=0; i<strlen(a)+1; i++)
            printf("%d ", DP_array[i][j]);
        printf("\n");
    }
    printf("Min_Edit_Distance: %d\n", DP_array[strlen(a)][strlen(b)]);

}

// Driver Code 
int main()
{
    char a[100]; char b[100];
    printf("Enter the two words: \n");
    scanf("%s %s", a, b);

    // carry, bark => ans:3
    // snowy, sunny => ans:3
    // exponential, polynomial => ans:6
    // range, rover => ans:4

    find_edit_distance(a,b);

    printf("Exiting program! \n\n");
    return 0; 
} 
