#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            mp[val].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for (auto &entry : mp) {
            vector<int> &list = entry.second;
            int size = list.size();
            
            if (size < 3) continue;
            
            for (int i = 0; i < size - 2; i++) {
                int first = list[i];
                
                for (int j = i + 2; j < size; j++) {
                    int last = list[j];
                    
                    int dist = 2 * (last - first);
                    if (dist < ans) {
                        ans = dist;
                    }
                }
            }
        }
        
        if (ans == INT_MAX) return -1;
        return ans;
    }
};