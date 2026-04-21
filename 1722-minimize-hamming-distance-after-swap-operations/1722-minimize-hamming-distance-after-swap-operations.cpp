class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        vector<int> parent(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(auto &sw : allowedSwaps) {
            int u = sw[0];
            int v = sw[1];

            int pu = find(parent, u);
            int pv = find(parent, v);

            if(pu != pv) {
                parent[pu] = pv;
            }
        }

        unordered_map<int, vector<int>> groups;

        for(int i = 0; i < n; i++) {
            int root = find(parent, i);
            groups[root].push_back(i);
        }

        int mismatch = 0;

        for(auto &entry : groups) {
            auto &list = entry.second;

            unordered_map<int, int> freq;

            for(int idx : list) {
                int val = source[idx];
                freq[val]++;
            }

            for(int idx : list) {
                int val = target[idx];

                if(freq.count(val) && freq[val] > 0) {
                    freq[val]--;
                } else {
                    mismatch++;
                }
            }
        }

        return mismatch;
    }

private:
    int find(vector<int>& parent, int x) {
        if(parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};