// Link: https://leetcode.com/problems/permutation-in-string/

class Solution {
    
public:
    bool checkInclusion(string s1, string s2) 
    {
        // special case
        if (s1.size() == s2.size())
        {
            int sum = 0;
            for (int i=0; i<s1.size(); i++)
                sum += (int)s1[i];
            
            int sum2 = 0;
            for (int i=0; i<s2.size(); i++)
                sum2 += (int)s2[i];
            
            if (sum == sum2) return true;
            else return false;
        }
        
        
        // sliding window approach
        int sum = 0;
        for (int i=0; i<s1.size(); i++)
            sum += (int)s1[i];
        sort(s1.begin(), s1.end());
        
        int l = 0;
        int r = s1.size()-1;
        
        int movingSum = 0;
        for (int l=0; l<s2.size(); l++)
        { 
            if ((l+r) > s2.size()-1)
                break;

            // count the sum of ascii values in substring s2
            movingSum = 0;
            for (int j=l; j<=(l+r); j++)
            if (j<s2.size())
                movingSum += (int)s2[j];
              
            // double check: sort the s2 substring and check whether it is same as s1
            // NOTE: this move is executed rarely when movingSum==sum, therefore it has amortized time complexity
            if (movingSum == sum)
            {
                int found = 1;
                
                string s3 = s2.substr(l,r+1);
                sort(s3.begin(), s3.end());
                if (s1.size() == s3.size())
                    for (int j=0; j<s1.size(); j++)
                        if (s1[j] != s3[j]) //found
                        {
                             found = 0;
                             break;
                        }
                if (found) return true;
            }
        }
        
        return false;
    }
};