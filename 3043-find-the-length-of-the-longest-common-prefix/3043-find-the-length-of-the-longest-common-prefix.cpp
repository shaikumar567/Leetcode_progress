class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<int> prefixes;

        for (int val : arr1) {

            int curr = val;

            while (curr > 0) {
                prefixes.insert(curr);
                curr /= 10;
            }
        }

        int ans = 0;

        for (int val : arr2) {

            int curr = val;

            while (curr > 0) {

                if (prefixes.count(curr)) {

                    int len = to_string(curr).length();

                    if (len > ans) {
                        ans = len;
                    }

                    break;
                }

                curr /= 10;
            }
        }

        return ans;
    }
};