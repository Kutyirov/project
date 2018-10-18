#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
int main( int argc, char** argv ) {

    
  
    cv::Mat img;
    img = cv::imread("sample5.jpg");
    cv::Mat temp = img;
    if(! img.data ) {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }
  
 
    for( int i = 0; i < img.rows; i++ )
        for( int j = 0; j < img.cols; j++ )
            {       
                if (int(img.at<cv::Vec3b>(i,j)[0]) + int(img.at<cv::Vec3b>(i,j)[1]) + int(img.at<cv::Vec3b>(i,j)[2]) < 250){                     
                    img.at<cv::Vec3b>(i,j)[0]= 0;
                    img.at<cv::Vec3b>(i,j)[1]= 0;
                    img.at<cv::Vec3b>(i,j)[2]= 0;
                }
                else {
                    img.at<cv::Vec3b>(i,j)[0]= 255;
                    img.at<cv::Vec3b>(i,j)[1]= 255;
                    img.at<cv::Vec3b>(i,j)[2]= 255;
                }
                        
            }
    //cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
    //cv::imshow( "Display window", img );
    imwrite( "image01_res.jpg", img );
    cv::waitKey(0);
    return 0;
}
