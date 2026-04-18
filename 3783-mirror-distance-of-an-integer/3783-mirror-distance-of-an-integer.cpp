class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n;
        int rev = 0;

        while (temp > 0) {
            int digit = temp % 10;
            rev = rev * 10 + digit;
            temp = temp / 10;
        }

        int diff = n - rev;

        if (diff < 0) {
            diff = -diff;
        }

        return diff;
    }
};