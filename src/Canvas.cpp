#include "Canvas.h"

Canvas::Canvas(int width, int height)
{
    Canvas::width = width;
    Canvas::height = height;
    Refresh();
}
void Canvas::Refresh() {
    system("CLS");
    buffer.clear();
    for(int i = 0; i < height; i++) {
        vec_t.clear();
        for(int ix = 0; ix < width; ix++) {
            vec_t.push_back(' ');
        }
        buffer.push_back(vec_t);
    }
}
void Canvas::Draw() {
    for(auto& c : Canvas::buffer) {
        for(auto& cx : c) {
            std::cout << cx;
        }
        std::cout << std::endl;
    }
}
void Canvas::Set(int row, int col) {
    try {
        Canvas::buffer[row][col] = '*';
    } catch(const std::exception& e) {
        throw std::runtime_error("Row/Col inexistent.");
    }
}
void Canvas::Set(int row, int col, char ch) {
    try {
        Canvas::buffer[row][col] = ch;
    } catch(const std::exception& e) {
        throw std::runtime_error("Row/Col inexistent.");
    }
}
void Canvas::Rem(int row, int col) {
    try {
        Canvas::buffer[row][col] = ' ';
    } catch(const std::exception& e) {
        throw std::runtime_error("Row/Col inexistent.");
    }
}

void Canvas::PrintToBuffer(int row, int col, string val) {
    try {
        long len = val.length();
        long rows_c = buffer.size();
        long col_c  = buffer[row].size();
        long overflow = len > col_c - col ? true : false;

        if(!overflow) {
            for(int i = 0; i < len; i++) {
                buffer[row][col + i] = val[i];
            }
        } else {
            unsigned cur_row = row;
            unsigned cur_col = col;
            for(int i = 0; i < len; i++) {
                if(cur_col >= buffer[cur_row].size()) { //shift to next row
                    if(cur_row + 1 > buffer.size()) break;
                    cur_row++;
                    cur_col = 0;
                }
                buffer[cur_row][cur_col] = val[i];
                cur_col++;
            }
        }
    } catch(const std::exception& e) {
        printf("\n Corruption in screen buffer \n");
    }
}
