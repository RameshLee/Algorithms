// Link: https://leetcode.com/problems/3sum/

// 1) Two Pointers approach

class Solution {
public:
    using vvi = vector<vector<int>>;
    using svi = set<vector<int>>;
    using vi = vector<int>;
    vvi threeSum(vi& nums) {

        svi output;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0; i<n-2; i++){ // Fix the first ele & apply 2-pointer approach to find the other two elements

            if(i > 0 && nums[i] == nums[i - 1])  continue; //checking for duplicate i's

            int first = nums[i];
            int l=i+1;
            int r=n-1;

            while(l<r){ // Two-pointer approach to find second and third elements
                int sum=first+nums[l]+nums[r];
                if(sum == 0) {
                    vi combo = {first,nums[l],nums[r]};
                    sort(combo.begin(), combo.end());
                    output.insert(combo);
                }
                if(sum < 0) l++;
                else r--;
            }
        }
        return vvi(output.begin(), output.end());;
    }
};


// 2) using HashMap

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
