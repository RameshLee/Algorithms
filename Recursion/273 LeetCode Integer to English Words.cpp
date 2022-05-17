// Link: https://leetcode.com/problems/integer-to-english-words/

class Solution {
public:
    string numberToWords(int num) {
        return (num==0) ? "Zero" : helper(num).substr(1);
    }
private:
    string one[19]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

string ten[10]={"Zeroty","OneTy",  "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

    string helper(int n) {
        if(n>=1000000000)   return helper(n/1000000000)+" Billion"+helper(n%1000000000);
        if(n>=1000000)      return helper(n/1000000)+" Million"+helper(n%1000000);
        if(n>=1000)         return helper(n/1000)+" Thousand"+helper(n%1000);
        if(n>=100)          return helper(n/100)+" Hundred"+helper(n%100);
        if(n>=20)           return " "+ten[n/10]+helper(n%10);
        if(n>=1)            return " "+one[n-1];
        return "";
    }
};


