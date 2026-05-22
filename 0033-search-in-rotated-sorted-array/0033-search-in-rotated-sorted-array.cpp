class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int curr = nums[mid];

            if (curr == target) {
                return mid;
            }

            if (nums[left] <= curr) {
                if (target >= nums[left] && target < curr) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > curr && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};