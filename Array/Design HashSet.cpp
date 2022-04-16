// Link: https://leetcode.com/problems/design-hashset/

 // 1) Design hashset using vector

#define MAX_LEN 1000

class MyHashSet {
public:
    vector<int> Set[MAX_LEN];

    int hash(int key){ return key % MAX_LEN; }

    int getPosition(int key){
        int bucket = hash(key);
        for (int pos=0; pos<Set[bucket].size(); pos++)
            if (Set[bucket][pos] == key)
                return pos;
        return -1;
    }

    void add(int key) {
        int bucket = hash(key);
        int pos = getPosition(key);
        if (pos == -1) Set[bucket].push_back(key);
    }

    void remove(int key) {
        int bucket = hash(key);
        int pos = getPosition(key);
        if (pos == -1) return;
        Set[bucket].erase(Set[bucket].begin() + pos);
    }

    bool contains(int key) {
        return (getPosition(key) == -1) ? false : true;
    }
};

// 2) hash set using BST STL

/*class MyHashSet {
public:
    map<int,int> Map;

    MyHashSet() {

    }

    void add(int key) {
        Map[key] = key;
    }

    void remove(int key) {
        if (Map.find(key) != Map.end()){
            Map.erase(key);
        }
    }

    bool contains(int key) {
        if (Map.find(key) == Map.end()) return false;
        return true;
    }
};*/

/*
// 3) hash set using list STL

class MyHashSet {
public:
    list<int> l[10];
    int M = 4;

    MyHashSet() {

    }

    int hash(int key){
        return key % M;
    }

    void add(int key) {
        int index = hash(key);
        if (!contains(key))
            l[index].push_back(key);
    }

    void remove(int key) {
        int index = hash(key);
        list<int>::iterator it = find(l[index].begin(),l[index].end(), key);
        if (it != l[index].end()) l[index].erase(it);
    }

    bool contains(int key) {
        int index = hash(key);
        list<int>::iterator it = find(l[index].begin(),l[index].end(), key);
        if (it == l[index].end()) return false;
        return true;
    }
};*/

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */