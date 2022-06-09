// Link: https://leetcode.com/problems/time-needed-to-inform-all-employees/

// Algo: build a tree and record maxTime at all leaf nodes
class Node {
public:
    int val;
    vector<Node*> children;
    Node(int v) : val(v) {}
    ~Node() {}
};

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // create nodes
        for (auto i=0; i<n; i++) {
            Map[i] = new Node(i);
        }

        // build tree
        for (auto i=0; i<n; i++) {
           if (manager[i] != -1)
               Map[manager[i]]->children.push_back(Map[i]);
        }

        // apply dfs
        helper(Map[headID], 0, informTime);
        return result;
    }
private:
    void helper(Node* root, int timestamp, vector<int>& informTime) {
        if (!root) return;
        if (root->children.empty()) { // update time at leaf nodes
            result = max(result, timestamp);
        }
        for (auto n : root->children) {
            helper(n, timestamp+informTime[root->val], informTime);
        }
    }
private:
    unordered_map<int,Node*> Map;
    int result = 0;
};