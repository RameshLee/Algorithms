// Link: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> vec;

        //brute-force:
        /*for (int i=0; i<nums.size(); i++)
            for (int j=i+1; j<nums.size(); j++)
                if (nums[i]+nums[j] == target)
                    return vector<int>({i,j});*/

         //optimized: using hashmap
         unordered_map<int,int> Map;
         Map[nums[0]] = 0;

         for (int i=1; i<nums.size(); i++)
         {
             int otherNum = target-nums[i];
             if (Map.find(otherNum) != Map.end())
                 return vector<int>({Map[otherNum], i});

             Map[nums[i]] = i;
         }

        return vector<int>();
    }
};
