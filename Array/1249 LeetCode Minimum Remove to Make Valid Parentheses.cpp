// Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/


//Solution-1: Iterative algorithm at O(N) time complexity

class Solution {
public:
    string minRemoveToMakeValid(string s) {

        string vec; int sum;

        // 1) remove invalid closing braces
        sum = 0;
        for (int i=0; i<s.size(); i++){
             if (s[i] == '(') sum += 1;
             else if (s[i] == ')')  sum -= 1;

             if (sum < 0) sum = 0;
             else vec.push_back(s[i]);
        }

        s=vec;
        vec.clear();

         // 2) remove invalid opening braces
        sum = 0;
        for (int i=s.size()-1; i>=0; i--){
             if (s[i] == '(') sum += 1;
             else if (s[i] == ')')  sum -= 1;

             if (sum > 0) sum = 0;
             else vec.push_back(s[i]);
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};

//Solution-2: Using hash map at O(N) time complexity

class Solution {
public:
    string minRemoveToMakeValid(string s) {

        string vec; int sum;
        unordered_map<int,int> indices;

        // 1) remove invalid closing braces
        sum = 0;
        for (int i=0; i<s.size(); i++){
             if (s[i] == '(') sum += 1;
             else if (s[i] == ')')  sum -= 1;

             if (sum < 0) {sum+=1; indices[i]++;}
        }

         // 2) remove invalid opening braces
        sum = 0;
        for (int i=s.size()-1; i>=0; i--){
             if (s[i] == '(') sum += 1;
             else if (s[i] == ')')  sum -= 1;

             if (sum > 0) {sum-=1; indices[i]++;}
        }

        for (int i=0; i<s.size(); i++)
            if (!indices[i])
                vec.push_back(s[i]);

        return vec;
    }
};