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
    void DFS(TreeNode* root,int & ans , int& k)
    {
        
        if(!root || k==0) return;
        DFS(root->left,ans,k);
        k--;
        if(k==0)
        {
            ans=root->val;
            return;
        }
        DFS(root->right,ans,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        int ans=-1;
        DFS(root,ans,k);
        return ans;    
    }
};