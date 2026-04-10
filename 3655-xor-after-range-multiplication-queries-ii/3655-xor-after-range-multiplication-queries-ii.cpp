#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        
        while (exp > 0) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    long long modInv(long long n) {
        return power(n, MOD - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int limit = sqrt(n);

        unordered_map<int, vector<vector<int>>> lightK;

        // process queries
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k >= limit) {
                // heavy case
                for (int i = l; i <= r; i += k) {
                    long long val = (1LL * nums[i] * v) % MOD;
                    nums[i] = (int)val;
                }
            } else {
                lightK[k].push_back(q);
            }
        }

        // handle light k
        for (auto &entry : lightK) {
            int k = entry.first;
            auto &queryList = entry.second;

            vector<long long> diff(n, 1);

            for (auto &q : queryList) {
                int l = q[0], r = q[1], v = q[3];

                diff[l] = (diff[l] * v) % MOD;

                int steps = (r - l) / k;
                int next = l + (steps + 1) * k;

                if (next < n) {
                    diff[next] = (diff[next] * modInv(v)) % MOD;
                }
            }

            for (int i = 0; i < n; i++) {
                if (i >= k) {
                    diff[i] = (diff[i] * diff[i - k]) % MOD;
                }
                nums[i] = (int)((1LL * nums[i] * diff[i]) % MOD);
            }
        }

        int ans = 0;
        for (int val : nums) {
            ans ^= val;
        }

        return ans;
    }
};