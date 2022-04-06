// Link: https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& vec) {

        int i=0; int count = 0;
        while (1){

            if (i>=vec.size()) break;

            if (vec[i] % 2 == 0) {
                int temp = vec[i];
                vec.erase(vec.begin()+i);
                vec.insert(vec.begin(),temp);
            }
            i++;
        }
        return vec;
    }
};