class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();

        if (rows == 1) return encodedText;

        int cols = n / rows;
        string ans = "";

        for (int start = 0; start < cols; start++) {
            int i = 0;
            int j = start;

            while (i < rows && j < cols) {
                int index = i * cols + j;
                char ch = encodedText[index];

                ans.push_back(ch);
                i++;
                j++;
            }
        }

        int end = ans.length() - 1;

        while (end >= 0 && ans[end] == ' ') {
            end--;
        }

        return ans.substr(0, end + 1);
    }
};