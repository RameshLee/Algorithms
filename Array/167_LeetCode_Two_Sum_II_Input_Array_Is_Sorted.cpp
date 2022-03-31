// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// 1) Two-pointers approach: T=O(n), S=O(1) --> VALID ONLY IF ARRAY IS SORTED!

class Solution {
public:
    vector<int> twoSum(vector<int>& vec, int target)
    {
        int l=0, h=vec.size()-1;
        while (l<h){
            int sum = vec[l]+vec[h];
            if (sum == target) return vector<int>({l+1,h+1});
            else if (sum<target) l++;
            else h--;
        }
        return vector<int>();
    }
};

// 2) Using HashMap: T=O(n), S=O(n) --> GENERIC!

class Solution {
public:
    vector<int> twoSum(vector<int>& vec, int target) {

        unordered_map<int,int> Map;

        for (int i=0; i<vec.size(); i++){
            if (Map.find(target-vec[i]) != Map.end()){
                return vector<int>({ Map[target-vec[i]], i+1 });
            }
            Map[vec[i]] = i+1;
        }
        return vector<int>();
    }
};