// Link: https://leetcode.com/problems/top-k-frequent-words/

class cmp{
public:
    bool operator()(pair<int,string>& a, pair<int,string>& b){
        return (a.first == b.first) ? a.second > b.second : a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // find frequency of each word
        unordered_map<string,int> Map;
        for (auto& s:words) Map[s]++;

        // store the words & freq in a vector
        vector<pair<int,string>> vec;
        for (auto it=Map.begin(); it!=Map.end(); it++){
            vec.push_back(make_pair(it->second, it->first));
        }

        // create a priority queue
        using pi = pair<int,string>;
        priority_queue<pi, vector<pi>, cmp> pq(vec.begin(), vec.end());

        // update results
        vector<string> ret;
        for (int i=0; i<k; i++) {
            ret.push_back(pq.top().second); pq.pop();
        }
        return ret;
    }
};