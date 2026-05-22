class Solution {
public:
    bool rotateString(string s, string goal) {

        int n = s.size();

        if (n != goal.size()) {
            return false;
        }

        string temp = s + s;

        return temp.find(goal) != string::npos;
    }
};