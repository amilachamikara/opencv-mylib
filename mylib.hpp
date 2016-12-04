//
// Created by Amila Jayawardhana on 12/3/16.
//

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

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

    Mat getHistogram(Mat image, bool axis=true, bool labels=true){

        Mat gray;

        if(image.type() != CV_8UC1) {
            cvtColor(image, gray, COLOR_BGR2GRAY);
        }else{
            gray = image;
        }

        // reading the properties of the grayscale image
        int width = gray.cols;
        int height = gray.rows;
        int type = gray.type();


        int hist[256], normalizedHist[256];

        for(int i=0; i<256; i++){
            hist[i] = 0;
            normalizedHist[i] = 0;
        }

        // calculating pixel counts for each gray levels
        for(int r=0; r<height; r++){
            for(int c=0; c<width; c++){

                int grayLevel = gray.at<uchar>(r, c);
                hist[grayLevel] += 1;

            }
        }

        // get the maximum pixel count
        int max = 0;
        for(int i=0; i<256; i++){
            if(max<hist[i]){
                max = hist[i];
            }
        }

        // scale down each pixel count by using predefined value

        int HIST_HEIGHT = 400;
        int HIST_WIDTH = 512;

        for(int i=0; i<256; i++){
            normalizedHist[i] = (double(hist[i]) / max) * HIST_HEIGHT;
        }

        // creating blank image with predefined height and width to draw histogram bars
        Mat histImage(HIST_HEIGHT+15, HIST_WIDTH+20, CV_8UC1, 255);

        if(axis) {
            line(histImage, Point(10, HIST_HEIGHT), Point(10, 0), 0);
            line(histImage, Point(10, HIST_HEIGHT), Point(10 + HIST_WIDTH, HIST_HEIGHT), 0);
        }
        for(int i=0; i<256; i++){
            // draw a line to represent the pixel count for each color level
            line(histImage, Point((i*2)+10, HIST_HEIGHT), Point((i*2)+10, HIST_HEIGHT-normalizedHist[i]), 0);

            if(labels && (i%10==0)){
                putText(histImage, to_string(i), Point((i*2)+10, HIST_HEIGHT+8), FONT_HERSHEY_SIMPLEX, 0.2,0);
            }

        }

        return histImage;
    }
}
