// Link: https://leetcode.com/problems/merge-strings-alternately/

// 1) Recursive Solution
class Solution {
public:
    string str;
    string mergeAlternately(string word1, string word2, int i=0, int j=0) {

        if (i>=word1.size() && j>=word2.size()) return str; //base-case

        if (j>=word2.size()) str.push_back(word1[i]), i++;
        else if (i>=word1.size()) str.push_back(word2[j]), j++;
        else str.push_back(word1[i]),str.push_back(word2[j]),i++,j++;

        return mergeAlternately(word1, word2, i, j); //recursion
    }
};

// 2) Iterative Solution (Preferred: 100.00% Faster)
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0; int j=0; string str;
        while (1){
            if (i>=word1.size() && j>=word2.size()) break;
            if (i>=word1.size()) str.push_back(word2[j]), j++;
            else if (j>=word2.size()) str.push_back(word1[i]), i++;
           else str.push_back(word1[i]),str.push_back(word2[j]),i++,j++;
        }
        return str;
    }
};