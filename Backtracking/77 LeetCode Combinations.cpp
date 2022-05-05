// Link: https://leetcode.com/problems/combinations/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n, this->k = k;
        backtrack(1);
        return output;
    }
private:
    int n, k; vector<int> vec; vector<vector<int>> output;

    void backtrack(int i){
        if (vec.size() == k){ //base-case
            output.push_back(vec);
            return;
        }

        for (int j=i; j<=n; j++){ //explore candidates
            vec.push_back(j); // make move
            backtrack(j+1); // backtrack
            vec.pop_back(); // undo move
        }
    }
};