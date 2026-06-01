class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        int total = 0;
        int cnt = 0;

        for (int i = cost.size() - 1; i >= 0; i--) {
            cnt++;

            if (cnt == 3) {
                cnt = 0;
                continue;
            }

            total += cost[i];
        }

        return total;
    }
};