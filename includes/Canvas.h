#ifndef CANVAS_H
#define CANVAS_H

#include <windows.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
using namespace std;

class Canvas
{
    public:
        Canvas(int width, int height);                      //ctor
        int width,height;                                   //Buffer's dimensions
        void Draw();                                        //Draw the buffer to screen
        void Refresh();                                     //Flush the buffer
        void Set(int row, int col);                         //Set a standard char in the buffer
        void Rem(int row, int col);                         //Remove a char from the buffer (set def one)
        void Set(int row, int col, char ch);                //Set a custom char in the buffer
        void PrintToBuffer(int row, int col, string val);   //Print text in the buffer (auto dealing with the char overflow)
    private:
        std::vector< std::vector<char> > buffer;            //The screen buffer
        std::vector<char> vec_t;                            //Temporary buffer
};

#endif // CANVAS_H
