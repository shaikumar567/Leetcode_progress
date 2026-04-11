class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for (auto &entry : mp) {
            vector<int> &list = entry.second;
            
            if (list.size() < 3) continue;
            
            for (int i = 0; i + 2 < list.size(); i++) {
                int first = list[i];
                int last = list[i + 2];
                
                int dist = 2 * (last - first);
                
                if (dist < ans) {
                    ans = dist;
                }
            }
        }
        
        return (ans == INT_MAX ? -1 : ans);
    }
};