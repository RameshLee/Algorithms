// Link: https://leetcode.com/problems/plus-one/

// Carry-forward summation: T=O(n), S=O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int carry = 0, sum = 0;
        for (int i=digits.size()-1; i>=0 ;i--){
            if (i==digits.size()-1) {
                sum = (1+digits[i])%10;
                carry = (1+digits[i])/10;
                digits[i] = sum;
            }
            else{
                sum = (carry+digits[i])%10;
                carry = (carry+digits[i])/10;
                digits[i] = sum;
            }
        }
        if (carry>0) digits.insert(digits.begin(), carry);
        return digits;
    }
};