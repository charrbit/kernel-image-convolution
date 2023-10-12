#include <fstream>
#include <string>

#include "convolveSequential.cpp"

int main(int argc, char* argv[]) {

    // Parse passed arguments
    int imageWidth = std::stoi(argv[1]);
    int imageHeight = std::stoi(argv[2]);
    std::string kernelPath = argv[3];
    int kernelSize = std::stoi(argv[4]);

    // Generate the new matrices to store the convolved pixel values
    Matrix convolvedRed = Matrix(imageWidth, imageHeight);
    Matrix convolvedGreen = Matrix(imageWidth, imageHeight);
    Matrix convolvedBlue = Matrix(imageWidth, imageHeight);

    // Generate the kernel Matrix
    std::ifstream kernelStream;
    kernelStream.open(kernelPath);
    Matrix kernel = Matrix(kernelSize, kernelStream);
    kernelStream.close();

    // Read the RGB pixel values of the original image into a Matrix
    std::ifstream redPixelInStream;
    redPixelInStream.open("imageRed.txt");
    Matrix imageRed = Matrix(imageWidth, imageHeight, redPixelInStream);
    redPixelInStream.close();

    std::ifstream greenPixelInStream;
    greenPixelInStream.open("imageGreen.txt");
    Matrix imageGreen = Matrix(imageWidth, imageHeight, greenPixelInStream);
    greenPixelInStream.close();

    std::ifstream bluePixelInStream;
    bluePixelInStream.open("imageBlue.txt");
    Matrix imageBlue = Matrix(imageWidth, imageHeight, bluePixelInStream);
    bluePixelInStream.close();

    // Sequentially convolve each RGB Matrix seperately
    sequentialConvolve(0, imageWidth-1, 0, imageHeight-1, convolvedRed, imageRed, kernel);
    sequentialConvolve(0, imageWidth-1, 0, imageHeight-1, convolvedGreen, imageGreen, kernel);
    sequentialConvolve(0, imageWidth-1, 0, imageHeight-1, convolvedBlue, imageBlue, kernel);

    // Write the convolved RGB matrices to their respective files
    std::ofstream redPixelOutStream;
    redPixelOutStream.open("imageRedConvolved.txt");
    if (redPixelOutStream.is_open()) {
        redPixelOutStream << convolvedRed;
    }
    redPixelOutStream.close();

    std::ofstream greenPixelOutStream;
    greenPixelOutStream.open("imageGreenConvolved.txt");
    if (greenPixelOutStream.is_open()) {
        greenPixelOutStream << convolvedGreen;
    }
    greenPixelOutStream.close();

    std::ofstream bluePixelOutStream;
    bluePixelOutStream.open("imageBlueConvolved.txt");
    if (bluePixelOutStream.is_open()) {
        bluePixelOutStream << convolvedBlue;
    }
    bluePixelOutStream.close();


    /* Generate Parallel Convolved Image */
    // int n = 8192;
    // dataSource.open("images/Image_8192.txt");
    // Matrix image = Matrix(dataSource, n);
    // dataSource.close();

    // Matrix newPimage = Matrix(n);
    // int stopSize = 1;
    // parallelConvolve(0, 0, newPimage.getRow(), newPimage.getCol(), newPimage, image, kernel, stopSize, stopSize);

    return 0;
}