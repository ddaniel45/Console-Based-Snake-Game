#include "Canvas.h"
#include "Game.h"


void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}


int main()
{
    ShowConsoleCursor(false);
    Canvas* display = new Canvas(100,25);
    Game* g = new Game(display);
    g->init();
    int asd = 0;
    std::cin >> asd;
}
