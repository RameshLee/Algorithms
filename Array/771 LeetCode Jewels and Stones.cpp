// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Using HashMap: T=O(n), S=O(n), where n->number of stones

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> Map;
        for (auto& it:jewels) Map[it]++;

        int count = 0;
        for (auto& it:stones){
            if (Map.find(it) != Map.end())
                count++;
        }
        return count;
    }
};