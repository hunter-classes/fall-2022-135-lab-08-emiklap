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
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];

  //invert the entire image for task A
  copy_array(img, out, h, w);
  inverse(out, h, w);
  writeImage("taskA.pgm", out, h, w);

  //invert half the image for task B
  copy_array(img, out, h, w);
  inverse_half(out, h, w);
  writeImage("taskB.pgm",out, h, w);

  //draw a 50% white box for task C
  copy_array(img, out, h, w);
  white_box(out, h, w);
  writeImage("taskC.pgm",out, h, w);

  //draw a 50% white frame for task D
  copy_array(img, out, h, w);
  white_frame(out, h, w);
  writeImage("taskD.pgm",out, h, w);

  //increase the image by 200% for task E
  int ref[MAX_H][MAX_W];
  copy_array(img, out, h, w);
  double_scale(out, ref, h, w);
  writeImage("taskE.pgm", ref, h*2, w*2);

  //pixelates image for task F
  copy_array(img, out, h, w);
  pixelate(out, h, w);
  writeImage("taskF.pgm", out, h, w);

  return 0;
}
