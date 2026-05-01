class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        long long curr = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            curr += 1LL * i * nums[i];
        }

        long long maxVal = curr;

        for (int k = 1; k < n; k++) {
            int moved = nums[n - k];

            long long next = curr + sum - 1LL * n * moved;

            curr = next;

            if (curr > maxVal) {
                maxVal = curr;
            }
        }

        return (int)maxVal;
    }
};