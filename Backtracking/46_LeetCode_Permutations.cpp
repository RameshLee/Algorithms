// Link: https://leetcode.com/problems/permutations/

// 1) Backtracking approach
class Solution {
public:
    vector<vector<int>> permute(vector<int>& vec) {
        this->vec = vec;
        backtrack(0);
        return output;
    }
private:
    vector<vector<int>> output; vector<int> vec;

    void backtrack(int i){
        if (i==vec.size()-1) { //base-case
            output.push_back(vec); //cout<<"vec ";for (auto& it:vec) printf("%d", it); cout<<endl;
            return;
        }

        for (int j=i; j<vec.size(); j++){
            std::swap(vec[i],vec[j]); //make move
            backtrack(i+1); ///recursively explore from this move
            std::swap(vec[i],vec[j]);; //undo move
        }

    }
};



// 2) Solution using STL container
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

