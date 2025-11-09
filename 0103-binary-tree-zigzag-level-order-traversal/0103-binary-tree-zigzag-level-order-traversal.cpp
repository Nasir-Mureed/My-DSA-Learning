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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        bool traversal=false;  // for zigzag
        while(!q.empty())
        {
            stack<TreeNode*> st;
            int levelSize=q.size();
            for(int i=0;i<levelSize;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                st.push(temp);
                level.push_back(temp->val);               
            }
            while(!st.empty())
            {
                TreeNode* temp=st.top();
                st.pop();
                if(traversal)
                {
                    if(temp->left) 
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                }
                else
                {
                    if(temp->right)
                        q.push(temp->right);
                    if(temp->left) 
                        q.push(temp->left);
                }

            }
            traversal=!traversal; // shift
            res.push_back(level);
            level.clear();

        }
        return res;
        
    }
};