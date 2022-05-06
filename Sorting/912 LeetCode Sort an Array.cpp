// Link: https://leetcode.com/problems/sort-an-array/

// 2) MergeSort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    void merge(vector<int>& nums, int start, int mid, int end){
        int s1=mid-start, s2=end-(mid+1);
        vector<int> t1, t2;

        for (int i=start; i<=mid; i++) t1.push_back(nums[i]);
        for (int i=mid+1; i<=end; i++) t2.push_back(nums[i]);

        int i=0, j=0, index=start;
        while(1){
            if (i>s1 && j>s2)       break;
            else if (i>s1)          nums[index++] = t2[j++];
            else if (j>s2)          nums[index++] = t1[i++];
            else if (t1[i] < t2[j]) nums[index++] = t1[i++];
            else                    nums[index++] = t2[j++];
        }
    }

    void mergesort(vector<int>& nums, int start, int end){
        if (start>=end) return;
        int mid = (start+end)/2;
        mergesort(nums, start, mid);
        mergesort(nums, mid+1, end);
        merge(nums, start, mid, end);
    }
};