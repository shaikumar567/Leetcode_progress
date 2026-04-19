class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int maxDist = 0;

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                int curr = j - i;
                if (curr > maxDist) {
                    maxDist = curr;
                }
                j++;
            } else {
                i++;
            }
        }

        return maxDist;
    }
};