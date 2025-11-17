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
   
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return NULL;
        if(root->val == key)
        {
            //found
            if(!root->left && ! root->right)  // if leaf node
            {
                delete root;
                return NULL;
            }
            else if(!root->left || ! root->right) // if one child
            {
                TreeNode* temp ;
                if(root->left)
                {
                    temp=root->left;
                    delete root; // deleted 
                    return temp; // return the child
                }
                else
                {
                    temp=root->right;
                    delete root;
                    return temp;
                }
            }
            else     // two child
            {
                TreeNode* temp=root->right; // go right
                TreeNode* tempPar=root;
                while(temp->left) // find lrft most
                {
                    tempPar=temp;
                    temp=temp->left;
                }
                if(tempPar!=root)
                    tempPar->left=temp->right; // universal truth
                temp->left=root->left; 
                if(tempPar!=root) // if not check this then there will be a cycle
                    temp->right= root->right; 
                delete root;
                return temp; //final ..
            }            
        } 
        if(root->val> key)
        {
            root->left=deleteNode(root->left,key);
        }
        else
        {
            root->right=deleteNode(root->right,key);
        }
        return root; 
    }
};