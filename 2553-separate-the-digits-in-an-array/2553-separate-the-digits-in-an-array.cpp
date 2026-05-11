class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> ans;
        
        for (int val : nums) {
            
            string curr = to_string(val);
            
            for (char ch : curr) {
                ans.push_back(ch - '0');
            }
        }
        
        return ans;
    }
};