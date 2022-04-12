// Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// 1) Priority queue approach: T=O(N*logN)

class Solution {
public:
    string frequencySort(string s) {

        // count the frequency
        unordered_map<char,int> Map;
        for (auto& c:s) Map[c]++;

        // create a vector with char and freq
        vector<pair<int,char>> vec;
        for (auto it=Map.begin(); it!=Map.end(); it++)
            vec.push_back(make_pair(it->second, it->first));

        // add it into priority queue
        priority_queue<pair<int,char>> pq(vec.begin(), vec.end());

        // build result string
        string ret;
        while (!pq.empty()){
            for (int i=0; i<pq.top().first; i++)
                ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};

// 2) Use bucket sort since there are only 26 characters: T=O(N)