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
    void inorder(TreeNode* root, vector<int>& arr)
    {
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
public:
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> arr;
        inorder(root,arr);
        int st=0,end=arr.size()-1;
        while(st<end)
        {
            if(arr[st]+arr[end]==k) return true;
            else if(arr[st]+arr[end]>k) end--;
            else st++;
        }
        return false;
    }
};