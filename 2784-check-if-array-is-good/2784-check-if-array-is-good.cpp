class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = nums.size() - 1;

        vector<int> freq(n + 1, 0);

        for (int val : nums) {

            if (val < 1 || val > n) {
                return false;
            }

            freq[val]++;
        }

        for (int i = 1; i < n; i++) {

            if (freq[i] != 1) {
                return false;
            }
        }

        return freq[n] == 2;
    }
};