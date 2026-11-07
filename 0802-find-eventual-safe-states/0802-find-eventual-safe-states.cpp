class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);

        for(int i = 0; i < n; i++) 
            dfs(i, graph, vis, pathVis);

        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(!pathVis[i]) res.push_back(i);
        }

        return res;
    }

    bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        // visit nbrs
        for(auto nbr : graph[node]) {
            if(!vis[nbr]) {
                if(dfs(nbr, graph, vis, pathVis)) return true;
            }
            else if(pathVis[nbr]) return true;
        }

        pathVis[node] = 0;
        return false;
    }
};