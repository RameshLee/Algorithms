// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

// Using hashmap: T=O(n), S=O(n) (100% faster)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char,char> Map;
        unordered_map<char,int> ValueMap;
        for (int i=0; i<s.size(); i++){
            if (Map.find(s[i]) != Map.end()){
                if (Map[s[i]] != t[i])
                    return false;
            }
            else{
                if (ValueMap.find(t[i]) != ValueMap.end())
                    return false;
                else{
                    Map[s[i]] = t[i];
                    ValueMap[t[i]] = 1;
                }
            }
        }

        return true;
    }
};