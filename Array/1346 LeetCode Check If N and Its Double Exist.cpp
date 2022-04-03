// Link: https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<float,int> Map;
        for (auto& it:arr){
            if (Map.find((float)it/2) != Map.end()) return true;
            if (Map.find((float)it*2) != Map.end()) return true;
            Map[it]++;
        }
        return false;
    }
};