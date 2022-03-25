// Link: https://leetcode.com/problems/3sum-closest/


// 1) using Two-pointers (preferred)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int closest=99999;
        int n=nums.size();

        sort(nums.begin(),nums.end()); // Sorting is essential to apply 2-pointer approach

        for(int i=0; i<n-2; i++){ // Fix the first ele & apply 2-pointer approach to find the other two elements

            int first = nums[i];
            int l=i+1;
            int r=n-1;

            while(l<r){ // Two-pointer approach to find second and third elements
                int sum=first+nums[l]+nums[r];
                if(abs(sum-target) < abs(closest-target)) closest = sum;
                if(sum < target) l++;
                else r--;
            }
        }
        return closest;
    }
};

// 2) using HashMap
class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {

        unordered_map<int,int> Map;
        int val = 0;
        int externalBest = INT_MAX;

        for (int i=0; i<arr.size(); i++){

            int first = arr[i];  // fix the first element
            Map.clear();

            for (int j=i+1; j<arr.size(); j++){
                int second = arr[j];
                int third = target - (first+second);  // pick the second element

                int bestdiff = INT_MAX;
                int bestThird = INT_MAX;

                for (auto it=Map.begin(); it!=Map.end(); it++){  // find the closest third element in HashMap
                    int Difference = abs(third - it->first);
                    if (Difference < bestdiff){
                        bestdiff = Difference;
                        bestThird = it->first;
                    }
                }

                if (bestThird != INT_MAX) { // update the closestSum in val
                    int sum = first+second+bestThird;
                    int Difference = abs(sum-target);
                    if (Difference < externalBest){
                        externalBest = Difference;
                        val = sum;
                    }

                }
                Map[second] = 99;
            }
        }
        return val;
    }
};