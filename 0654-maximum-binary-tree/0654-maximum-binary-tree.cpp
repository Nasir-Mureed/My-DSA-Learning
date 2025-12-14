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
    TreeNode* DFS(int s,int e,vector<int>& nums)
    {
        if(s>e ) return nullptr;
        //find max
        int maxVal=nums[s],max=s;
        for(int i=s;i<=e;i++)
        {
            if(nums[i]>maxVal)
            {
                maxVal=nums[i];
                max=i;
            }
        }

        TreeNode* root=new TreeNode(nums[max]);
        root->left=DFS(s,max-1,nums);
        root->right=DFS(max+1,e,nums);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return DFS(0,nums.size()-1,nums);
        
    }
};