class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1000000007;

        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            int idx = l;

            while (idx <= r) {
                long long temp = nums[idx];

                temp = temp * v;
                temp = temp % mod;

                nums[idx] = (int)temp;

                idx += k;
            }
        }

        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }

        return res;
    }
};