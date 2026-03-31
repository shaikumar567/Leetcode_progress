class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        int len = n + m - 1;

        vector<char> res(len, '?');
        vector<bool> fixed(len, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    char curr = str2[j];

                    if (res[i + j] == '?' || res[i + j] == curr) {
                        res[i + j] = curr;
                        fixed[i + j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < len; i++) {
            if (res[i] == '?') {
                res[i] = 'a';
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (res[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool changed = false;

                    for (int j = m - 1; j >= 0; j--) {
                        int idx = i + j;

                        if (fixed[idx]) continue;

                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c != str2[j]) {
                                res[idx] = c;
                                changed = true;
                                break;
                            }
                        }

                        if (changed) break;
                    }

                    if (!changed) return "";
                }
            }
        }

        string ans = "";
        for (char c : res) ans += c;

        return ans;
    }
};