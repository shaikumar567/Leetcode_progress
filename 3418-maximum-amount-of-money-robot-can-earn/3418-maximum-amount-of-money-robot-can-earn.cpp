class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<int>> dp(n, vector<int>(3, INT_MIN));

        for(int k = 0; k < 3; k++) {
            if(coins[0][0] >= 0) {
                dp[0][k] = coins[0][0];
            } else {
                if(k > 0) dp[0][k] = 0;
                else dp[0][k] = coins[0][0];
            }
        }

        for(int i = 0; i < m; i++) {
            vector<vector<int>> curr(n, vector<int>(3, INT_MIN));

            for(int j = 0; j < n; j++) {
                for(int k = 0; k < 3; k++) {

                    if(i == 0 && j == 0) {
                        curr[j][k] = dp[j][k];
                        continue;
                    }

                    int val = coins[i][j];

                    if(dp[j][k] != INT_MIN) {

                        int temp = dp[j][k] + val;
                        curr[j][k] = max(curr[j][k], temp);

                        if(val < 0 && k < 2) {
                            curr[j][k + 1] = max(curr[j][k + 1], dp[j][k]);
                        }
                    }

                    if(j > 0 && curr[j - 1][k] != INT_MIN) {

                        int temp = curr[j - 1][k] + val;
                        curr[j][k] = max(curr[j][k], temp);

                        if(val < 0 && k < 2) {
                            curr[j][k + 1] = max(curr[j][k + 1], curr[j - 1][k]);
                        }
                    }
                }
            }

            dp = curr;
        }

        int res = INT_MIN;
        for(int k = 0; k < 3; k++) {
            res = max(res, dp[n - 1][k]);
        }

        return res;
    }
};