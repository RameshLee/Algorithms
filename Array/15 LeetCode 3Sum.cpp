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
