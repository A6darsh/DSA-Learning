class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* node = root;

        while(node) {
            if(node->val > val) {
                if(node->left == NULL) {
                    node->left = new TreeNode(val);
                    break;
                }
                node = node->left;
            }
            else {
                if(node->right == NULL) {
                    node->right = new TreeNode(val);
                    break;
                }
                node = node->right;
            }
        }

        return root;
    }
};