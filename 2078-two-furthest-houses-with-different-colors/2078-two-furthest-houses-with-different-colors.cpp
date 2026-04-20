class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int first = colors[0];
        int last = colors[n - 1];

        int maxDist = 0;

        for (int j = n - 1; j >= 0; j--) {
            if (colors[j] != first) {
                int dist = j - 0;
                maxDist = dist;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (colors[i] != last) {
                int dist = (n - 1) - i;
                if (dist > maxDist) {
                    maxDist = dist;
                }
                break;
            }
        }

        return maxDist;
    }
};