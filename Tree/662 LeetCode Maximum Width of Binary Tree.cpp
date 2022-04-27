// Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*,long long>> q;
        if (root) q.push(make_pair(root,0)); index++;

        bool first = true;
        while (!q.empty()){
            auto sz = q.size();
            for (auto loop=0; loop<sz; loop++){

                TreeNode* root = q.front().first;
                long long i=q.front().second; q.pop();
                level.push_back(i);

                if (root->left)  {
                    q.push(make_pair(root->left, 2*i));
                }
                if (root->right) {
                    q.push(make_pair(root->right, 2*i+1));
                }
            }
            if (!level.empty()){
                maxWidth = max(maxWidth, 1+abs(level[0]-level[level.size()-1]));
            }
            printf("level: ");for (auto i:level) printf("%d,",i);cout<<endl;
            level.clear(); index = 0;
        }
        return (int)maxWidth;
    }
private:
    using pi = pair<TreeNode*,long long>;
    long long index = 0, maxWidth = 0;
    vector<long long> level;
};*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,unsigned long long int>>q;
        q.push({root,1});TreeNode* temp;
        int size;int res=0;int d;
        while(!q.empty()){
            size=q.size();
            if (size == 1){
                q.push({q.front().first,1});
                q.pop();
            }
            d= q.back().second-q.front().second+1;
            res=max(res,d);
            while(size--){
                if(q.front().first->left) q.push({q.front().first->left,(q.front().second*2)});
                if(q.front().first->right) q.push({q.front().first->right,((q.front().second*2)+1)});
                q.pop();
            }
        }
        return res;
    }
};