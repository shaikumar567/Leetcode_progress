class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        char a1 = s1[0], a2 = s1[2];
        char b1 = s2[0], b2 = s2[2];

        char c1 = s1[1], c2 = s1[3];
        char d1 = s2[1], d2 = s2[3];

        bool evenMatch = (a1 == b1 && a2 == b2) || (a1 == b2 && a2 == b1);
        bool oddMatch = (c1 == d1 && c2 == d2) || (c1 == d2 && c2 == d1);

        return evenMatch && oddMatch;
    }
};