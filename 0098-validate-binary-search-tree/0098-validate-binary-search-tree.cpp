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
     TreeNode* prev=NULL;
  public:
    bool isValidBST(TreeNode* root) 
    {
        // code here
        if(!root)
            return true;
        if(root->left)
        {
            if(root->val<=root->left->val) return false;
            if( ! isValidBST(root->left)) return false;
        }
        if(prev)
        {
            if(root->val<= prev->val) return false;
        }
        prev=root;
        if(root->right)
        {
            if(root->val >= root->right->val) return false;
            if( ! isValidBST(root->right)) return false;
        }
        
        return true;
        
    }
};