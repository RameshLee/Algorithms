// Link: https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/

// Leverages on the ideas from the following problems:
// 1) https://leetcode.com/problems/validate-binary-search-tree/
// 2) https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        this->preorder = preorder;
        this->inorder = preorder;
        std::sort(inorder.begin(), inorder.end());

        // construct and validate the bst
        for (auto i=0; i<inorder.size(); i++) Map[inorder[i]] = i;
        auto root = constructBST(0, inorder.size()-1);
        return isValidBST(root, nullptr, nullptr);
    }
private:
    TreeNode* constructBST(int start, int end) { // construct bst from preorder & inorder
        if (start > end || j>preorder.size()-1) {
            j--; return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[j]);
        int index = Map[preorder[j]];
        j++; root->left  = constructBST(start, index-1);
        j++; root->right = constructBST(index+1, end);

        return root;
    }

    bool isValidBST(TreeNode* root, TreeNode* Min, TreeNode* Max) { // valid bst
        if (!root) return true;

        if (Min && root->val < Min->val) return false;
        if (Max && root->val > Max->val) return false;

        return (isValidBST(root->left, Min, root) && isValidBST(root->right, root, Max));
    }

private:
    vector<int> inorder, preorder;
    unordered_map<int,int> Map;
    int j = 0;
};