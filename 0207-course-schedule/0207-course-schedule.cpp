class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // convert into adj list
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        // return !usingDFS(numCourses, adj);
        return usingBFS(adj);
    }

    bool usingDFS(int V, vector<vector<int>>& adj) {
        vector<int> pathVis(V, 0);
        vector<int> vis(V, 0);
        vector<int> topo;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, pathVis, topo)) return true;
            }
        }

        return false;
    }

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, vector<int>& topo) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto nbr : adj[node]) {
            if(!vis[nbr]) {
                if(dfs(nbr, adj, vis, pathVis, topo)) return true;
            }

            else if(pathVis[nbr]) return true;
        }

        pathVis[node] = 0;
        return false;
    }

    bool usingBFS(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> topo;
        vector<int> vis(n, 0);
        vector<int> indegree(n, 0);

        for(int i = 0; i < n; i++) {
            for(auto node : adj[i]) indegree[node]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto nbr : adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }

        return topo.size() == n;
    }
};