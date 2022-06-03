// Link: https://leetcode.com/problems/kill-process/

// class for n-ary tree
class Node {
public:
    int val;
    vector<Node*> children;

    Node(int v) : val(v) {}
    ~Node() {}
};

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        // create nodes
        for (auto i=0; i<pid.size(); i++) {
            Map[pid[i]]  = new Node(pid[i]);
            Map[ppid[i]] = new Node(ppid[i]);
        }

        // build tree
        for (auto i=0; i<pid.size(); i++) {
            if (ppid[i] != 0)
                Map[ppid[i]]->children.push_back(Map[pid[i]]);
        }

        // traversal
        helper(Map[kill]);
        return result;
    }
private:
    unordered_map<int, Node*> Map; // val,Node*
    vector<int> result;

    void helper(Node* root) {
        if (!root) return;
        for (auto n : root->children) {
            helper(n);
        }
        result.push_back(root->val);
    }
};