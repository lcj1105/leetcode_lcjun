/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) 
            return 0;
        int num_l = maxDepth(root->left);
        int num_r = maxDepth(root->right);
        
        return num_l > num_r ? num_l+1 : num_r +1;
    }
};