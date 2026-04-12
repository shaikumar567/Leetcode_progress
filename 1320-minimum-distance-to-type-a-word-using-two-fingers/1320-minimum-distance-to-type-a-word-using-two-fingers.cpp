class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        
        vector<int> dp(26, 0);
        
        int total = 0;
        
        for (int i = 0; i < n - 1; i++) {
            int curr = word[i] - 'A';
            int next = word[i + 1] - 'A';
            
            int moveCost = getDist(curr, next);
            total += moveCost;
            
            vector<int> temp = dp; 
            
            for (int j = 0; j < 26; j++) {
                if (dp[j] > temp[j]) {
                    temp[j] = dp[j];
                }
                
                int saved = moveCost - getDist(j, next);
                int candidate = dp[j] + saved;
                
                if (candidate > temp[curr]) {
                    temp[curr] = candidate;
                }
            }
            
            dp = temp;
        }
        
        int maxSaved = 0;
        for (int i = 0; i < 26; i++) {
            if (dp[i] > maxSaved) {
                maxSaved = dp[i];
            }
        }
        
        return total - maxSaved;
    }
    
private:
    int getDist(int a, int b) {
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        
        int dx = abs(x1 - x2);
        int dy = abs(y1 - y2);
        
        return dx + dy;
    }
};