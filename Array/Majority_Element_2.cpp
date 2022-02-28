// C++ program for to solve Majority Element II using unordered_map STL Data Structure at O(n) time complexity

//Problem statement: Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
//For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
// Link: https://leetcode.com/problems/majority-element-ii/

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        unordered_map<int,int> mymap;
        vector<int> output;

        // 1) add elements and adjust counts in the map
        for (auto elem:nums) //O(n)
        {
            //printf("Hello World, %d\n", elem);
              unordered_map<int,int>::const_iterator got = mymap.find(elem);
              if (got == mymap.end()) //not-found
                mymap.insert({elem,1});
              else
                mymap.at(elem) += 1;
        }

        // 2) check elements with counts higher than required
        for (auto x:mymap)
            if ( x.second > floor(nums.size()/3) )
                output.push_back(x.first);

        // print utility
        int i =0;
        for (auto elem:output)
        {
             printf("output[%d]=%d\n", i, elem);
             i++;
        }




        return output;

    }
};

int main()
{
    Solution S;
    vector<int> vec{3,2,3,3,3,3,3};

    vector<int> final;
    final = S.majorityElement(vec);

    printf("\nExited the program!\n");
    return 0;
}