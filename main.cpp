#include "mylib.hpp"


using namespace mylib;

int main() {

    Mat image = imread("/Users/Amila/ClionProjects/opencv-mylib/lenna.png", IMREAD_COLOR);

//    Mat inverted = getInvertedImage(image);
//    Mat binary = getBinaryImage(image);
    Mat hist = getHistogram(image, false);

//    imshow("Grayscale", image);
    imshow("Histogram", hist);
//    imshow("Inverted", inverted);
//    imshow("Binary", binary);
    waitKey(0);
    destroyAllWindows();

    return 0;
}