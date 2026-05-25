class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> reach(n, false);
        reach[0] = true;
        int usable = 0;
        for (int i = 1; i < n; i++) {
            int left = i - maxJump;
            int right = i - minJump;
            if (right >= 0 && reach[right]) {
                usable++;
            }
            if (left - 1 >= 0 && reach[left - 1]) {
                usable--;
            }
            if (s[i] == '0' && usable > 0) {
                reach[i] = true;
            }
        }
        return reach[n - 1];
    }
};