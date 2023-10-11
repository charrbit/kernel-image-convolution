#include "Matrix.h"

int convolvePixel(int x,int y, Matrix& image, Matrix& kernel) {
    int kernelLength = kernel.getRowCount();
    int V = (kernelLength - 1)/2;

    int counter = 0;
    int convolutionVal = 0;
    // Center the Kernel above the Image pixel location matching the NewImage pixel location
    for (int i = 0; i < kernelLength; i++) {
        
        for (int j = 0; j < kernelLength; j++) {
            // Current Image pixel being applied to ConvolutionVal
            int imagX = x-V+i;
            int imagY = y-V+j;

            // Exclude indices outside Image (edge detection)
            if ( ((imagX >= 0) && (imagX < image.getRowCount())) &&
                 ((imagY >= 0) && (imagY < image.getColCount())) )
            {
                counter += kernel.get(i,j); // Track Kernel values used (flux conservation)
                convolutionVal += kernel.get(i,j) * image.get(imagX, imagY);
            }
        }
    }
    return convolutionVal / counter;
}