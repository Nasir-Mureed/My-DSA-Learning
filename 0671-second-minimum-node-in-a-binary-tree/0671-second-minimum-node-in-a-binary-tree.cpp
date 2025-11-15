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
    void helper(TreeNode* root,int& min, int& smin,bool& flag)
    {
        if(!root)
            return;
        if(root->val<=min)
        {
            min=root->val;
        }
        else
        {
            if(root->val<=smin)
            {
                flag=true;
                smin=root->val;
            }
        }
        helper(root->left,min,smin,flag);
        helper(root->right,min,smin,flag);
    }
public:
    int findSecondMinimumValue(TreeNode* root) 
    {
        if(!root)
            return -1;
        int smin=INT_MAX;
        int min=INT_MAX;
        bool flag= false;
        helper(root,min,smin,flag);
        if(!flag) return -1;
        return smin;
    }
};