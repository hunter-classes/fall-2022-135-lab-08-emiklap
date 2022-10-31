#include <iostream>

#include "imageio.h"
#include "tasks.h"

/*
 * A helper function that will copy one arry into a new one
 * @param original_img the original array
 * @param out_img the new array
 */
void copy_array(int original_img[MAX_H][MAX_W], int out_img[MAX_H][MAX_W], int height, int width) {
  for(int row = 0; row < height; row++) {
    for(int col = 0; col < width; col++) {
      out_img[row][col] = original_img[row][col];
    }
  }
  return;
}

int main()
{
  std::string input = "inImage.pgm";
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"
  int out[MAX_H][MAX_W];

  //invert the entire image for task A
  inverse(img, h, w);
  copy_array(img, out, h, w);
  writeImage("taskA.pgm", out, h, w);
  //resetting the original image
  inverse(img, h, w);

  //invert half the image for task B
  inverse_half(img, h, w);
  copy_array(img, out, h, w);
  writeImage("taskB.pgm",out, h, w);
  //resetting the original image
  inverse(img, h, w);

  return 0;
}
