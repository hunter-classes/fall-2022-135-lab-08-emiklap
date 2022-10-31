#include <string>
using namespace std;

#include "imageio.h"


void inverse(int image[MAX_H][MAX_W], int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
    return;
}

void inverse_half(int image[MAX_H][MAX_W], int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = (w/2); j < w; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
    return;
}
