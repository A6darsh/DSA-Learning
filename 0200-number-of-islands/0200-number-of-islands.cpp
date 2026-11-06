class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }

    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({row, col});   // {row, col}
        vis[row][col] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // visit nbrs
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(0 <= nr && nr < n && 0 <= nc && nc < m && !vis[nr][nc] && grid[nr][nc] == '1') {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};