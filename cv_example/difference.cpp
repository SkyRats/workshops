#include <iostream>
#include <opencv2/opencv.hpp>
#define THRESHOLD 3000

using namespace cv;


bool em_movimento(Mat dif_img) {
    int count=0;

    for (int i=0; i < dif_img.rows-1; i++) {
        for (int j=0; j < dif_img.cols-1; j++) {
            //std::cout << dif_img.at<uchar>(i, j) << " ";
            count += dif_img.at<uchar>(i, j);
        }
    }
    std::cout << "cont = " << count << std::endl;
    return count > THRESHOLD;
}

int main()  {
    Mat image1, image2, dif;
    image1 = imread("./imgs/img1.jpeg", CV_LOAD_IMAGE_GRAYSCALE);
    image2 = imread("./imgs/img2.jpeg", CV_LOAD_IMAGE_GRAYSCALE);
    
    if ( !image1.data )
    {
        std::cout << "No image data \n" << std::endl;
        return -1;
    }

    dif = image1 - image2;


    if (em_movimento(dif)) {
        std::cout << "Moveu!" << std::endl;
    }
    else {
        std::cout << "Não moveu!" << std::endl;
    }
    //namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", dif);
    waitKey(0);

    return 0;
}