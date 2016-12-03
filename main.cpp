#include "mylib.hpp"


using namespace mylib;

int main() {

    Mat image = imread("/Users/Amila/ClionProjects/opencv-mylib/lenna.png", IMREAD_GRAYSCALE);

    Mat inverted = getInvertedImage(image);
    Mat binary = getBinaryImage(image);

    imshow("Grayscale", image);
    imshow("Inverted", inverted);
    imshow("Binary", binary);
    waitKey(0);
    destroyAllWindows();

    return 0;
}