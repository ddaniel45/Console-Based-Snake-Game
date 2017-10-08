#ifndef GAME_H
#define GAME_H

#include "Canvas.h"

class snake_part {
        public:
            snake_part(int row,int col, char ch = '*');
            int row,col;
            char ch = '*';
        };

class Game
{
    public:
        Game(Canvas* ptr);
        void init();
    private:
        Canvas* screen;
        int direction = 0; // 0 = right 1 = left 2 = up 3 = down
        int temp_dir = 0;
        static DWORD loop(LPVOID lparam);
        void gameloop();
        vector<snake_part> snake;
};

#endif // GAME_H
