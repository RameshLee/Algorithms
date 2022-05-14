// Link: https://leetcode.com/problems/diameter-of-n-ary-tree/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
};
*/

// Approach: diameter of any node in n-ary tree is the sum of heights of two longest subpaths from that node.
class Solution {
public:
    int diameter(Node* root) {
        helper(root);
        return maxDiameter;
    }
private:
    int maxDiameter = 0;

    int helper(Node* root) {
        if (!root) return 0;

        int MaxHeight = 0, secondMaxHeight = 0;
        for (auto it:root->children) {
            int h = helper(it);
            if (h > MaxHeight)  secondMaxHeight = MaxHeight, MaxHeight = h;
            else                secondMaxHeight = max(secondMaxHeight, h);
        }
        maxDiameter = max(maxDiameter, MaxHeight+secondMaxHeight);
        return MaxHeight+1;
    }
};