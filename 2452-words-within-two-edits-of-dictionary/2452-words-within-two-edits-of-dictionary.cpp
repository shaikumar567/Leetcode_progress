class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for (string &q : queries) {
            bool found = false;

            for (string &d : dictionary) {
                int diff = 0;

                for (int i = 0; i < q.size(); i++) {
                    if (q[i] != d[i]) {
                        diff++;
                        if (diff > 2) break;
                    }
                }

                if (diff <= 2) {
                    found = true;
                    break;
                }
            }

            if (found) ans.push_back(q);
        }

        return ans;
    }
};