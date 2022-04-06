// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

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

    string s = "";

    void dfs(TreeNode* root){
        if (!root) {
            s = s + ' ' + "N";
            return;
        }

        s += ' ' + to_string(root->val);
        dfs(root->left);
        dfs(root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        dfs(root);
        printf("%s\n", s.c_str());
        return s;
    }

    int j=0; int first = 1;
    TreeNode* dfs2(stringstream& streamer){

        string word;
        if (streamer >> word){
            if (word == "N") return NULL;
        }

        TreeNode* root = new TreeNode(stoi(word));

        root->left = dfs2(streamer);
        root->right = dfs2(streamer);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        stringstream streamer(data);
        return dfs2(streamer);
       // return new TreeNode(3);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));