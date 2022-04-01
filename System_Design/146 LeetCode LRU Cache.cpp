// Link: https://leetcode.com/problems/lru-cache/

class LRUCache {
    using listofpairs = list<pair<int,int>>;

public:
    int cap;
    listofpairs l;
    unordered_map<int,listofpairs::iterator> Map;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {

        if (Map.find(key) == Map.end()) return -1;

        listofpairs::iterator it = Map[key];
        int val = it->second;
        l.erase(Map[key]);
        l.push_front(make_pair(key,val));
        Map[key] = l.begin();

        return val;
    }

    void put(int key, int value) {
        if (Map.find(key) != Map.end()){
            l.erase(Map[key]);
        }

        l.push_front(make_pair(key,value));
        Map[key] = l.begin();

        if (l.size() > cap){
            Map.erase(l.back().first);
            l.pop_back();
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
