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
    void dfs(TreeNode* root, string path, vector<string>& res)
    {
        if(!root)
            return;
        if(root && !root->left && !root->right) //leaf node
        {
           path.append(std::to_string(root->val)); //apend char
            res.push_back(path);
            return;
        }
        path.append(std::to_string(root->val)); //apend char
        path.append("->");
        dfs(root->left,path,res);
        dfs(root->right,path,res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        dfs(root,"",res);
        return res;
        
    }
};