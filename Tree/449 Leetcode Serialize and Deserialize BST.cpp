// Link: https://leetcode.com/problems/serialize-and-deserialize-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string s;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()){
            TreeNode* root = q.front(); q.pop();

            if (!root) s += "Null,";
            else s += to_string(root->val) + ",";

            if (root){
                q.push(root->left);
                q.push(root->right);
            }
        }
        printf("Encoded: %s\n", s.c_str());
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        stringstream line(data); string word;

        if (data.empty()) return nullptr;

        TreeNode* root = nullptr;
        queue<TreeNode*> q;
        if (line.good()){
            getline(line, word, ',');
            root = new TreeNode(stoi(word));
            q.push(root);
        }

        while (!q.empty()){

            TreeNode* root = q.front(); q.pop();

            if (line.good()){
                getline(line, word, ',');
                if (word != "Null"){
                    root->left = new TreeNode(stoi(word));
                    q.push(root->left);
                }
            }
            if (line.good()){
                getline(line, word, ',');
                if (word != "Null"){
                    root->right = new TreeNode(stoi(word));
                    q.push(root->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;