// Link: https://leetcode.com/problems/design-hashmap/

#define MAX_LEN 100

class MyHashMap {
public:
    vector<pair<int,int>> l[MAX_LEN];

    int hash(int key){
        return key % MAX_LEN;
    }

    void put(int key, int value) {
        int bucket = hash(key);
        int pos = getPosition(key);

        if (pos == -1){
            l[bucket].push_back(make_pair(key,value));
        }
        else {
            l[bucket][pos].second= value;
        }
    }

    int getPosition(int key){
        int bucket = hash(key);
        for (int pos=0; pos<l[bucket].size(); pos++){
            if (l[bucket][pos].first == key)
                return pos;
        }
        return -1;
    }

    int get(int key) {
        int bucket = hash(key);
        int pos = getPosition(key);
        if (pos == -1) return -1;
        return l[bucket][pos].second;
    }

    void remove(int key) {
        int bucket = hash(key);
        int pos = getPosition(key);
        if (pos == -1) return;
        l[bucket].erase(l[bucket].begin() + pos);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */