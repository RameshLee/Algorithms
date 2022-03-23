// Link: https://leetcode.com/problems/combinations/

class Solution {
public:
    using vi = vector<int>;
    using vvi = vector<vector<int>>;

    void backtrack(int curr, int &n, int &k, vvi& output, vi& vec){

        if (vec.size() == k){ //base-case
            output.push_back(vec);
            return;
        }

        for (int j=curr; j<=n; j++){ //explore candidates
            vec.push_back(j); // make move
            backtrack(j+1,n,k,output,vec); // backtrack
            vec.pop_back(); // undo move
        }
    }

    vvi combine(int n, int k) {
        vi vec; vvi output;
        backtrack(1,n,k,output,vec);
        return output;
    }
};