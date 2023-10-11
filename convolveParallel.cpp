#include "convolveSequential.cpp"
#include </home/astrobits/opencilk/cheetah/include/cilk/cilk.h>

void parallelConvolve(int startX, int startY, int xSize, int ySize, Matrix& convolvedImage, Matrix& originalImage, Matrix& kernel, int stopX, int stopY) {
    if ((xSize <= stopX) && (ySize <= stopY)) {
        sequentialConvolve(startX, startX+xSize, startY, startY+ySize, convolvedImage, originalImage, kernel);
    }
    else {
        cilk_spawn 
            parallelConvolve(startX, startY, xSize/2, ySize/2, convolvedImage, originalImage, kernel, stopX, stopY);
        cilk_spawn
            parallelConvolve(startX, startY+ySize/2, xSize/2, ySize/2, convolvedImage, originalImage, kernel, stopX, stopY); 
        cilk_spawn
            parallelConvolve(startX+xSize/2, startY, xSize/2, ySize/2, convolvedImage, originalImage, kernel, stopX, stopY); 
        cilk_spawn
            parallelConvolve(startX+xSize/2, startY+ySize/2, xSize/2, ySize/2, convolvedImage, originalImage, kernel, stopX, stopY);
        cilk_sync;
    }
}