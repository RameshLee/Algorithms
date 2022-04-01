// Link: https://leetcode.com/problems/group-anagrams/

// 1) Using hashmap and sort: T=O(N*logN), S=O(N)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ret;
        vector<string> vec;

        // sort and store the vector<strings>
        for (auto& it:strs){
            vec.push_back(it);
            int k = vec.size()-1;
            sort(vec[k].begin(), vec[k].end());
        }

        // extract the indices of anagrams by referring sorted strings
        unordered_map<string,vector<int>> Map; //string, indices
        for (int i=0; i<vec.size(); i++){
            Map[vec[i]].push_back(i);
        }

        // retrieve unmodified anagrams from respective indices
        for (auto it=Map.begin(); it!=Map.end(); it++){
            vector<int> indices = it->second; // all indices of an unique anagram
            vector<string> group;
            for (int i=0; i<indices.size(); i++){
                int j = indices[i];
                group.push_back(strs[j]);
            }
            ret.push_back(group); // push into results
        }

        return ret;
    }
};