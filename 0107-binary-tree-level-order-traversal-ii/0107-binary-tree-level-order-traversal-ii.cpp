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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>>res;
        if(!root) return res;
        stack<int> level_Len;
        stack<int> level_val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            level_Len.push(s);
            for(int i=0;i<s;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                level_val.push(temp->val);
                if(temp->right) q.push(temp->right);
                if(temp->left)  q.push(temp->left);
            }
        }
        vector<int> level;
        while(!level_val.empty())
        {
            int size=level_Len.top();
            level_Len.pop();
            for(int i=0;i<size;i++)
            {
                level.push_back(level_val.top());
                level_val.pop();
            }
            res.push_back(level);
            level.clear();
        }
        return res;
        
    }
};