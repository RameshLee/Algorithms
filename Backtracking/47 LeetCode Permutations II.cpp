// Link: https://leetcode.com/problems/permutations/

// 1) Backtracking approach
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->vec = nums;
        backtrack(0);
        return vector<vector<int>>(output.begin(), output.end());
    }
private:
    set<vector<int>> output; vector<int> vec;

    void backtrack(int i) {
        if (i == vec.size()-1){ // base-case
            output.insert(vec);
            return;
        }

        for (int j=i; j<vec.size(); j++){ // for all candidates
            std::swap(vec[i],vec[j]); // make move
            backtrack(i+1);
            std::swap(vec[i],vec[j]); // undo move
        }
    }
};



// 2) Solution using STL container
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& vec) {
            set<vector<int>> output;
            sort(vec.begin(),vec.end());
            // Find all possible permutations
            do {
                //for (auto& it:vec) cout << " " << it; cout << endl;
                output.insert(vec);
             } while (next_permutation(vec.begin(), vec.end()));
            return vector<vector<int>>(output.begin(), output.end());
    }
};

