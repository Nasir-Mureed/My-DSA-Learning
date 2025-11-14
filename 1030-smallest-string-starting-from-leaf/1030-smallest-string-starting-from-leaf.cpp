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
    string reverseCompare(string s1,string s2)
    {
        if(s1==s2)
            return s1;
        int n1=s1.size();
        int n2=s2.size();
        n1--;
        n2--;
        while(n1>=0 && n2>=0)
        {
            if(s1[n1]<s2[n2])
                return s1;
            else if(s2[n2]<s1[n1])
                return s2;
            else
            {
                n1--;
                n2--;
            }
        }
        if(n1!=-1)
            return s2; 
        if(n2!=-1)
            return s1;
        return s1;//equal
    }
    string helper(TreeNode* root,string str)
    {
        if(!root)
            return str;
        str+=(char(root->val+97));
        string s1,s2;
        s1= helper(root->left,str);
        s2=helper(root->right,str);
        if(s1==str) 
            return s2;
        if(s2==str)
            return s1;
       
        return reverseCompare(s1,s2);

    }
public:
   
    string smallestFromLeaf(TreeNode* root) 
    {
        string s=helper(root,"");
        reverse(s.begin(),s.end());
        return s;
    }
};