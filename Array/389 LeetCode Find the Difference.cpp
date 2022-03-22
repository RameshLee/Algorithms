// Link: https://leetcode.com/problems/find-the-difference/

// 1) using ASCII value difference (Preferred: 100.00% Faster)
class Solution {
public:
    char findTheDifference(string s, string t) {
        double A = 0;
        double B = 0;

        for (auto& it:s) A += it;
        for (auto& it:t) B += it;

        return (char)(B-A);
    }
};


// 2) using hashmap
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int,int> Map;
        unordered_map<int,int> Map2;

        for (auto& it:s) Map[it]++;
        for (auto& it:t) Map2[it]++;

        for (auto& it:t){
           if (Map[it] != Map2[it]) return it;
        }

        return 'a';
    }
};