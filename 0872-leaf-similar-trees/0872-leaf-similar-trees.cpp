class Solution {
    void collectLeaves(TreeNode* node, vector<int>& leaves) {
        if (!node) return;
        
        // Leaf node
        if (!node->left && !node->right) {
            leaves.push_back(node->val);
            return;
        }
        
        // Traverse left subtree first, then right
        collectLeaves(node->left, leaves);
        collectLeaves(node->right, leaves);
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        collectLeaves(root1, leaves1);
        collectLeaves(root2, leaves2);
        
        return leaves1 == leaves2;
    }
};