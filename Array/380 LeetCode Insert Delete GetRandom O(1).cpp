// Link: https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
public:
    bool insert(int val) {
        if (Map.find(val) == Map.end()){
            vec.push_back(val); // store elements
            Map[val] = vec.size()-1; // stores index
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (Map.find(val) != Map.end()){
            int index = Map[val];
            std::swap(vec[index], vec[vec.size()-1]); // swap the deletable elem & last element
            Map[vec[index]] = index; // update the new index
            vec.pop_back(); // delete the target element
            Map.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {
        int i = rand()%vec.size();
        return vec[i];
    }
private:
    unordered_map<int,int> Map;
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

