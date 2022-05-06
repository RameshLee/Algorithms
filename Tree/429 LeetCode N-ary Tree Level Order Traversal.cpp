// Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return vector<vector<int>>();

        vector<vector<int>> result; result.push_back(vector<int>({root->val}));
        queue<Node*> q; q.push(root);

        // level-order traversal or BFS using queue
        vector<int> level;
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; i++){
                Node* root = q.front(); q.pop();
                for (auto child:root->children)
                    if (child){
                        q.push(child);
                        level.push_back(child->val);
                    }
            }
            if (!level.empty()) result.push_back(level);
            level.clear();
        }
        return result;
    }
};