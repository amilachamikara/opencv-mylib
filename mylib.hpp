//
// Created by Amila Jayawardhana on 12/3/16.
//

#include <opencv2/opencv.hpp>
using namespace cv;

namespace mylib {

    Mat getInvertedImage(Mat gray){
        int width = gray.cols;
        int height = gray.rows;
        int type = gray.type();

        // creating blank image with the same properties
        Mat inverseImage(height, width, type);

        // looping through each and every pixels
        for(int r=0; r<height; r++){
            for(int c=0; c<width; c++){

                // read the pixel value
                int graylevel = gray.at<uchar>(r, c);

                // calculating the inverse value
                int inverseLevel = 255 - graylevel;

                inverseImage.at<uchar>(r, c) = inverseLevel;

            }
        }

        return inverseImage;
    }

    Mat getBinaryImage(Mat gray){
        // reading the properties of the grayscale image
        int width = gray.cols;
        int height = gray.rows;
        int type = gray.type();

        // creating blank image with the same properties
        Mat binary(height, width, type);

        // looping through each and every pixels
        for(int r=0; r<height; r++){
            for(int c=0; c<width; c++){
                // read the pixel value
                int graylevel = gray.at<uchar>(r, c);

                // evaluate the condition to set new pixel value
                if(graylevel < 127){
                    binary.at<uchar>(r, c) = 0;
                }else{
                    binary.at<uchar>(r, c) = 255;
                }
            }
        }

        return binary;
    }

}
