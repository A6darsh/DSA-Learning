class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        // return iterative(root, val);
        return recursive(root, val);
    }

    

    TreeNode* recursive(TreeNode* root, int val) {
        if(root == NULL || root->val == val) return root;

        if(root->val > val) return recursive(root->left, val);
        if(root->val < val) return recursive(root->right, val);

        return root;
    }
};