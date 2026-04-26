class Solution {
public:
    int rows, cols;
    vector<vector<bool>> seen;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool containsCycle(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        seen.assign(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(!seen[i][j]) {
                    if(dfs(grid, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& grid, int x, int y,
             int px, int py, char val) {

        seen[x][y] = true;

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || ny < 0 || nx >= rows || ny >= cols) {
                continue;
            }

            if(grid[nx][ny] != val) {
                continue;
            }

            if(nx == px && ny == py) {
                continue;
            }

            if(seen[nx][ny]) {
                return true;
            }

            if(dfs(grid, nx, ny, x, y, val)) {
                return true;
            }
        }

        return false;
    }
};