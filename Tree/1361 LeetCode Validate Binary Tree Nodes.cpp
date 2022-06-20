// Link: https://leetcode.com/problems/validate-binary-tree-nodes/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // all childs should have 1 parent.
        vector<int> parent(n,0);
        for (auto i=0; i<n; i++) {
            if (leftChild[i] != -1 && ++parent[leftChild[i]] > 1) return false;
            if (rightChild[i] != -1 && ++parent[rightChild[i]] > 1) return false;
        }

        // root node should have 0 parent.
        int root, totalRoots = 0;
        for (auto i=0; i<n; i++) {
            if (parent[i] == 0)
                totalRoots++, root = i;
        }
        if (totalRoots != 1) return false;

        // apply dfs to count total nodes
        auto count = dfs(root, leftChild, rightChild);
        return (count == n) ? true : false;
    }
private:
    int count = 0;

    int dfs(int root, vector<int>& l, vector<int>& r) {
        if (root == -1) return 0;
        return 1 + dfs(l[root], l, r) + dfs(r[root], l, r);
    }
};