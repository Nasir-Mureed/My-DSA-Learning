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
    void count(TreeNode* root,int max,int& res)
    {
        if(!root)
            return;
        if(max<=root->val)
            res++;
        count(root->left,max>root->val?max:root->val,res);
        count(root->right,max>root->val?max:root->val,res);
    }
public:
    int goodNodes(TreeNode* root) 
    {
        int res=0;
        count(root,root->val,res);
        return res;
        
    }
};