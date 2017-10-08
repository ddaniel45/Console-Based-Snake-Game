#include "Game.h"

snake_part::snake_part(int row,int col, char ch) {
    if(ch != '*') snake_part::ch = ch;
    snake_part::row = row;
    snake_part::col = col;
}
Game::Game(Canvas* ptr)
{
    if(ptr == NULL) throw std::runtime_error("Null canvas ptr");
    Game::screen = ptr;
}

void Game::init() {
    if(Game::screen == NULL) throw std::runtime_error("Null canvas ptr");

    snake.push_back(snake_part(1,1));
    snake.push_back(snake_part(1,2));
    snake.push_back(snake_part(1,3));
    snake.push_back(snake_part(1,4));

    DWORD id;
    HANDLE hnd = CreateThread(NULL,0,loop,this,0,&id);
}

DWORD Game::loop(LPVOID lparam) {
    Game* g = (Game*)lparam;
    g->gameloop();
    std::cout << "GAME OVER!" << std::endl;
}
void Game::gameloop() {
while(true) {
    if (GetAsyncKeyState(VK_RIGHT) < 0 && this->direction != 1 && this->direction != 0) this->direction = 0;
    if (GetAsyncKeyState(VK_LEFT)  < 0 && this->direction != 1 && this->direction != 0) this->direction = 1;
    if (GetAsyncKeyState(VK_UP)    < 0 && this->direction != 2 && this->direction != 3) this->direction = 2;
    if (GetAsyncKeyState(VK_DOWN)  < 0 && this->direction != 2 && this->direction != 3) this->direction = 3;

    switch(direction) {
        case 0:
             if(this->snake.back().col < this->screen->width) this->snake.push_back(snake_part(snake.back().row,snake.back().col + 1));
            break;
        case 1:
             if(this->snake.back().col > 0) this->snake.push_back(snake_part(snake.back().row,snake.back().col - 1));
            break;
        case 2:
             if(this->snake.back().row > 0) this->snake.push_back(snake_part(snake.back().row - 1,snake.back().col));
            break;
        case 3:
             if(this->snake.back().row < this->screen->height) this->snake.push_back(snake_part(snake.back().row + 1,snake.back().col));
            break;

    }
    for(snake_part& p : this->snake) {
        this->screen->Set(p.row,p.col,p.ch);
    }
    if(this->snake.back().col >= this->screen->width ||this->snake.back().col <= 0 ||this->snake.back().row <= 0 ||this->snake.back().row >= this->screen->height) break;

    //DRAW BOX
        for(int i = 0; i < this->screen->width - 1; i++) {
            this->screen->Set(0,i,'-');
            this->screen->Set(this->screen->height - 1,i,'-');
        }
        for(int i = 0; i < this->screen->height - 1; i++) {
            this->screen->Set(i,0,'|');
            this->screen->Set(i,this->screen->width - 1,'|');
        }
    //
    this->screen->Draw();
    this->screen->Refresh();
    this->snake.erase(this->snake.begin());
}
}
