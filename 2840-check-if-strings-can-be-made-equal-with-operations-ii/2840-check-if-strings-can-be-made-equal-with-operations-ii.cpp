class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();

        vector<int> even(26, 0);
        vector<int> odd(26, 0);

        for(int i = 0; i < n; i++) {
            char c1 = s1[i];
            char c2 = s2[i];

            if(i % 2 == 0) {
                even[c1 - 'a']++;
                even[c2 - 'a']--;
            } else {
                odd[c1 - 'a']++;
                odd[c2 - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(even[i] != 0) return false;
            if(odd[i] != 0) return false;
        }

        return true;
    }
};