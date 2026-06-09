class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minVal = nums[0];
        int maxVal = nums[0];

        for (int val : nums) {
            if (val < minVal) {
                minVal = val;
            }
            if (val > maxVal) {
                maxVal = val;
            }
        }
        long long best = (long long)maxVal - minVal;
        return best * k;
    }
};