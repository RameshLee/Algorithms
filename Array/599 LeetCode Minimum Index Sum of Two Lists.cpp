// Link: https://leetcode.com/problems/minimum-index-sum-of-two-lists/

using ps = pair<string,int>;

class myComparator{ // custom-made comparator for priority queue
public:
    bool operator()(ps& p1, ps& p2){
        return p1.second > p2.second;
    }
};

class Solution {
public:
    vector<string> findRestaurant(vector<string>& l1, vector<string>& l2) {

        priority_queue<ps, vector<ps>, myComparator> pq;
        unordered_map<string,int> Map; //string,index
        for (auto i=0; i<l1.size(); i++) Map[l1[i]]=i; // store the string as key, and indices as values
        for (auto i=0; i<l2.size(); i++){
             if (Map.find(l2[i]) != Map.end()){
                 int sumIndex = i+Map[l2[i]];
                 pq.push(make_pair(l2[i],sumIndex)); // if strings are present in both, then update pq.
             }
        }

        // update output
        vector<string> ret;
        ret.push_back(pq.top().first);
        int indexSum = pq.top().second; pq.pop();

        // keep updating output as long as "indexSum" remains same!
        while(!pq.empty()){
            ps p = pq.top(); pq.pop();
            if (indexSum == p.second) ret.push_back(p.first);
            else break;
        }
        return ret;
    }
};