class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<bool> visited(n, false);

        return dfs(arr, start, visited);
    }

    bool dfs(vector<int>& arr, int curr, vector<bool>& visited) {
        if (curr < 0 || curr >= arr.size()) {
            return false;
        }

        if (visited[curr]) {
            return false;
        }

        if (arr[curr] == 0) {
            return true;
        }

        visited[curr] = true;

        int jump = arr[curr];

        int forward = curr + jump;
        int backward = curr - jump;

        if (dfs(arr, forward, visited)) {
            return true;
        }

        return dfs(arr, backward, visited);
    }
};