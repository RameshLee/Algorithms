// Link: https://leetcode.com/problems/duplicate-zeros/

//T=O(n), S=O(1)

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        int i=0;
        while (1){
            if (i>=arr.size()) break;
            if (arr[i] == 0){
                arr.insert(arr.begin()+i, 0); i++;
                arr.pop_back();
            }
            i++;
        }
    }
};