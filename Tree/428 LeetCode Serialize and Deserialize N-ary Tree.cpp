// Link: https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/

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

// 1) using BFS

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {

        string s;
        queue<Node*> q;
        if (root) q.push(root), q.push(nullptr);

        while (!q.empty()){
            Node* node = q.front(); q.pop();

            if (!node) s += "null ";
            else {
                s += to_string(node->val) + " ";
                for (auto& it:node->children) q.push(it);
                q.push(nullptr); //end-of-row marker
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {

        printf("%s\n", data.c_str());
        stringstream line; line<<data;
        string word;

        Node* root = NULL;
        queue<Node*> q;
        if (line>>word){
            root = new Node(stoi(word));
            q.push(root);
            line>>word; // read the unnecessary nullptr after root
        }

        while (!q.empty()){
            Node* temp = q.front(); q.pop();

            while (line>>word){
                if (word == "null") break;
                Node* child = new Node(stoi(word));
                temp->children.push_back(child);
                q.push(child);
            }
        }

        return root;
    }
};


// 2) using DFS

class Codec {
private: string s,word; stringstream line;
public:
    void dfs(Node* root){
        s += " " + to_string(root->val);
        for (auto& it:root->children)
            dfs(it);

        s += " EOC"; // end-of-child marker
    }

    // Encodes a tree to a single string.
    string serialize(Node* root) {

        if (!root) return s;
        dfs(root);
        return s;
    }

    Node* dfs2(string &word){

        Node* root = new Node(stoi(word));
        while (line>>word){
            if (word == "EOC") break;
            Node *child = dfs2(word);
            root->children.push_back(child);
        }
        return root;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {

        line << data; // read the string data as a stream
        string word;
        if (line >> word){
            if (word == "EOC") return nullptr;
        }
        if (word.empty()) return nullptr;
        return dfs2(word);
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));