class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> st;

        for (auto &obs : obstacles) {
            long long key = ((long long)obs[0] << 32) | (obs[1] & 0xffffffffLL);
            st.insert(key);
        }

        int x = 0, y = 0;
        int dir = 0;

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int maxDist = 0;

        for (int cmd : commands) {

            if (cmd == -1) {
                dir = (dir + 1) % 4;
            }
            else if (cmd == -2) {
                dir = (dir + 3) % 4;
            }
            else {
                int steps = cmd;

                for (int i = 0; i < steps; i++) {
                    int nextX = x + dx[dir];
                    int nextY = y + dy[dir];

                    long long key = ((long long)nextX << 32) | (nextY & 0xffffffffLL);

                    if (st.find(key) != st.end()) {
                        break;
                    }

                    x = nextX;
                    y = nextY;

                    int currDist = x * x + y * y;
                    if (currDist > maxDist) {
                        maxDist = currDist;
                    }
                }
            }
        }
        return maxDist;
    }
};