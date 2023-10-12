#include "convolvePixel.cpp"

void sequentialConvolve(int startX, int endX, int startY, int endY, Matrix& convolvedImage, Matrix& originalImage, Matrix& kernel) {
    for (int i = startX; i < endX; i++) {
        for (int j = startY; j < endY; j++) {
            convolvedImage.set(i,j, convolvePixel(i,j,originalImage,kernel));
        }
    }
}