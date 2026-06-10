class SparseTable {
    int n;
    int maxLog;
    vector<vector<int>> mx;
    vector<vector<int>> mn;
    vector<int> lg;

public:
    SparseTable(vector<int>& nums) {
        n = nums.size();
        maxLog = 32 - __builtin_clz(n) + 1;

        mx.assign(n, vector<int>(maxLog));
        mn.assign(n, vector<int>(maxLog));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        for (int i = 0; i < n; i++) {
            mx[i][0] = nums[i];
            mn[i][0] = nums[i];
        }

        for (int j = 1; j < maxLog; j++) {
            int len = 1 << j;

            for (int i = 0; i + len <= n; i++) {
                mx[i][j] = max(
                    mx[i][j - 1],
                    mx[i + (len >> 1)][j - 1]
                );

                mn[i][j] = min(
                    mn[i][j - 1],
                    mn[i + (len >> 1)][j - 1]
                );
            }
        }
    }

    int getMax(int l, int r) {
        int k = lg[r - l + 1];

        return max(
            mx[l][k],
            mx[r - (1 << k) + 1][k]
        );
    }

    int getMin(int l, int r) {
        int k = lg[r - l + 1];

        return min(
            mn[l][k],
            mn[r - (1 << k) + 1][k]
        );
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SparseTable st(nums);

        priority_queue<array<long long, 3>> pq;

        for (int l = 0; l < n; l++) {
            long long val =
                (long long)st.getMax(l, n - 1) -
                (long long)st.getMin(l, n - 1);

            pq.push({val, l, n - 1});
        }

        long long ans = 0;

        while (k--) {
            auto curr = pq.top();
            pq.pop();

            long long val = curr[0];
            int l = (int)curr[1];
            int r = (int)curr[2];

            ans += val;

            if (r > l) {
                long long nextVal =
                    (long long)st.getMax(l, r - 1) -
                    (long long)st.getMin(l, r - 1);

                pq.push({nextVal, l, r - 1});
            }
        }
        return ans;
    }
};