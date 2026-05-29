class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (int val : nums) {
            int sum = 0;
            int curr = val;
            while (curr > 0) {
                sum += curr % 10;
                curr /= 10;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};