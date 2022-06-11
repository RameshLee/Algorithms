// Link: https://leetcode.com/problems/tree-diameter/

class Node {
public:
    int val;
    vector<Node*> children;
    Node(int v) : val(v) {}
    ~Node() {}
};

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        // create nodes
        for (auto e:edges) {
            Map[e[0]] = new Node(e[0]);
            Map[e[1]] = new Node(e[1]);
        }

        // build tree
        for (auto e:edges) {
            Map[e[0]]->children.push_back(Map[e[1]]);
            Map[e[1]]->children.push_back(Map[e[0]]);
        }

        // find max diameter from any node
        helper(Map[1]);
        return width;
    }
private:
    int helper(Node* root) {
        if (!root || visited.count(root)) return 0;
        visited.insert(root);

        int first = 0, second = 0; // first & second max height
        for (auto n : root->children) {
            auto curr = helper(n);
            if (curr > first) second = first, first = curr;
            else second = max(second, curr);
        }
        width = max(width, first+second);

        visited.erase(root);
        return 1+first;
    }
private:
    unordered_map<int,Node*> Map;
    unordered_set<Node*> visited;
    int width = 0;
};