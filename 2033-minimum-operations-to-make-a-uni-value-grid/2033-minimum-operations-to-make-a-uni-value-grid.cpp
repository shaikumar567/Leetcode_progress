class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> vals;
        int rem = grid[0][0] % x;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(grid[i][j] % x != rem) {
                    return -1;
                }

                vals.push_back(grid[i][j]);
            }
        }

        sort(vals.begin(), vals.end());

        int target = vals[vals.size() / 2];

        int ops = 0;

        for(int val : vals) {
            int diff = abs(val - target);
            ops += diff / x;
        }

        return ops;
    }
};