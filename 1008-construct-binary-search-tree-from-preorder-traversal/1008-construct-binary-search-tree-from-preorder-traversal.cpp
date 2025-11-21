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
    void right(TreeNode* root,int start,int end,vector<int>& arr)
    {
        if(start>end)
            return ;
        root->right= new TreeNode(arr[start]);
        start++; // one move next
        if(start<=end)
        {
            int Lst=0,Led=0;
            if(arr[start-1]>arr[start])
                Lst=start; //left start
            int i=start;
            while(i<=end && arr[start-1]>arr[i])
                i++;
            Led=i-1; // left end
            if(Lst!=0)  // else no node for left
                left(root->right,Lst,Led,arr);
            
            if(i>end) // nothing for right
            {
                return;
            }
            // for right
            int rst=0,red=0;
            rst=i; // right start
            red= end; // right end
            if(rst<=red) // else noNode for right
                right(root->right,rst,red,arr);
        }
        
        
    }
   void left(TreeNode* root,int start,int end , vector<int>& arr)
   {
        if(start>end)
            return ;
        root->left= new TreeNode(arr[start]);
        start++;
        if(start<=end)
        {
            int Lst=0,Led=0;
            if(arr[start-1]>arr[start])
                Lst=start; //left start
            int i=start;
            while(i<=end && arr[start-1]>arr[i])
                i++;
            Led=i-1; // left end
            if(Lst!=0)  // else no node for left
                left(root->left,Lst,Led,arr);

            if(i>end) // nothing for right
            {
                return;
            }
            // for right
            int rst=0,red=0;
            rst=i; // right start
            red= end; // right end
            if(rst<=red) // else noNode for right
                right(root->left,rst,red,arr);
        }
        
        

   } 
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {

        int len= preorder.size();
        if(len==0)
            return NULL;

        TreeNode* dummy= new TreeNode(10000037);
        left(dummy,0,len-1,preorder);
        TreeNode* root=dummy->left; // actual root;
        delete dummy; // removing dummy node
        return root;
        
        
    }
};