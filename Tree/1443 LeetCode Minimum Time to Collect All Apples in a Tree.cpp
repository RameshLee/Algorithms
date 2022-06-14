// Link:

class Node {
public:
    int val;
    vector<Node*> children;
    Node(int v) : val(v) {}
    ~Node() {}
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // create nodes
        for (auto i=0; i<n; i++) {
            Map[i] = new Node(i);
        }

        // build tree
        for (auto e:edges) {
            Map[e[0]]->children.push_back(Map[e[1]]);
            Map[e[1]]->children.push_back(Map[e[0]]);
        }

        // apply dfs
        return 2*helper(Map[0], hasApple);
    }
private:
    unordered_map<int, Node*> Map;
    unordered_set<Node*> visited;

    int helper(Node* root, vector<bool>& hasApple) {
        if (!root) return 0;
        if (visited.count(root)) return 0;
        visited.insert(root);

        int childApples = 0;
        for (auto n : root->children) {
            auto ans = helper(n, hasApple);
            childApples += ans;
        }

        if (root != Map[0] && !childApples) return (hasApple[root->val]) ? 1 : 0;
        return (root == Map[0]) ? childApples : 1+childApples;
    }
};