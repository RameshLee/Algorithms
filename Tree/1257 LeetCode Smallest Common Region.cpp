// Link: https://leetcode.com/problems/smallest-common-region/

// Variation of lowest common ancestor problem
class Node {
public:
    string val;
    vector<Node*> children;

    Node(string s) : val(s) {}
    ~Node() {}
};

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        // build tree out of the regions
        for (auto local:regions) {
            for (auto s:local)
                if (!nodeMap.count(s)) {
                    nodeMap[s] = new Node(s); // create the nodes (root/children)
                    if (local[0] != s)
                        nodeMap[local[0]]->children.push_back(nodeMap[s]); // append childrens
                }
        }

        // find the LCA of region1 & region2
        lowestCommonAncestor(nodeMap[regions[0][0]], nodeMap[region1], nodeMap[region2]);
        return LCA->val;
    }
private:
    unordered_map<string, Node*> nodeMap;
    Node* LCA;

    int lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if (!root) return 0;

        auto marker = 0;
        for (auto n:root->children) { // find whether p/q present in the child n
            marker += lowestCommonAncestor(n, p, q);
        }
        auto curr = (root->val==p->val || root->val==q->val) ? 1 : 0; // find whether curr has p/q

        if (marker+curr >= 2) LCA = root; // update LCA
        return (marker || curr) ? 1 : 0;
    }
};