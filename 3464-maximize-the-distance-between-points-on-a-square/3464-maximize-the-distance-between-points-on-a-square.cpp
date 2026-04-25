class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> pos(n);
        long long s = side;

        for (int i = 0; i < n; i++) {
            long long x = points[i][0];
            long long y = points[i][1];

            if (x == 0) pos[i] = y;
            else if (y == s) pos[i] = s + x;
            else if (x == s) pos[i] = s * 3 - y;
            else pos[i] = s * 4 - x;
        }

        sort(pos.begin(), pos.end());

        int left = 1;
        int right = (int)((s * 4) / k) + 1;

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid, pos, s, k)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return left;
    }

    bool check(int dist, vector<long long>& pos, long long s, int k) {
        int m = pos.size();
        vector<int> idx(k);
        long long perimeter = s * 4;

        idx[0] = 0;
        long long curr = pos[0];

        for (int i = 1; i < k; i++) {
            int p = lower_bound(pos.begin(), pos.end(), curr + dist) - pos.begin();
            if (p == m) return false;
            idx[i] = p;
            curr = pos[p];
        }

        if (pos[idx[k - 1]] - pos[0] <= perimeter - dist) return true;

        for (idx[0] = 1; idx[0] < idx[1]; idx[0]++) {
            for (int j = 1; j < k; j++) {
                while (idx[j] < m && pos[idx[j]] < pos[idx[j - 1]] + dist) {
                    idx[j]++;
                }
                if (idx[j] == m) return false;
            }

            if (pos[idx[k - 1]] - pos[idx[0]] <= perimeter - dist) {
                return true;
            }
        }

        return false;
    }
};