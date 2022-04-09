// Link: https://leetcode.com/problems/maximum-units-on-a-truck/

class cmp{
public:
    bool operator()(vector<int>& v1, vector<int>& v2){
        return v1[1]>v2[1];
    }
};

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(), cmp());
        int items=0, val=0;
        for (auto& it:boxTypes){
            for (int j=0; j<it[0]; j++){
                val += it[1];
                if (++items == truckSize) return val;
            }
        }
        return val;
    }
};