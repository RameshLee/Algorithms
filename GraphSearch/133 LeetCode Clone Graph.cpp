// Link: https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (node->neighbors.empty()) return new Node(node->val);
        return dfs(node);
    }
private:
    unordered_map<Node*,Node*> Visited;

    Node* dfs(Node* node) {
        vector<Node*> neighbors;
        Node* clone = new Node(node->val);
        Visited[node] = clone;
        for (auto it : node->neighbors) {
            if (Visited.find(it) == Visited.end())  neighbors.push_back(dfs(it));
            else                                    neighbors.push_back(Visited[it]);
        }
        clone->neighbors = neighbors;
        return clone;
    }
};
