// Link: https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (Map.find(key) == Map.end()) {
            return -1;
        }

        auto it = Map[key];
        int value = it->second;
        l.erase(Map[key]);
        l.push_front(make_pair(key,value));
        Map[key] = l.begin();

        return value;
    }

    void put(int key, int value) {
        if (Map.find(key) != Map.end()) {
            l.erase(Map[key]);
        }

        l.push_front(make_pair(key,value));
        Map[key] = l.begin();

        if (l.size() > this->capacity) {
            Map.erase(l.back().first);
            l.pop_back();
        }
    }
private:
    int capacity;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> Map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */