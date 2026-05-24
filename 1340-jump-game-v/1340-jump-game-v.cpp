class Solution {
public:
    
    int dfs(int idx, vector<int>& arr, int d, vector<int>& dp) {
        
        if (dp[idx] != 0) {
            return dp[idx];
        }

        int best = 1;
        int n = arr.size();

        for (int j = idx - 1; j >= max(0, idx - d); j--) {

            if (arr[j] >= arr[idx]) {
                break;
            }

            int curr = 1 + dfs(j, arr, d, dp);
            best = max(best, curr);
        }

        for (int j = idx + 1; j <= min(n - 1, idx + d); j++) {

            if (arr[j] >= arr[idx]) {
                break;
            }

            int curr = 1 + dfs(j, arr, d, dp);
            best = max(best, curr);
        }

        dp[idx] = best;

        return best;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        vector<int> dp(n, 0);

        int ans = 1;

        for (int i = 0; i < n; i++) {

            int val = dfs(i, arr, d, dp);
            ans = max(ans, val);
        }

        return ans;
    }
};