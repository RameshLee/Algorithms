// Link: https://leetcode.com/problems/delete-tree-nodes/

class Node {
public:
    int val, sum;
    vector<Node*> children;
    Node(int v) : val(v) {}
    ~Node() {}
};

class Solution {
public:
    int deleteTreeNodes(int n, vector<int>& parent, vector<int>& value) {
        // create nodes
        for (auto i=0; i<n; i++) {
            Map[i] = new Node(value[i]);
        }

        // build tree
        for (auto i=0; i<n; i++) {
            if (parent[i] != -1)
                Map[parent[i]]->children.push_back(Map[i]);
        }

        // apply dfs
        helper(Map[0]);
        dfs(Map[0]);
        return count;
    }
private:
    unordered_map<int,Node*> Map;
    int count = 0;

    int helper(Node* root) { // calculate subtree sum
        if (!root) return 0;

        root->sum = root->val;
        for (auto n : root->children) {
            root->sum += helper(n);
        }
        return root->sum;
    }

    void dfs(Node* root) { // count tree nodes
        if (!root || root->sum == 0) return;

        count++;
        for (auto n : root->children) {
            dfs(n);
        }
    }
};