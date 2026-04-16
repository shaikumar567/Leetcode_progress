class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> res(queries.size());
        
        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i];
            int val = nums[idx];
            
            vector<int>& vec = mp[val];
            
            if (vec.size() == 1) {
                res[i] = -1;
                continue;
            }
            
            int pos = lower_bound(vec.begin(), vec.end(), idx) - vec.begin();
            
            int sz = vec.size();
            
            int prev = vec[(pos - 1 + sz) % sz];
            int next = vec[(pos + 1) % sz];
            
            int d1 = abs(idx - prev);
            int d2 = abs(idx - next);
            
            int dist1 = min(d1, n - d1);
            int dist2 = min(d2, n - d2);
            
            res[i] = min(dist1, dist2);
        }
        
        return res;
    }
};