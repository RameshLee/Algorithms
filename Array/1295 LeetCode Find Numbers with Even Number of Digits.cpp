// Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

// 1) without using string

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto& it:nums){
            int digits = 0;
            while (it>0){
                it = it/10; digits++;
            }
            if (digits%2 == 0) count++;
        }
        return count;
    }
};

// 2) using string
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (auto& it:nums){
            string s=to_string(it);
            if (s.size()%2 == 0) count++;
        }
        return count;
    }
};