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
    void levelOrder(Node* head, vector<vector<int>>& vec){

        vec.push_back(vector<int>({head->val}));
        vector<int> level;
        queue<Node*> q;
        q.push(head);

        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; i++){

                Node* root = q.front(); q.pop();
                for (int j=0; j<root->children.size(); j++){
                    if (root->children[j]){
                        q.push(root->children[j]);
                        level.push_back(root->children[j]->val);
                    }
                }
            }
            if (!level.empty()) vec.push_back(level);
            level.clear();
        }
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vec;
        if (root) levelOrder(root, vec);
        return vec;
    }
};