class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int diff = abs(i - startIndex);
                int curr = min(diff, n - diff);

                if (curr < ans) {
                    ans = curr;
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};