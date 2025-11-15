/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
{
    string encode;
    if (!root)
        return encode;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode* temp = q.front();
            q.pop();
            if (!temp)
            {
                encode += "$,"; //nullptr
            }
            else
            {
                encode += to_string(temp->val);
                encode += ",";
            }
            if (temp)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
    }
    return encode;

}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data.empty())
            return nullptr;
        stringstream ss(data);
        string token;
        queue<string> t;
        while(getline(ss,token,','))
        {
            t.push(token);
        }
        TreeNode* root= new TreeNode(stoi(t.front()));
        t.pop();
        queue<TreeNode*> q;
        q.push(root);
        while(!t.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(t.front()!="$")
                {
                    temp->left=new TreeNode(stoi(t.front()));
                    q.push(temp->left);
                }
                t.pop();
                if(t.front()!="$")
                {
                    temp->right=new TreeNode(stoi(t.front()));
                    q.push(temp->right);
                }
                t.pop();
            
            }
        }
        return  root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));