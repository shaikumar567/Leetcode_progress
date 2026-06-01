class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        const int NEG = -1000000000;

        vector<vector<int>> prev(n, vector<int>(k + 1, NEG));

        for (int i = 0; i < m; i++) {
            vector<vector<int>> curr(n, vector<int>(k + 1, NEG));

            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                int addCost = (val == 0) ? 0 : 1;

                for (int cost = addCost; cost <= k; cost++) {
                    int best = NEG;

                    if (i == 0 && j == 0) {
                        if (cost == addCost) {
                            best = val;
                        }
                    } else {
                        if (i > 0 && prev[j][cost - addCost] != NEG) {
                            best = max(best,
                                       prev[j][cost - addCost] + val);
                        }

                        if (j > 0 && curr[j - 1][cost - addCost] != NEG) {
                            best = max(best,
                                       curr[j - 1][cost - addCost] + val);
                        }
                    }

                    curr[j][cost] = best;
                }
            }

            prev = move(curr);
        }

        int ans = -1;

        for (int cost = 0; cost <= k; cost++) {
            ans = max(ans, prev[n - 1][cost]);
        }

        return ans < 0 ? -1 : ans;
    }
};