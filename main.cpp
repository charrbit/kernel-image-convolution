#include <fstream>
#include <random>
#include "Matrix.h"
#include "convolve.cpp"

int main() {

    /* Generate Kernel Matrix */
    std::ifstream dataSource;
    dataSource.open("kernels/boxcar.txt");
    Matrix kernel = Matrix(dataSource, 3);
    dataSource.close();

    // -----------------------------------------------------


    /* Generate Image Matrix */
   
    /* Matrix image = Matrix(n);

    std::random_device seed;
    std::mt19937 rng(seed());
    std::uniform_int_distribution<std::mt19937::result_type> range(0,65535);

    for (int i = 0; i < image.getRow(); i++) {
        for (int j = 0; j < image.getCol(); j++) {
            image.set(i,j, range(rng));
        }
    }

    std::ofstream outFile;
    outFile.open("Image_8192.txt");
    outFile << image; */
 
    // -----------------------------------------------------


    /* Generate Parallel Convolved Image */
    int n = 8192;
    dataSource.open("images/Image_8192.txt");
    Matrix image = Matrix(dataSource, n);
    dataSource.close();

    Matrix newPimage = Matrix(n);
    int stopSize = 1;
    parallelConvolve(0, 0, newPimage.getRow(), newPimage.getCol(), newPimage, image, kernel, stopSize, stopSize);

    // -----------------------------------------------------


    /* Generate Sequential Convolved Image */

    /* Matrix newImage = Matrix(n);
    
    sequentialConvolve(0, newImage.getRow(), 0 , newImage.getCol(), newImage, image, kernel);


    // -----------------------------------------------------


    /* Write NewImage to file */

    /* std::ofstream saveFile;
    saveFile.open("convolvedData.txt");
    saveFile << newPImage;
    saveFile.close(); */

    // -----------------------------------------------------


    return 0;
}