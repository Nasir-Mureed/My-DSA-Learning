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
    string smallest;
public:
    void dfs(TreeNode* node, string path) 
    {
        if (!node) return;

        path.push_back('a' + node->val);

        //leaf
        if (!node->left && !node->right) 
        {
            string temp = path;
            reverse(temp.begin(), temp.end());
            if (smallest.empty() || temp < smallest) 
            {
                smallest = temp;
            }
            return;
        }

        dfs(node->left, path);
        dfs(node->right, path);
    }

    string smallestFromLeaf(TreeNode* root) 
    {
        smallest = "";
        dfs(root, "");
        return smallest;
    }
};