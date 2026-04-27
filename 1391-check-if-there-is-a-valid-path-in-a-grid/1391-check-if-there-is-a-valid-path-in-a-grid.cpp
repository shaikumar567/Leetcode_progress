class Solution {
public:
    vector<vector<vector<int>>> dirs = {
        {},
        {{0,-1},{0,1}},
        {{-1,0},{1,0}},
        {{0,-1},{1,0}},
        {{0,1},{1,0}},
        {{0,-1},{-1,0}},
        {{0,1},{-1,0}}
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        return dfs(0, 0, grid, vis, m, n);
    }

    bool dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis, int m, int n) {
        if (r == m - 1 && c == n - 1) {
            return true;
        }

        vis[r][c] = true;

        for (auto &move : dirs[grid[r][c]]) {
            int nr = r + move[0];
            int nc = c + move[1];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n || vis[nr][nc]) {
                continue;
            }

            if (!isConnected(r, c, nr, nc, grid)) {
                continue;
            }

            if (dfs(nr, nc, grid, vis, m, n)) {
                return true;
            }
        }

        return false;
    }

    bool isConnected(int r, int c, int nr, int nc, vector<vector<int>>& grid) {
        for (auto &back : dirs[grid[nr][nc]]) {
            if (nr + back[0] == r && nc + back[1] == c) {
                return true;
            }
        }
        return false;
    }
};