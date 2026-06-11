class Solution {
    static constexpr long long MOD = 1000000007LL;

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> graph(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.push(1);
        visited[1] = true;

        int depth = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int curr = q.front();
                q.pop();

                for (int next : graph[curr]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            if (!q.empty()) {
                depth++;
            }
        }

        return (int)power(2, depth - 1);
    }
private:
    long long power(long long base, int exp) {
        long long ans = 1;

        while (exp > 0) {
            if (exp & 1) {
                ans = (ans * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return ans;
    }
};