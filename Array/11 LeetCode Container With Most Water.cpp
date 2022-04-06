// Link: https://leetcode.com/problems/container-with-most-water/

// Two-pointer approach : T=O(n), S=O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {

        int l=0, r=height.size()-1, ret = 0;
        while (l<=r){
            int length = min(height[l],height[r]);
            int width = r-l;
            ret = max(ret, width*length);

            if (height[l] < height[r]) l++;
            else r--;
        }
        return ret;
    }
};