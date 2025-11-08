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
class Solution {
    bool helper(TreeNode* root,int sum,int targetSum)
    {
        
        if(!root)
            return false;
        if(root && root->left==nullptr && root->right==nullptr && sum+root->val==targetSum)
        {
            return true;
        }
        sum+=root->val;
        if(helper(root->left,sum,targetSum))
            return true;
        if(helper(root->right,sum,targetSum))
            return true;
        return false;
    }
public:
    
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)   // if empty
            return false;
        return helper(root,0,targetSum);
    }
};