class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, -1); // -1 -> No Color
        for(int i = 0; i < n; i++) {
            if(vis[i] == -1) {
                // if(!bfs(i, graph, vis)) return false;
                if(!dfs(i, 0, graph, vis)) return false;
            }
        }

        return true;
    }

    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = color;

        for(auto nbr : graph[node]) {
            if(vis[nbr] == -1) {
                if(!dfs(nbr, !color, graph, vis)) return false;
            }

            else if(vis[nbr] == vis[node]) return false;
        }

        return true;
    }

    bool bfs(int start, vector<vector<int>>& graph, vector<int>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            // visit nbrs
            for(auto nbr : graph[node]) {
                if(vis[nbr] == -1) {
                    int nbrColor = vis[node];
                    q.push(nbr);
                    vis[nbr] = 1 - nbrColor;
                }

                // if nbr color and curr node color are same then return false
                else if(vis[nbr] == vis[node]) return false;
            }
        }

        return true;
    }
};