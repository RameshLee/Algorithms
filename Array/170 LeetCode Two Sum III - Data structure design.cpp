// Link: https://leetcode.com/problems/two-sum-iii-data-structure-design/

// using HashMap

class TwoSum {
private: unordered_map<long,long> Map;
public:
    TwoSum() {

    }

    void add(int number) {
        Map[number]++;
    }

    bool find(int target) {
        for (auto it=Map.begin(); it!=Map.end(); it++){
            auto first = it->first; auto count = it->second;
            auto second = target-first;

            if ((target-first == first) && count >= 2) return true;
            if ((target-first != first) && (Map.find(second) != Map.end())) return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
