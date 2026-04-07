class Robot {
public:
    int width, height;
    int x, y;
    int dir;

    vector<vector<int>> move = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

    vector<string> dirName = {"East", "North", "West", "South"};

    int cycle;

    Robot(int width, int height) {
        this->width = width;
        this->height = height;

        x = 0;
        y = 0;
        dir = 0;

        cycle = 2 * (width + height - 2);
    }
    
    void step(int num) {
        num = num % cycle;

        if (num == 0) num = cycle;

        while (num > 0) {
            int nx = x + move[dir][0];
            int ny = y + move[dir][1];

            // check boundary
            if (nx < 0 || nx >= width || ny < 0 || ny >= height) {
                dir = (dir + 1) % 4;
                continue;
            }

            x = nx;
            y = ny;
            num--;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirName[dir];
    }
};