class Solution {
public:
    // TC -> O(N)
    // SC -> O(N), Auxiliary Space
    // we do dfs traversal (left and right)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
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