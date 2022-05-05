// Link: https://leetcode.com/problems/n-ary-tree-postorder-traversal/

class Solution {
public:
    vector<int> postorder(Node* root) {
        helper(root);
        return vec;
    }
private:
    vector<int> vec;

    void helper(Node* root) {
        if (!root) return;
        for (auto it:root->children){
            helper(it);
        }
        vec.push_back(root->val);
    }
};