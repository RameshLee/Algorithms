// Link: https://leetcode.com/problems/4sum/


// 1) Using 3Sum function and 2-pointer approach on 2sum Function

class Solution {
private: set<vector<int>> output; int n,first,second;
public:
    void twoSum(vector<int> &nums, int l, int r, int target2){ // 2-pointer approach

        while(l<r){
            int sum = nums[l]+nums[r];
            if(sum == target2) {
                vector<int> combo = {first,second,nums[l],nums[r]};
                sort(combo.begin(), combo.end());
                output.insert(combo);
            }
            if(sum < target2) l++;
            else r--;
        }
    }

    void threeSum(vector<int>& nums, int index, int target3) {
        for(int i=index; i<n-2; i++){
            second = nums[i];
            twoSum(nums, i+1, n-1, target3-second);
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        n = nums.size();
        sort(nums.begin(),nums.end()); // sorting is essential to apply 2-pointers appraoch

        for (int i=0; i<n-2; i++){
            if (i>0 && nums[i] == nums[i-1]) continue; // duplicates
            first = nums[i];
            threeSum(nums, i+1, target-first);
        }
        return vector<vector<int>>(output.begin(), output.end());
    }
};