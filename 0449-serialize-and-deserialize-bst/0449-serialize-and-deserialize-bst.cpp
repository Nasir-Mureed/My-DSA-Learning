/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string res;
        res.append("[");
        if(root)
        {
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty())
            {
                int s=q.size();
                for(int i=0;i<s;i++)
                {
                    TreeNode* temp=q.front();
                    q.pop();
                    if(temp)
                    {
                        res+=(to_string(temp->val));
                        q.push(temp->left);
                        q.push(temp->right);
                    }
                    else
                    {
                        res+="#"; //null
                    }
                    res+=",";
                }
            }
            res.pop_back();
        }
        res.append("]");
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if (data == "[]") return nullptr;

        string content = data.substr(1, data.length() - 2);
        vector<string> values;
        stringstream ss(content);
        string token;
        
        while (getline(ss, token, ',')) {
            values.push_back(token);
        }
        
        // Now build tree using values[0], values[1], etc.
        if (values.empty() || values[0] == "#") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(values[0]));
        queue<TreeNode*> q;
        q.push(root);
        
        int index = 1;
        while (!q.empty() && index < values.size()) 
        {
            TreeNode* node = q.front();
            q.pop();
            
            // Left child
            if (index < values.size() && values[index] != "#") {
                node->left = new TreeNode(stoi(values[index]));
                q.push(node->left);
            }
            index++;
            
            // Right child
            if (index < values.size() && values[index] != "#") {
                node->right = new TreeNode(stoi(values[index]));
                q.push(node->right);
            }
            index++;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;