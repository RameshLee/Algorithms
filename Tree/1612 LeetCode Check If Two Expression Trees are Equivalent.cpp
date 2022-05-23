// Link: https://leetcode.com/problems/check-if-two-expression-trees-are-equivalent/

/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */

// 1) Count total characters in both expression trees
class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        unordered_map<char,int> Map;
        helper(root1, Map); // count chars in tree1
        helper(root2, Map); // count chars in tree2
        for (auto it:Map) { // return true if they are same tree!
            if (it.second % 2 != 0)
                return false;
        }
        return true;
    }
private:
    void helper(Node* root, unordered_map<char,int>& Map) {
        if (!root) return;
        Map[root->val]++;
        helper(root->left, Map);
        helper(root->right, Map);
    }
};

// 2) Retrieve the expressions as strings and compare them
class Solution {
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        unordered_map<char,int> Map;

        // retrieve expression in string format
        string Expression1 = helper(root1, Map);
        string Expression2 = helper(root2, Map);

        // compare the expressions
        for (auto it=Map.begin(); it!=Map.end(); it++) {
            if (it->second % 2 != 0)
                return false;
        }
        return true;
    }
private:
    string helper(Node* root, unordered_map<char,int>& Map) {
        if (!root) return "N";

        string l = helper(root->left, Map);
        string r = helper(root->right, Map);
        string curr; curr.push_back(root->val);
        Map[root->val]++;

        return (l == "N" || r == "N") ? curr : l+curr+r;
    }
};