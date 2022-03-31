// Link: https://leetcode.com/problems/two-sum/

// Using HashMap: T=O(n), S=O(n) --> GENERIC!

class Solution {
public:
    vector<int> twoSum(vector<int>& vec, int target) {

        unordered_map<int,int> Map;

        for (int i=0; i<vec.size(); i++){
            if (Map.find(target-vec[i]) != Map.end()){
                return vector<int>({ Map[target-vec[i]], i });
            }
            Map[vec[i]] = i;
        }
        return vector<int>();
    }
};