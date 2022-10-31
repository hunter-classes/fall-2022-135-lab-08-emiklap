#include <string>
using namespace std;

#include "imageio.h"

//task A
void inverse(int image[MAX_H][MAX_W], int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
    return;
}

//task B
void inverse_half(int image[MAX_H][MAX_W], int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = (w/2); j < w; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
    return;
}

//task C
void white_box(int image[MAX_H][MAX_W], int h, int w) {
    int half_h = h/2;
    int quarter_h = h/4;
    int half_w = w/2;
    int quarter_w = w/4;

    for (int i = quarter_h; i < (half_h + quarter_h); i++) {
        for (int j = quarter_w; j < (half_w + quarter_w); j++) {
            image[i][j] = 255;
        }
    }

    return;
}
