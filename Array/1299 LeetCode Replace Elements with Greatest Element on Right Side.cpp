// Link: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

// One-pass algorithm: T=O(n), S=O(1)

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        int ele = arr[arr.size()-1];
        for (int i=arr.size()-1; i>=0; i--){

            int tmp = arr[i];

            if (i == arr.size()-1)  arr[i] = -1;
            else                    arr[i] = ele;

            ele = max(ele,tmp);
        }
        return arr;
    }
};