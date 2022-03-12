// Link: https://leetcode.com/problems/permutations/
// C++ STL based solution - beats 100% submissions in terms of speed

class Solution {
public:
    vector<vector<int>> permute(vector<int>& vec) {

            vector<vector<int>> output;

            sort(vec.begin(),vec.end());

            // Find all possible permutations
            do {
                //for (auto& it:vec) cout << " " << it; cout << endl;
                output.push_back(vec);
             } while (next_permutation(vec.begin(), vec.end()));


            return output;

    }
};

