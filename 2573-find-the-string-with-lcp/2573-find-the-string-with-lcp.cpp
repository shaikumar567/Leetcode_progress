class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        // Step 1: Union positions with lcp > 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] > 0) {
                    unite(i, j, parent);
                }
            }
        }

        // Step 2: Assign characters
        vector<char> res(n, '#');
        char curr = 'a';

        unordered_map<int, char> mp;

        for (int i = 0; i < n; i++) {
            int root = find(i, parent);

            if (mp.find(root) == mp.end()) {
                if (curr > 'z') return "";
                mp[root] = curr;
                curr++;
            }

            res[i] = mp[root];
        }

        // Step 3: Validate using dp
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (res[i] == res[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 0;
                }

                if (dp[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }

        return string(res.begin(), res.end());
    }

private:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }

    void unite(int a, int b, vector<int>& parent) {
        int pa = find(a, parent);
        int pb = find(b, parent);

        if (pa != pb) {
            parent[pb] = pa;
        }
    }
};