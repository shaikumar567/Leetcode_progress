class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int rows = grid.size();
        int cols = grid[0].size();

        int layers = min(rows, cols) / 2;

        for (int layer = 0; layer < layers; layer++) {

            vector<int> vals;

            int top = layer;
            int left = layer;
            int bottom = rows - layer - 1;
            int right = cols - layer - 1;

            for (int j = left; j <= right; j++) {
                vals.push_back(grid[top][j]);
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                vals.push_back(grid[i][right]);
            }

            for (int j = right; j >= left; j--) {
                vals.push_back(grid[bottom][j]);
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                vals.push_back(grid[i][left]);
            }

            int size = vals.size();
            int rotate = k % size;

            vector<int> rotated(size);

            for (int i = 0; i < size; i++) {

                int next = i - rotate;

                if (next < 0) {
                    next += size;
                }

                rotated[next] = vals[i];
            }

            int idx = 0;

            for (int j = left; j <= right; j++) {
                grid[top][j] = rotated[idx++];
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = rotated[idx++];
            }

            for (int j = right; j >= left; j--) {
                grid[bottom][j] = rotated[idx++];
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = rotated[idx++];
            }
        }

        return grid;
    }
};