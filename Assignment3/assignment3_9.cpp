// Aritra Bandyopadhyay 2021CSB107
// Assignment 3_9 Graphics
#include <bits/stdc++.h>

using namespace std;

class screen {
private:
    vector<vector<char>> pixels;  // 2D array of screen pixels

public:
    // Constructor initializes pixels array with given size
    screen(int width, int height) {
        pixels.resize(height);
        for (int i = 0; i < height; i++) {
            pixels[i].resize(width);
        }
        erase_screen();  // Initially, screen is empty
    }

    // Function to erase the screen by filling it with blank spaces
    void erase_screen() {
        for (auto& row : pixels) {
            for (auto& pixel : row) {
                pixel = ' ';
            }
        }
    }

    // Function to draw a line on the screen between two given points
    void draw_line(int x1, int y1, int x2, int y2) {
        bool steep = (abs(y2 - y1) > abs(x2 - x1));
        if (steep) {
            swap(x1, y1);
            swap(x2, y2);
        }
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        int dx = x2 - x1;
        int dy = abs(y2 - y1);
        int error = dx / 2;
        int ystep = (y1 < y2) ? 1 : -1;
        int y = y1;
        for (int x = x1; x <= x2; x++) {
            if (steep) {
                pixels[x][y] = '*';
            } else {
                pixels[y][x] = '*';
            }
            error -= dy;
            if (error < 0) {
                y += ystep;
                error += dx;
            }
        }
    }

    void draw_circle(int x0, int y0, int r) {
        int x = r, y = 0;
        int radius_error = 1 - x;
        while (x >= y) {
            pixels[x0 + x][y0 + y] = '*';
            pixels[x0 + y][y0 + x] = '*';
            pixels[x0 - y][y0 + x] = '*';
            pixels[x0 - x][y0 + y] = '*';
            pixels[x0 - x][y0 - y] = '*';
            pixels[x0 - y][y0 - x] = '*';
            pixels[x0 + y][y0 - x] = '*';
            pixels[x0 + x][y0 - y] = '*';
            y++;
            if (radius_error < 0) {
                radius_error += 2 * y + 1;
            } else {
                x--;
                radius_error += 2 * (y - x + 1);
            }
        }
    }



    // Function to display the screen on the terminal
    void display() const {
        for (const auto& row : pixels) {
            for (const auto& pixel : row) {
                cout << pixel;
            }
            cout << '\n';
        }
    }
};

int main() {
    screen my_screen(30, 30);  
    my_screen.draw_line(1, 1, 5, 7);
    my_screen.draw_circle(20, 20, 3);
    
    my_screen.display();
    return 0;
}
