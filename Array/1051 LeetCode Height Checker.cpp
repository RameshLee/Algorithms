// Link: https://leetcode.com/problems/height-checker/

// 1) Using non-comparative sort: T=O(N), S=O(1) ==> (100% faster and 100% efficient)
// Use the logic of counting sort since total height is limited up to 101.

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int counter[101] = {0};
        for (auto& it:heights) counter[it]++;

        int k = 0, difference = 0;
        for (int i=0; i<=100; i++){
            if (counter[i] != 0)
                for (int times=0; times<counter[i]; times++){
                    if (heights[k] != i) difference++;
                    if (++k >= heights.size()) return difference;
                }
        }
        return difference;
    }
};

// 2) Using comparative sort: T=O(N*logN), S=O(N)
// sort two vectors and compare the values

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> vec = heights;
        sort(vec.begin(), vec.end());

        int count = 0;
        for (int i=0; i<vec.size(); i++){
            if (vec[i] != heights[i])
                count++;
        }
        return count;
    }
};
