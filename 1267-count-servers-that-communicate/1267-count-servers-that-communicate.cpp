class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cntServers = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    int cnt = 0;
                    dfs(i, j, cnt, grid, vis);

                    if(cnt >= 2) cntServers += cnt;
                }
            }
        }

        return cntServers;
    }

    void dfs(int row, int col, int &cnt, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        cnt++;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            int nr = i;
            int nc = col;
            // int nr = row + dr[i];
            // int nc = col + dc[i];

            if(/*0 <= nr && nr < n && 0 <= nc && nc < m &&*/ !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc, cnt, grid, vis);
            }
        }

        for(int j = 0; j < m; j++) {
            if(!vis[row][j] && grid[row][j] == 1) {
                dfs(row, j, cnt, grid, vis);
            }
        }
    }
};