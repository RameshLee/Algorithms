// Link: https://leetcode.com/problems/third-maximum-number/solution/

// 1) Using set: T=O(n), S=O(1) (Because, set holds const 3 items always)

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        set<int> Set;
        for (auto& it:nums){
            Set.insert(it);
            if (Set.size() > 3) Set.erase(Set.begin()); // delete the smallest ele in set
        }
        return Set.size() == 3 ? *Set.begin() : *Set.rbegin();
    }
};

// 2) Using priority queue: T = O(n), S=O(n)

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        priority_queue<int> pq(nums.begin(), nums.end()); // buildheap: O(n)

        int first = pq.top(), second = -INT_MAX, third = -INT_MAX;

        // get the second unique ele
        while (!pq.empty()){
            if (pq.top() != first) {
                second = pq.top(); pq.pop();
                break;
            }
            pq.pop();
        }

        // get the third unique ele
        while (!pq.empty()){
            if (pq.top() != second) {
                third = pq.top(); pq.pop();
                break;
            }
            pq.pop();
        }

        return (third == -INT_MAX) ? first : third;
    }
};