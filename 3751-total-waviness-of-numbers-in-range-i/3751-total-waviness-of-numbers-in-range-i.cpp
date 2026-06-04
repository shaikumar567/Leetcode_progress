class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;

        for (int num = num1; num <= num2; num++) {
            total += getWaviness(num);
        }

        return total;
    }

private:
    int getWaviness(int num) {
        string s = to_string(num);

        if (s.size() < 3) {
            return 0;
        }

        int count = 0;

        for (int i = 1; i < (int)s.size() - 1; i++) {
            int left = s[i - 1] - '0';
            int curr = s[i] - '0';
            int right = s[i + 1] - '0';

            bool peak = curr > left && curr > right;
            bool valley = curr < left && curr < right;

            if (peak || valley) {
                count++;
            }
        }

        return count;
    }
};