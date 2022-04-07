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

// 1) using BFS

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string s;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()){
            TreeNode* node = q.front(); q.pop();

            if (!node) s += "Null ";
            else {
                s += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream str; str<<data;
        string word;

        TreeNode* root = NULL;
        if (str>>word){
            root = new TreeNode(stoi(word));
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            TreeNode* node = q.front(); q.pop();

            if (str>>word){
                if (word != "Null") {
                    node->left = new TreeNode(stoi(word));
                    q.push(node->left);
                }
            }

            if (str>>word){
                if (word != "Null") {
                    node->right = new TreeNode(stoi(word));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};


// 2) using DFS

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
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));