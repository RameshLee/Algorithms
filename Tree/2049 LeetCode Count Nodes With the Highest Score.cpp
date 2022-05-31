// Link: https://leetcode.com/problems/count-nodes-with-the-highest-score/

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parent) {
        this->n = parent.size();

        // create nodes
        for (auto i=0; i<n; i++) {
            Map[i] = new TreeNode(i);
        }

        // create connections
         for (auto i=1; i<n; i++) {
            if (!Map[parent[i]]->left)        Map[parent[i]]->left = Map[i];
            else if (!Map[parent[i]]->right)  Map[parent[i]]->right = Map[i];
        }

        // traversal
        helper(Map[0]);
        return Count[maxScore];
    }
private:
    int n;
    unordered_map<int,TreeNode*> Map; // (value,TreeNode)
    unordered_map<long long, int> Count; // (score, nodeCount)
    long long maxScore = 0;

    long long helper(TreeNode* root) {
        if (!root) return 0;

        // get the total nodesets if we cut the curr node
        auto l = helper(root->left);
        auto r = helper(root->right);
        auto remainingNodes = n - (l+r+1);

        // update the score
        long long score = 0;
        if (l || r || remainingNodes)   score = 1;
        if (l)                          score *= l;
        if (r)                          score *= r;
        if (remainingNodes)             score *= remainingNodes;

        // update the result
        Count[score]++;
        if (maxScore < score) maxScore = score;
        return (l+r+1);
    }
};