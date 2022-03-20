// Link: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

class Solution {
public:
    void addition(vector<int>& arr, int l, int r, int &sum){
        for (int i=l; i<=r; i++)
            sum += arr[i];
    }

    int sumOddLengthSubarrays(vector<int>& arr) {
       int sum = 0;
       int odd = 0;
       for (int odd=0; odd<arr.size(); odd=odd+2){
           int l = 0; int r = odd;
           for (int r=odd; r<arr.size(); r++, l++){
               addition(arr,l,r, sum);
           }
       }
       return sum;
    }
};