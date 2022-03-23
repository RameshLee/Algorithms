// Link: https://leetcode.com/problems/permutations/

// 1) Backtracking approach
class Solution {
public:
	vector<vector<int>> output;
    void backtrack(vector<int> &vec, int l, int r){
        if (l==r) { //base-case
            output.push_back(vec);
            return;
        }
        for (int i=l; i<=r; i++){
            std::swap(vec[l],vec[i]); //make move
            backtrack(vec, l+1, r); ///recursively explore from this move
            std::swap(vec[l],vec[i]);; //undo move
        }
    }

    vector<vector<int>> permute(vector<int>& vec) {
            backtrack(vec, 0, vec.size()-1);
            return output;
    }
};

// 2) Solution using STL container
class Solution {
public:
    vector<vector<int>> permute(vector<int>& vec) {
            vector<vector<int>> output;
            sort(vec.begin(),vec.end()); // sort
            do { output.push_back(vec); // extract permutations
             } while (next_permutation(vec.begin(), vec.end()));
            return output;
    }
};
