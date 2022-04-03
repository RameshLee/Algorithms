// Link: https://leetcode.com/problems/valid-mountain-array/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        int check = 1;
        bool foundIncrease = 0;
        bool foundDecrease = 0;
        for (int i=1; i<arr.size(); i++){
            switch (check){
                case 1: if (!foundIncrease && arr[i-1] >= arr[i]) return false; // downroad before the uproad.
                        if (arr[i-1] == arr[i]) return false; // flat road.
                        if (arr[i-1] > arr[i]) { // end of the uproad.
                            check = 2;
                            foundDecrease = true;
                        }
                        foundIncrease = true;
                        break;
                case 2: if (arr[i-1] <= arr[i]) return false; // flat or uproad.
                        break;
            }
        }

        if (foundDecrease && foundIncrease) return true;
        return false;
    }
};