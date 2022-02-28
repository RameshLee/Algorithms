// C++ program for to find squares of sorted at O(n) time complexity

//Problem statement: https://leetcode.com/problems/squares-of-a-sorted-array/
#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            nums[0] = (nums[0]*nums[0]);
            return nums;
        }
        else
        {
            vector<int> output(nums.size());
            int output_index = 0;
            int pivot = 0;

            for (int i=0; i<nums.size(); i++) //O(n)
            {
                if (nums[i] < 0)
                {
                     nums[i] = (nums[i]*nums[i]);
                     pivot++;
                }
                else
                {
                    int square_nums = nums[i]*nums[i];
                    if (pivot == 0)
                        output[output_index++] = square_nums;
                    else if (pivot > 0 && nums[pivot-1] <= square_nums)
                    {
                        output[output_index++] = nums[pivot-1];
                        pivot--;
                        i -= 1;
                    }
                    else
                        output[output_index++] = square_nums;

                }

            }

            for (int i=pivot-1; i>=0; i--)
                output[output_index++] = (nums[i]);

            return output;
        }
    }
};

int main()
{
    Solution S;
    vector<int> vec{-7,-3,2,3,11};

    vector<int> final;
    final = S.sortedSquares(vec);

    printf("Sorted Squared Array: ");
    for (int i=0; i<final.size(); i++)
        printf("%d ", final[i]);

    printf("\nExited the program!\n");
    return 0;
}