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
class Solution 
{
    void helper(TreeNode* root, long long int& minDiff, TreeNode* & prev)
    {
        if(!root) return;
        helper(root->left,minDiff,prev);
        if(prev)
        {
            int diff= root->val-prev->val;
            minDiff=minDiff<diff?minDiff:diff;
        }
        prev = root;
        helper(root->right,minDiff,prev);
    }
public:
    int getMinimumDifference(TreeNode* root) 
    {
        long long int minDiff=LONG_MAX;
        TreeNode* prev=NULL;
        helper(root,minDiff,prev);
        return minDiff;
        
    }
};