// Link: https://leetcode.com/problems/3sum/

// 1) 3Sum using two-pointer approach on 2Sum function

class Solution {
private:  using vvi = vector<vector<int>>; using vi = vector<int>; set<vector<int>> output;
public:
    void twoSum(vi &nums, int l, int r, int first){ // 2-pointer approach
        while(l<r){
            int sum = first+nums[l]+nums[r];
            if(sum == 0) {
                vi combo = {first,nums[l],nums[r]};
                sort(combo.begin(), combo.end());
                output.insert(combo);
            }
            if(sum < 0) l++;
            else r--;
        }
    }

    vvi threeSum(vi& nums) {

        int n=nums.size();
        sort(nums.begin(),nums.end()); // sorting is essential to apply 2-pointers appraoch

        for(int i=0; i<n-2; i++){ // Fix the 1st ele & apply 2-pointer approach to find other 2
            if (i>0 && nums[i] == nums[i-1]) continue; //check for duplicate i's
            twoSum(nums, i+1, n-1, nums[i]);
        }
        return vvi(output.begin(), output.end());;
    }
};


// 2) using hashmaps

class Solution {
public:
    using vvi = vector<vector<int>>;
    using svi = set<vector<int>>;
    using vi = vector<int>;
    using us = unordered_set<int>;
    using um = unordered_map<int,int>;
    vvi threeSum(vi& nums) {

        svi output;
        us dups;
        um Map;

        for (int i=0; i<nums.size(); i++){
            if (dups.insert(nums[i]).second){
                for (int j=i+1; j<nums.size(); j++){
                    int third = (-1)*(nums[i]+nums[j]);
                    auto it = Map.find(third);

                     if (it != end(Map) && it->second == i) {
                        vi combo = {nums[i],nums[j],third};
                        sort(combo.begin(), combo.end());
                        output.insert(combo);
                    }
                    Map[nums[j]] = i;
                }
            }
        }

        return vvi(output.begin(), output.end());;
    }
};