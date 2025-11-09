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
    vector<vector<int>> res;
    void helper(TreeNode* root,vector<int> &vec,int sum,int target)
    {
        if(!root)
            return;
        sum+=root->val;
        if(!root->left && !root->right && sum==target)
        {
            vec.push_back(root->val);
            res.push_back(vec);
            vec.pop_back();
            return;
        }
        vec.push_back(root->val);
        helper(root->left,vec,sum,target);
        helper(root->right,vec,sum,target);
        vec.pop_back();

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> vec;
        helper(root,vec,0,targetSum);
        return res;
        
    }
};