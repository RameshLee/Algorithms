// Link: https://leetcode.com/contest/weekly-contest-284/

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k)
    {
        vector<int> output;
        vector<int> vec;

        // 1) find indices (j) with key values
        for (int i=0; i<nums.size(); i++)
            if (nums[i] == key)
                vec.push_back(i);


        // 2) check all i wrt j indices for conditions
        for (int i=0; i<nums.size(); i++)
        {
             for (int j=0; j<vec.size(); j++)
                if (abs(i-vec[j]) <= k)
                {
                    output.push_back(i);
                    goto Jump;
                }
            Jump:{}
        }

        return output;
    }
};