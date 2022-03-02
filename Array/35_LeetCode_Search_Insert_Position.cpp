// Link: https://leetcode.com/problems/binary-search/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        // corner-case
        if (nums.size() == 1)
        {
            if (target <= nums[0])
                return 0;
            else
                return 1;
        }
        if (nums[nums.size()-1] < target)
            return nums.size();
        if (target <= nums[0])
            return 0;



        // randomized binary search
        int LB = 0;
        int UB = nums.size();
        int pivot = rand()%(UB-LB) + LB;
        while (LB<UB)
        {
            //printf("%d, %d, %d\n", pivot,LB,UB);

            if (nums[pivot] == target)
                return pivot;
            else if (nums[pivot] < target)
            {
                LB = pivot;
                pivot = rand()%(UB-LB) + LB;
            }
            else
            {
                UB = pivot;
                pivot = rand()%(UB-LB) + LB;
            }

            if (abs(LB-UB) == 1)
                if (nums[LB] != target && nums[UB] != target)
                    return UB;
        }

        return pivot;
    }
};

int main()
{
    int target = 2;
    vector<int> vec = {1,3,5,6}; //sorted array

    Solution S;
    int index = S.searchInsert(vec, target);
    printf("Position: %d\n", index);

    printf("\nExited the program!\n");
    return 0;
}