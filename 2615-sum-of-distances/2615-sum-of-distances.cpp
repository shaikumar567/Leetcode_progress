class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto &entry : mp) {
            vector<int> &list = entry.second;
            int size = list.size();

            vector<long long> prefix(size);
            prefix[0] = list[0];

            for (int i = 1; i < size; i++) {
                prefix[i] = prefix[i - 1] + list[i];
            }

            for (int i = 0; i < size; i++) {
                int curr = list[i];

                long long left = 0;
                if (i > 0) {
                    long long total = prefix[i - 1];
                    left = (long long)i * curr - total;
                }

                long long right = 0;
                if (i < size - 1) {
                    long long total = prefix[size - 1] - prefix[i];
                    right = total - (long long)(size - i - 1) * curr;
                }

                res[curr] = left + right;
            }
        }

        return res;
    }
};