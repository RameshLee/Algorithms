// C++ program for to solve Rod Cutting Problem using Dynamic Programming at O(rodsize*max_cuts-1) time complexity

#include <iostream>
using namespace std;

#define max(a,b) ((a) > (b) ? (a) : (b))

void find_optimal_cuts(int rodsize, int max_cuts, int cut_length[], int price[])
{
    // 1) initialization
    int DP[rodsize+1][max_cuts];
    for (int j=0; j<max_cuts; j++)
        for (int i=0; i<rodsize+1; i++)
            DP[i][j] = 0;

    // 2) for cut length = 1 (index at j=0)
    int j = 0; //cutlength
    for (int i=0; i<rodsize+1; i++) //rodsize
        DP[i][j] = i * price[j];


    // 2) optimally solve all the sub-problems
    for (int j=1; j<max_cuts; j++) //rodsize
        for (int i=1; i<rodsize+1; i++) //cutlength
        {
            int second_part = 0;
            if ((j+1) <= i) // cut length <= rod size
                second_part = price[j] + DP[i - (j+1)][j];
            DP[i][j] = max(DP[i][j-1], second_part); //max(price without this cut, price[cut] + optimal cut for remaining rod size)

                /*printf("DP[%d][%d]=max(%d, %d + %d)=%d\n", i, j, DP[i][j-1], price[j], DP[i - (j+1)][j], DP[i][j]);
                printf("second_part = %d\n", second_part);
                for (int i=0; i<rodsize+1; i++)
                {
                    for (int j=0; j<max_cuts; j++)
                        printf("%d ", DP[i][j]);
                    printf("\n");
                }
                printf("\n");*/

        }


    // 3) print DP table and output
    for (int i=0; i<rodsize+1; i++)
    {
        for (int j=0; j<max_cuts; j++)
            printf("%d ", DP[i][j]);
        printf("\n");
    }
    printf("Optimal rod cutting profit: %d\n", DP[rodsize][max_cuts-1]);

}

// Driver Code
int main()
{

   /* int rodsize = 5; //rod size
    int max_cuts = 4;
    int cut_length[] = {1,2,3,4};
    int price[] = {2,5,7,8};*/
    // optimality: 12

    int rodsize = 8; //rod size
    int max_cuts = 8;
    int cut_length[] = {1,2,3,4,5,6,7,8};
    int price[] = {1,5,8,9,10,17,17,20};
    // optimality: 12

    find_optimal_cuts(rodsize, max_cuts, cut_length, price);

    printf("Exiting program! \n\n");
    return 0;
}