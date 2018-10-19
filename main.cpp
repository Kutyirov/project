#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
//#include <opencv2.hpp>
//#include <highgui.hpp>
#include <iostream>
//typedef Vec<uchar, 3> Vec3b;
 using namespace cv;

Mat src, src_gray;
Mat dst, detected_edges;
int lowThreshold = 0;
const int max_lowThreshold = 100;
const int ratio = 3;
const int kernel_size = 3;
const char* window_name = "Edge Map";
static void CannyThreshold(int, void*)
{
    blur( src_gray, detected_edges, Size(3,3) );
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    dst = Scalar::all(0);
    src.copyTo( dst, detected_edges);
    imshow( window_name, dst );
}

int main( int argc, char** argv ) {

    
  
    cv::Mat img;
    img = cv::imread("sample5.jpg");
    //cv::_IplImage* dst;
    src = img;
    //cv::Mat bin = 0;
    if(! img.data ) {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }
      if( src.empty() )

    //ConvertImage(src, src, CV_BGR2GRAY);
    
    //Canny( src, src, 0,0 );

 
   /* for( int i = 0; i < img.rows; i++ )
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
                //std::cout << i << " " << j << "X";
                //std::cout<< int(img.at<cv::Vec3b>(i,j)[0]) << " ";
                //std::cout<<int(img.at<cv::Vec3b>(i,j)[1]) << " ";
                //std::cout<<int(img.at<cv::Vec3b>(i,j)[2]) << "///";                               
            }*/
    blur( src_gray, src, Size(3,3) );
    Canny(img,detected_edges, 200, 450);    
    dst = Scalar::all(0);

    src.copyTo( dst, detected_edges);
    //imshow( window_name, dst );
    //cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
    //cv::imshow( "Display window", dst );
    imwrite( "image01_res.jpg", detected_edges );
    cv::waitKey(0);
    return 0;
}
