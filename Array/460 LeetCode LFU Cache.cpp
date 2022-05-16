// Link: https://leetcode.com/problems/lfu-cache/

// Approach: using 3 hashMaps { (key,pair(values,freq), (key,iterators), (freq, list of keys)) }
class LFUCache {
public:
    LFUCache(int cap) : capacity(cap), size(0), lfu(0) {}

    int get(int key) {
        if (!values.count(key)) return -1;
        update(key);
        return values[key].first;
    }

    void put(int key, int val) {
        if (!capacity) return;

        // key already present in lfu
        if (values.count(key)) {
            values[key].first = val;
            update(key);
            return;
        }

        // full capacity reached in lfu
        if (size == capacity) { // evict leastFreq (if tied, leastRecent) from lfu
            auto pos = keyList[lfu].front();
            keyList[lfu].pop_front();
            iters.erase(pos);
            values.erase(pos);
        }
        else {
            size++;
        }

        // insert this new (key,val) pair in lfu
        values[key] = make_pair(val,1);
        keyList[1].push_back(key);
        iters[key] = --keyList[1].end(); // predecremented ptr => points to the last element.
        lfu = 1;
    }
private:
    int capacity, size, lfu;
    unordered_map<int,pair<int,int>> values; // (key, pair(val,freq))
    unordered_map<int,list<int>> keyList; // (freq, list of keys)
    unordered_map<int,list<int>::iterator> iters; // (key, iterator)

    void update(int key) {
        auto val = values[key].first;
        auto freq = values[key].second;

        // update the keyList, iters, and values
        keyList[freq].erase(iters[key]);
        keyList[freq+1].push_back(key);
        iters[key] = --keyList[freq+1].end();
        values[key].second++;

        if (keyList[lfu].empty()) lfu++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */