class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1) {
            return 0;
        }

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> visited(n, 0);

        q.push(0);
        visited[0] = 1;

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int curr = q.front();
                q.pop();

                if (curr == n - 1) {
                    return steps;
                }

                int left = curr - 1;

                if (left >= 0 && !visited[left]) {
                    visited[left] = 1;
                    q.push(left);
                }

                int right = curr + 1;

                if (right < n && !visited[right]) {
                    visited[right] = 1;
                    q.push(right);
                }

                if (mp.count(arr[curr])) {

                    vector<int>& same = mp[arr[curr]];

                    for (int idx : same) {

                        if (!visited[idx]) {
                            visited[idx] = 1;
                            q.push(idx);
                        }
                    }

                    mp.erase(arr[curr]);
                }
            }

            steps++;
        }

        return -1;
    }
};