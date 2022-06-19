// Link: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

class Node {
public:
    int val, label;
    vector<Node*> children;
    Node(int v, int w) : val(v), label(w) {}
    ~Node() {}
};

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this->result.resize(n,-1);
        // create nodes
        for (auto i=0; i<n; i++) {
            Map[i] = new Node(i, labels[i]-'a');
        }

        // build the tree
        for (auto e : edges) {
            Map[e[0]]->children.push_back(Map[e[1]]);
            Map[e[1]]->children.push_back(Map[e[0]]);
        }

        // apply dfs
        helper(Map[0]);
        return result;
    }
private:
    vector<int> helper(Node* root) {
        if (!root || visited.count(root)) return vector<int>();
        visited.insert(root);

        vector<int> collection(26,0);
        collection[root->label]++;
        for (auto n : root->children) { // update count
            auto temp = helper(n);
            for (auto i=0; i<temp.size(); i++)
                collection[i] += temp[i];
        }
        result[root->val] = collection[root->label]; // update result

        return collection;
    }
private:
    vector<int> result;
    unordered_map<int,Node*> Map;
    unordered_set<Node*> visited;
};