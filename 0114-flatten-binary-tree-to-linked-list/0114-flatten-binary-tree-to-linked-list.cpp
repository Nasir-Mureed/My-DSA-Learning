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
   void VLR(TreeNode* root, vector<int>& arr) 
    {
        if (!root) return;
        arr.push_back(root->val);
        VLR(root->left, arr);
        VLR(root->right, arr);
    }

public:
void flatten(TreeNode* root) 
{
    if (!root) return;
    
    vector<int> arr;
    VLR(root, arr);
    
     //memory leaks
    TreeNode* curr = root;
    curr->left = nullptr;
    
    for (int i = 1; i < arr.size(); i++) {
        curr->right = new TreeNode(arr[i]);
        curr = curr->right;
    }

}
};