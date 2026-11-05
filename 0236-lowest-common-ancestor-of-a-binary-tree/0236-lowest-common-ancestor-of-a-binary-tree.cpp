class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return approach1(root, p, q);
        return approach2(root, p, q);
    }

    // we do dfs traversal direct (left and right), 
    TreeNode* approach2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;

        TreeNode* left = approach2(root->left, p, q);
        TreeNode* right = approach2(root->right, p, q);

        if(left == NULL) return right;
        else if(right == NULL) return left;

        return root;
    }

    // TC -> O(N) + O(H) 
    // SC -> O(H)
    TreeNode* approach1(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        dfs(root, p, pathP);
        dfs(root, q, pathQ);

        TreeNode* lca = NULL;
        for(int i = 0; i < min(pathP.size(), pathQ.size()); i++) {
            if(pathP[i] != pathQ[i]) break;
            lca = pathQ[i];
        }

        return lca;
    }

    bool dfs(TreeNode* node, TreeNode* target, vector<TreeNode*> &path) {
        if(node == NULL) return false;

        path.push_back(node);

        if(node == target) return true;
        if(dfs(node->left, target, path) || dfs(node->right, target, path)) return true;

        path.pop_back();
        return false;
    }

};