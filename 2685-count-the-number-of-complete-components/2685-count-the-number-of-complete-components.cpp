class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int cntCompo = 0;
        vector<int> vis(n);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int degree = 0; // number of edges connected to that nodes
                int nodes = 0;  // number of nodes in current component
                dfs(i, adj, degree, nodes, vis);

                if(degree == nodes*(nodes-1)) cntCompo++;
                // WHY? Because every undirected edge is counted twice in the degree sum.
            }
        }

        return cntCompo;
    }

    void dfs(int node, vector<vector<int>>& adj, int &degree, int &nodes, vector<int>& vis) {
        nodes++;
        vis[node] = 1;
        degree += adj[node].size();

        for(auto nbr : adj[node]) {
            if(!vis[nbr]) {
                dfs(nbr, adj, degree, nodes, vis);
            }
        }
    }
};