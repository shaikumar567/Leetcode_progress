class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int rows = boxGrid.size();
        int cols = boxGrid[0].size();

        for (int i = 0; i < rows; i++) {

            int empty = cols - 1;

            for (int j = cols - 1; j >= 0; j--) {

                if (boxGrid[i][j] == '*') {
                    empty = j - 1;
                }

                else if (boxGrid[i][j] == '#') {

                    boxGrid[i][j] = '.';
                    boxGrid[i][empty] = '#';

                    empty--;
                }
            }
        }

        vector<vector<char>> ans(cols, vector<char>(rows));

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                ans[j][rows - 1 - i] = boxGrid[i][j];
            }
        }

        return ans;
    }
};