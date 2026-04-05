class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0;
        int horizontal = 0;

        for(int i = 0; i < moves.size(); i++) {
            char curr = moves[i];

            if(curr == 'U') {
                vertical++;
            } 
            else if(curr == 'D') {
                vertical--;
            } 
            else if(curr == 'R') {
                horizontal++;
            } 
            else {
                horizontal--;
            }
        }

        if(vertical == 0 && horizontal == 0) {
            return true;
        }
        return false;
    }
};