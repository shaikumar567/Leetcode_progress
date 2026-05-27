class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> smallLast(26, -1);
        vector<int> capitalFirst(26, -1);

        int n = word.size();

        for(int i = 0; i < n; i++) {
            char ch = word[i];

            if(ch >= 'a' && ch <= 'z') {
                int idx = ch - 'a';
                smallLast[idx] = i;
            }
            else {
                int idx = ch - 'A';

                if(capitalFirst[idx] == -1) {
                    capitalFirst[idx] = i;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < 26; i++) {

            if(smallLast[i] == -1 || capitalFirst[i] == -1) {
                continue;
            }

            if(smallLast[i] < capitalFirst[i]) {
                ans++;
            }
        }
        return ans;
    }
};