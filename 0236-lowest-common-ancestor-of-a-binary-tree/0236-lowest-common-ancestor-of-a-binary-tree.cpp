/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
    bool  found(TreeNode* root , TreeNode* ans)
    {
        if(!root)
            return false; //not found
        if(root==ans)
            return true; // found
        bool status=found(root->left,ans);
        if(status) // if found no need to check further
        {
            return true; 
        }
        else
        {
            return found(root->right,ans);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==p || root==q)
        {
           return root;
        }
        if(found(root->left,p)) // find p in left
        {
            if(found(root->left,q)) // find q in left 
            {
                return lowestCommonAncestor(root->left,p,q);
            }
            else // q must be right
            {
                return root;
            }
        }
        else  // p must be in right
        {
            if(found(root->left,q)) // find q in left 
            {
                return root;
            }
            else // q must be right
            {
                return lowestCommonAncestor(root->right,p,q);
            }
        }
    }
};