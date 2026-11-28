class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            if(q.front()->left) q.push(q.front()->left);
            res.push_back(q.front()->val);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }

        int mn = INT_MAX;
        sort(res.begin(), res.end());
        for(int i = 1; i < res.size(); i++) mn = min(mn, abs(res[i]-res[i-1]));
        return mn;
    }

    void traverse(TreeNode* node, int par, int &ans) {
        if(!node) return;
        ans = min(ans, abs(par-node->val));
        if(node->left) traverse(node->left, node->val, ans);
        if(node->right) traverse(node->right, node->val, ans);
    }
};