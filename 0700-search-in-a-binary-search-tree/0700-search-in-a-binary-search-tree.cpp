class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        return iterative(root, val);
        // return recursive(root, val);
    }

    TreeNode* iterative(TreeNode* root, int val) {
        TreeNode* node = root;

        while(node) {
            if(node->val == val) return node;
            node = node->val > val ? node->left : node->right;
        }

        return node;
    }

    TreeNode* recursive(TreeNode* root, int val) {
        if(root == NULL || root->val == val) return root;

        if(root->val > val) return recursive(root->left, val);
        if(root->val < val) return recursive(root->right, val);

        return root;
    }
};