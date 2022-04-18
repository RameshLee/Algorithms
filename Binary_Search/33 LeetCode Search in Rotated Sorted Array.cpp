// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

// One-pass Binary search: T=O(logN), S=O(1) (100% Faster)

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l=0, r=nums.size()-1;
        while (l<=r){
            int mid = l + rand()%(r-l+1);
            if (nums[mid] == target) return mid;

            if (nums[mid] > nums[r]){ // rotation exist; on the left-half
                if (target >= nums[l] && target < nums[mid]) r = mid - 1;
                else                                        l = mid + 1;
            }
            else if (nums[mid] < nums[l]){ // rotation exist; on the right-half
                if (target > nums[mid] && target <= nums[r]) l = mid + 1;
                else                                        r = mid - 1;
            }
            else { // no rotation
                if (nums[mid] < target) l = mid + 1;
                else                    r = mid - 1;
            }
        }
        return -1;
    }
};