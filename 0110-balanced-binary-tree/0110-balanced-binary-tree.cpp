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
    int depth(TreeNode* root,int h)
    {
        if(!root)
        {
            return h;
        }
        h++;
        int l=0,r=0;
        l=depth(root->left,h);
        r=depth(root->right,h);
        if(l==-1 || r==-1) return -1;  /// if already -1 
        if(abs(l-r)>1) return -1;   // if height diff >1 then not balannced....
        return l>r?l:r;
    }
    
public:
    bool isBalanced(TreeNode* root) 
    {
        if(depth(root,0)==-1) 
            return false;
        return true;
    }
};