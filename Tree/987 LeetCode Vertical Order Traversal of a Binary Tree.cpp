// Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class cmp{
public:
    using ppi = pair<int, pair<int,vector<int>>>;
    bool operator()(const ppi& p1, const ppi &p2){
        return (p1.first == p2.first) ? p1.second >= p2.second : p1.first >= p2.first;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        extractResult();
        return result;
    }
private:
    vector<vector<int>> result; //vector<int> vec;
    unordered_map<int, unordered_map<int, vector<int>>> Map; // col, row,[values]

    void dfs(TreeNode* root, int row, int col) {
        if (!root) return;
        Map[col][row].push_back(root->val);
        dfs(root->left, row+1, col-1);
        dfs(root->right, row+1, col+1);
    }

    void extractResult(){
        // convert the map into priority queue
        using ppi = pair<int, pair<int,vector<int>>>;
        priority_queue<ppi, vector<ppi>, cmp> pq; // col, row,[values]
         for (auto it=Map.begin(); it!=Map.end(); it++){
            auto Mp = it->second;
            for (auto iterator=Mp.begin(); iterator!=Mp.end(); iterator++){
                pq.push(make_pair( it->first, make_pair(iterator->first, iterator->second) ));
            }
        }

        // extract the output from pq
        int prevCol = INT_MAX;
        while (!pq.empty()){
            int col = pq.top().first;
            int row = pq.top().second.first;
            vector<int> vec = pq.top().second.second; pq.pop();

            sort(vec.begin(), vec.end());
            if (prevCol == col){
                for (auto e:vec) result[result.size()-1].push_back(e);
            }
            else {
                result.push_back(vec);
            }
            prevCol = col;
        }
    }
};