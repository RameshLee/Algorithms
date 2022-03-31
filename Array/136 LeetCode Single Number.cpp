// Link: https://leetcode.com/problems/single-number/

// 1) using XOR: T=O(n), S=O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int a = 0;
        for (auto it:nums)
            a ^= it;
        return a;

    }
};



// 2) using hashmap: T=O(n), S=O(n)

/*class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int,int> Map;
        for (auto& it:nums) Map[it]++;
        for (auto it=Map.begin(); it!=Map.end(); it++){
            if ((*it).second == 1)
                return (*it).first;
        }
        return 0;
    }
};*/