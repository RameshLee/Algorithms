// Link: https://leetcode.com/contest/weekly-contest-285/problems/count-hills-and-valleys-in-an-array/

class Solution {
public:
    int countHillValley(vector<int>& nums) {

        vector<int> arr;
        if (nums.size() < 1) return 0;

        arr.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++){
            if (arr[arr.size()-1] != nums[i])
                arr.push_back(nums[i]);
        }
        //for (auto& it:arr) printf("%d ", it);

        int count = 0;
        for (int i=1; i<arr.size()-1; i++){
            if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) count++;
            else if (arr[i-1] > arr[i] && arr[i] < arr[i+1]) count++;
        }

        return count;
    }
};