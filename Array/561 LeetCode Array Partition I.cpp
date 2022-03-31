// Link: https://leetcode.com/problems/array-partition-i/

// 1) Using built-in sort (preferred)

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i=0; i<nums.size(); i += 2){
            sum += nums[i];
        }
        return sum;
    }
};

// 2) priority queue

/*class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int sum = 0;
        while (!pq.empty()){
            sum +=  pq.top(); pq.pop(); pq.pop();
        }
        return sum;
    }
};*/