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

//task D
void white_frame(int image[MAX_H][MAX_W], int h, int w) {
    int half_h = h/2;
    int quarter_h = h/4;
    //int max_h = half_h + quarter_h;
    int half_w = w/2;
    int quarter_w = w/4;
    //int max_w = half_w + quarter_w;

    for (int i = 0; i < half_h; i++) {
        for (int j = 0; j < half_w; j++) {
            if (i == 0 || i == half_h - 1 || j == 0 || j == half_w - 1) {
                image[i + quarter_h][j + quarter_w] = 255;
            }
        }
    }
    return;
}

//task E
void double_scale(int image[MAX_H][MAX_W], int ref[MAX_H][MAX_W], int h, int w) {
    for (int i = 0; i < h ; i++) {
        for (int j = 0 ; j < w; j++) {
            ref[i*2][j*2] = image[i][j];
            ref[i*2+1][j*2] = image[i][j];
            ref[i*2][j*2+1] = image[i][j];
            ref[i*2+1][j*2+1] = image[i][j];
        }
    }
    return;
}

//task F
void pixelate(int image[MAX_H][MAX_W], int h, int w) {

    for (int i = 0; i < h; i = i+2) {
        for (int j = 0 ; j < w; j = j+2) {
            int average = 0;
            average += image[i][j];
            average += image[i+1][j];
            average += image[i][j+1];
            average += image[i+1][j+1];
            image[i][j] = average/4;
            image[i+1][j] = average/4;
            image[i][j+1] = average/4;
            image[i+1][j+1] = average/4;
        }
    }
    return;
}
