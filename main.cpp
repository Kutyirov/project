#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
//#include <stdio.h>
//#include <stdlib.h>
//#include <opencv2.hpp>
//#include <highgui.hpp>
#include <iostream>
//#include <array>
//typedef Vec<uchar, 3> Vec3b;
 using namespace cv;

/*
                work[i][j] = 0;
                unsigned x1,y1,x2,y2;
                x1 = 0;
                y1 = 0;
                x2 = 0;
                y2 = 0;
                bool k = false;
                
                for (short l = -1; l < 2; l++){
                    for (short m = -1; m < 2; m++)
                        if (work[i + l][j + m] == 255){
                            x1 = j + m;
                            y1 = i + l;
                            k = true;
                            break;
                            //std::cout << "x1 = " << x1 << " y1 = " << y1 << std::endl;
                        }
                    if (k) break;
                }
                if (!k) break;
                k = false;
                work[y1][x1] = 0;
                //std::cout << work[y1][y1] << std::endl;
                //std:: cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
                for (short l = -1; l < 2; l++){
                    for (short m = -1; m < 2; m++)
                        if (work[i + l][j + m] == 255) {
                            x2 = j + m;
                            y2 = i + l;
                            k = true;
                            break;
                            //std::cout << "x2 = " << x2 << " y2 = " << y2 << std::endl;
                        }
                    if (k) break;
                }
                if (!k) break;
                work[y1][x1] = 255;        
                //work[y2][x2] = 0;
                //std:: cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
                bool t = false;
                while (work[y1][x1] == 255){
                    work[y1][x1] = 0;
                    //std::cout << work[y1][x1] << std::endl;
                    t = false;
                    for (short l = -1; l < 2; l++){
                        for (short m = -1; m < 2; m++)
                            if ((work[y1 + l][x1 + m] == 255) || ((work[y1 + l][x1 + m] > 0) && (work[y1 + l][x1 + m] < 25))){
                                x1 = x1 + m;
                                y1 = y1 + l;
                                std::cout << "x1 = " << x1 << " y1 = " << y1 << std::endl;
                                //std::cout << x1 << " " << y1 << " " << work[y1][x1] << " " << l << " " << m << std::endl;
                                t = true;
                                break;
                            }
                        if (t) break;
                    }
                    if (!t) work[y1][x1] = 0;
                }
                if (!t) break;
                //std::cout << 2;
                while (work[y2][x2] == 255){
                    work[y2][x2] = 0;
                    t = false;
                    for (short l = -1; l < 2; l++){
                        for (short m = -1; m < 2; m++)
                            if ((work[y2 + l][x2 + m] == 255) || ((work[y2 + l][x2 + m] > 0) && (work[y2 + l][x2 + m] < 25))){
                                x2 = x2 + m;
                                y2 = y2 + l;
                                std::cout << "x2 = " << x2 << " y2 = " << y2 << std::endl;
                                //std::cout << x2 << " " << y2 << " " << work[y1][x1] << " " << l << " " << m << std::endl;
                                t = true;
                                break;
                            }
                        if (t) break;
                    }
                    if (!t) work[y2][x2] = 0;
                }
                if (!t) break;
                //std::cout << work[y1][x1] % 2;
                //std::cout << 2;
                std:: cout << x1 << " " << y1 << " " << x2 << " " << y2 <<  " " << work[y1][x1] << " " << work[y2][x2] << std::endl;
                //ищем центры прямоугольников зная четен цвет или нечетен
                */
                //work[i][j] = 0;



    
  /*
    cv::Mat img;
    img = cv::imread("sample7.jpg");
    cv::Mat cap;
    src = img;
    if(! img.data ) {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }
    Canny(img,detected_edges, 150, 300);    
    dst = Scalar::all(0);

    src.copyTo( dst, detected_edges);
    //imshow( window_name, dst );
    //cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
    //cv::imshow( "Display window", dst );
     for( int i = 0; i < dst.rows; i++ )
        for( int j = 0; j < dst.cols; j++ )
            {   
                //if (int(detected_edges.at<cv::Vec3b>(i,j)[1]) == 255)
                if ((int(dst.at<cv::Vec3b>(i,j)[0]) > 0) || (int(dst.at<cv::Vec3b>(i,j)[1]) > 0) || (int(dst.at<cv::Vec3b>(i,j)[2]) > 0))
            {
                dst.at<cv::Vec3b>(i,j)[0] = 255;
                dst.at<cv::Vec3b>(i,j)[1] = 255;
                dst.at<cv::Vec3b>(i,j)[2] = 255;
            }    
                
                //std::cout<< int(dst.at<cv::Vec3b>(i,j)[0]) << " ";
                //std::cout<<int(dst.at<cv::Vec3b>(i,j)[1]) << " ";
                //std::cout<<int(dst.at<cv::Vec3b>(i,j)[2]) << "///";                               
            }

           // imshow( window_name, detected_edges );
  //  cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
  //  cv::imshow( "Display window",detected_edges );
    //imwrite( "begin.jpg", dst );
    //формирование строки для считывания конденсатора
    std::string capa = "capacitor/";
    std::string tor = ".jpg";
    std::string ci = "18";
    std::string capacitor = "";
    for( int i = 0; i < cap.rows; i++ )
        for( int j = 0; j < cap.cols; j++ ){
            
            std::cout<< int(cap.at<cv::Vec3b>(i,j)[0]) << " ";
            std::cout<<int(cap.at<cv::Vec3b>(i,j)[1]) << " ";
            std::cout<<int(cap.at<cv::Vec3b>(i,j)[2]) << "///";        
        }

   
   for (unsigned i = 1; i < 41; i++){
        ci = std::to_string(i);
        capacitor = capa + ci + tor;
        std::cout << capacitor << std::endl;
        cap = cv::imread(capacitor);
    for( int i = 0; i < cap.rows; i++ )
        for( int j = 0; j < cap.cols; j++ ){
            if ((int(cap.at<cv::Vec3b>(i,j)[0]) > 0) || (int(cap.at<cv::Vec3b>(i,j)[1]) > 0) || (int(cap.at<cv::Vec3b>(i,j)[2]) > 0))
            {    
                cap.at<cv::Vec3b>(i,j)[0] = 255;
                cap.at<cv::Vec3b>(i,j)[1] = 255;
                cap.at<cv::Vec3b>(i,j)[2] = 255;
                                       
            }
            //std::cout<< int(cap.at<cv::Vec3b>(i,j)[0]) << " ";
            //std::cout<<int(cap.at<cv::Vec3b>(i,j)[1]) << " ";
            //std::cout<<int(cap.at<cv::Vec3b>(i,j)[2]) << "///";        
        }
        imwrite( capacitor, cap );

   }

    //for (unsigned i = 1; i < 2; i++){
        //ci = std::to_string(i);
        //capacitor = capa + ci + tor;
        //std::cout << capacitor << std::endl;
        //cap = cv::imread(capacitor);
        for (unsigned j = 0; j < dst.rows - cap.rows - 10; j++)
            for (unsigned k = 0; k < dst.cols - cap.cols - 10; k++){
                unsigned quanity = 0;
                for (unsigned j1 = 0; j1 < cap.rows; j1++)
                    for (unsigned k1 = 0; k1 < cap.cols; k1++)
                        if (int(dst.at<cv::Vec3b>(j+j1,k+k1)[0]) == (int(cap.at<cv::Vec3b>(j1,k1)[0])))
                            quanity++;
                std::cout << quanity << " ";
                if (quanity > cap.rows*cap.cols*0.5)
                    for (unsigned j1 = j; j1 < cap.rows+j; j1++)
                        for (unsigned k1 = k; k1 < cap.cols+k; k1++){
                            dst.at<cv::Vec3b>(j1,k1)[0] = 0;
                            dst.at<cv::Vec3b>(j1,k1)[1] = 0;
                            dst.at<cv::Vec3b>(j1,k1)[2] = 255;
                        }
            }
        
   // imwrite( "end.jpg", dst );
    cv::waitKey(0);
    return 0;
    */
    /*
    блок для обработки изображения
    cv::Mat img;
    img = cv::imread("capacitor/image1.jpg");
    src = img;
    if(! img.data ) {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }
    Canny(img,detected_edges, 150, 300);    
    dst = Scalar::all(0);

    src.copyTo( dst, detected_edges);

    for( int i = 0; i < dst.rows; i++ )
        for( int j = 0; j < dst.cols; j++ ){
            if ((int(dst.at<cv::Vec3b>(i,j)[0]) > 0) || (int(dst.at<cv::Vec3b>(i,j)[1]) > 0) || (int(dst.at<cv::Vec3b>(i,j)[2]) > 0))
            {    
                dst.at<cv::Vec3b>(i,j)[0] = 255;
                dst.at<cv::Vec3b>(i,j)[1] = 255;
               dst.at<cv::Vec3b>(i,j)[2] = 255;
                                       
            }
            std::cout<< int(dst.at<cv::Vec3b>(i,j)[0]) << " ";
            std::cout<<int(dst.at<cv::Vec3b>(i,j)[1]) << " ";
            std::cout<<int(dst.at<cv::Vec3b>(i,j)[2]) << "///";        
        }

    imwrite( "capacitor/image.jpg", dst );*/
    /*
    //блок для обработки базы данных
    Mat dst;
    dst = cv::imread("capacitor/1.jpg");
    if(! dst.data ) {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }
    for( int i = 0; i < dst.rows; i++ )
        for( int j = 0; j < dst.cols; j++ ){
            if ((int(dst.at<cv::Vec3b>(i,j)[0]) > 250) || (int(dst.at<cv::Vec3b>(i,j)[1]) > 250) || (int(dst.at<cv::Vec3b>(i,j)[2]) > 250))
            {    
                dst.at<cv::Vec3b>(i,j)[0] = 255;
                dst.at<cv::Vec3b>(i,j)[1] = 255;
               dst.at<cv::Vec3b>(i,j)[2] = 255;
                                       
            }
            else
            {
                dst.at<cv::Vec3b>(i,j)[0] = 0;
                dst.at<cv::Vec3b>(i,j)[1] = 0;
               dst.at<cv::Vec3b>(i,j)[2] = 0;
            }
            std::cout<< int(dst.at<cv::Vec3b>(i,j)[0]) << " ";
            std::cout<<int(dst.at<cv::Vec3b>(i,j)[1]) << " ";
            std::cout<<int(dst.at<cv::Vec3b>(i,j)[2]) << "///";        
        }
        imwrite( "capacitor/1.jpg", dst );
    */
    /*
    обход по матрице
    for (unsigned i = y1 - 10; i < y2 + 10; i++)
            for (unsigned j = x1 - 10; j < x2 + 10; j++){
                unsigned quanity = 0;
                for (unsigned i1 = 0; i1 < cap.rows; i1++)
                    for (unsigned j1 = 0; j1 < cap.cols; j1++)
                        if (int(dst.at<cv::Vec3b>(i+i1,j+j1)[0]) == (int(cap.at<cv::Vec3b>(i1,j1)[0])))
                            quanity++;
                //std::cout << i << " " << j << " " << quanity <<  "///";
                if (quanity > cap.rows*cap.cols-450)
                    for (unsigned i1 = i; i1 < cap.rows+i; i1++)
                        for (unsigned j1 = j; j1 < cap.cols+j; j1++)
                            if (int(cap.at<cv::Vec3b>(i1-i,j1-j)[0]) == 255){
                                dst.at<cv::Vec3b>(i1,j1)[0] = 255;
                                dst.at<cv::Vec3b>(i1,j1)[1] = 0;
                                dst.at<cv::Vec3b>(i1,j1)[2] = 0;
                            }
            }
        */

   //основная программа
int main( int argc, char** argv ) {
    Mat img;
    Mat dst;
    Mat src;
    Mat detected_edges;
    img = cv::imread("newone.jpg");
    src = img;
    if(! img.data ) {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }

    

    Canny(img,detected_edges, 100, 300);    
    dst = Scalar::all(0);

    src.copyTo( dst, detected_edges);
    unsigned x1,y1,x2,y2;
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
    unsigned y3,x3;
    for( int i = 0; i < dst.rows; i++ )
        for( int j = 0; j < dst.cols; j++ ){
            if ((int(dst.at<cv::Vec3b>(i,j)[0]) > 0) || (int(dst.at<cv::Vec3b>(i,j)[1]) > 0) || (int(dst.at<cv::Vec3b>(i,j)[2]) > 0))
            {    
                dst.at<cv::Vec3b>(i,j)[0] = 255;
                dst.at<cv::Vec3b>(i,j)[1] = 255;
                dst.at<cv::Vec3b>(i,j)[2] = 255;
                                       
            }
            else
            {
                dst.at<cv::Vec3b>(i,j)[0] = 0;
                dst.at<cv::Vec3b>(i,j)[1] = 0;
                dst.at<cv::Vec3b>(i,j)[2] = 0;
            }
        }
    for( int i = 0; i < img.rows; i++ )
        for( int j = 0; j < img.cols; j++ ){
            if (int(img.at<cv::Vec3b>(i,j)[0]) + int(img.at<cv::Vec3b>(i,j)[1]) + int(img.at<cv::Vec3b>(i,j)[2]) < 230)
            {    
                img.at<cv::Vec3b>(i,j)[0] = 255;
                img.at<cv::Vec3b>(i,j)[1] = 255;
                img.at<cv::Vec3b>(i,j)[2] = 255;
                                       
            }
            else
            {
                img.at<cv::Vec3b>(i,j)[0] = 0;
                img.at<cv::Vec3b>(i,j)[1] = 0;
                img.at<cv::Vec3b>(i,j)[2] = 0;
            }
        }
    for (unsigned i = 0; i < dst.rows; i++){
        for (unsigned j = 0; j < dst.cols; j++)
            if (int(dst.at<cv::Vec3b>(i,j)[0]) == 255){
                y1 = i;
                break;
            }
        if (y1) break;
    }
    for (unsigned j = 0; j < dst.cols; j++)
        for (unsigned i = 0; i < dst.rows; i++){ 
            if (int(dst.at<cv::Vec3b>(i,j)[0]) == 255){
                x1 = j;
                break;
            }
        if (x1) break;
    }
    for (int i = dst.rows - 1; i > 0; i--){
        for (unsigned j = dst.cols - 1; j > 0; j--)
            if (int(dst.at<cv::Vec3b>(i,j)[0]) == 255){
                y2 = i;
                break;
            }
        if (y2) break;
    }
    for (int j = dst.cols - 1; j > 0; j--)
        for (unsigned i = dst.rows - 1; i > 0; i--){
            if (int(dst.at<cv::Vec3b>(i,j)[0]) == 255){
                x2 = j;
                break;
            }
        if (x2) break;
    }

    //std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
    int** work;
    work = new int*[y2-y1+61];
    for (unsigned i = 0; i < y2-y1+61;i++)
        work[i] = new int[x2-x1+61];
    for(unsigned i = 0; i < y2-y1+61;i++)
        for (unsigned j = 0; j < x2 - x1 + 61; j++)
            work[i][j] = int(dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[0]);
    
    bool** speed;
    speed = new bool*[y2-y1+61];
    for (unsigned i = 0; i < y2-y1+61;i++)
        speed[i] = new bool[x2-x1+61];
    unsigned temp = 0;
    for(unsigned i = 0; i < y2-y1+61;i++)
        for (unsigned j = 0; j < x2 - x1 + 61; j++)
            speed[i][j] = false;
    
    for(unsigned i = 0; i < y2-y1+61 - 100;i++)
        for (unsigned j = 0; j < x2 - x1 + 61 - 100; j++){
            temp = 0;
            for (unsigned i1 = 0; i1 < 100; i1++)
                for (unsigned j1 = 0; j1 < 100; j1++)
                    if (work[i + i1][j + j1] == 255)
                        temp++;
            if (temp > 300)
                speed[i][j] = true;
        }
    
    std::string capa = "";
    std::string tor = ".jpg";
    std::string ci = "";
    std::string capacitor = "";
    cv::Mat cap;
    //здесь цикл по папкам

    for (unsigned t = 1; t < 5; t++){ //папки
        for (unsigned k = 1; k < 5; k++){ //образы
            capa = std::to_string(t) + "/";
            ci = std::to_string(k);
            capacitor = capa + ci + tor;
            std::cout << capacitor << std::endl;
            cap = cv::imread(capacitor);
    
            for( int i = 0; i < cap.rows; i++ ){
                for( int j = 0; j < cap.cols; j++ ){
                //std::cout << int(cap.at<cv::Vec3b>(i,j)[0]) << " " << int(cap.at<cv::Vec3b>(i,j)[1]) << int(cap.at<cv::Vec3b>(i,j)[2]) << "///";
                    if ((int(cap.at<cv::Vec3b>(i,j)[0]) > 50) || (int(cap.at<cv::Vec3b>(i,j)[1]) > 50) || (int(cap.at<cv::Vec3b>(i,j)[2]) > 50))
                    {    
                        cap.at<cv::Vec3b>(i,j)[0] = 255;
                        cap.at<cv::Vec3b>(i,j)[1] = 255;
                        cap.at<cv::Vec3b>(i,j)[2] = 255;
                                       
                    }
                    else
                    {
                        cap.at<cv::Vec3b>(i,j)[0] = 0;
                        cap.at<cv::Vec3b>(i,j)[1] = 0;
                        cap.at<cv::Vec3b>(i,j)[2] = 0;
                    }
                }
            }
        
            
            
            y3 = y2 + 60 - y1 - cap.rows;
            x3 = x2 + 60 - x1 - cap.cols;
    
            //std::cout << x3 << " " << y3 << std::endl;
            for(unsigned i = 0; i < y3; i++)
                for(unsigned j = 0; j < x3; j++){
                    unsigned quanity = 0;
                    if (speed[i][j])
                    for (unsigned i1 = 0; i1 < cap.rows; i1++)
                        for (unsigned j1 = 0; j1 < cap.cols; j1++)
                            if (work[i+i1][j+j1] == int(cap.at<cv::Vec3b>(i1,j1)[0]))
                                quanity++;
                    //std::cout << quanity << "//";
                    if (quanity > cap.rows*cap.cols-400)
                    for (unsigned i1 = i; i1 < cap.rows+i; i1++)
                        for (unsigned j1 = j; j1 < cap.cols+j; j1++)
                            work[i1][j1] = t;
                            //if (int(cap.at<cv::Vec3b>(i1-i,j1-j)[0]) == 255){
                            //    work[i1][j1] = 100;
                            //}
                    //work[i][j] = 100;
                }
                
        }
    }
    
    for (unsigned i = 0; i < y2- y1 + 61; i++)
        for(unsigned j = 0; j < x2 - x1 + 61; j++){
            dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[0] = work[i][j];
            if ((work[i][j] == 0) || (work[i][j] == 254)){
                dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[1] = work[i][j];
                dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[2] = work[i][j];
            }
        }
    
    imwrite( "end.jpg", dst );
    
    Mat second;
    second = cv::imread("newone.jpg");
    for( int i = 0; i < second.rows; i++ )
        for( int j = 0; j < second.cols; j++ ){
            if (int(second.at<cv::Vec3b>(i,j)[0]) + int(second.at<cv::Vec3b>(i,j)[1]) + int(second.at<cv::Vec3b>(i,j)[2]) < 120)
            {    
                second.at<cv::Vec3b>(i,j)[0] = 255;
                second.at<cv::Vec3b>(i,j)[1] = 255;
                second.at<cv::Vec3b>(i,j)[2] = 255;
                                       
            }
            else
            {
                second.at<cv::Vec3b>(i,j)[0] = 0;
                second.at<cv::Vec3b>(i,j)[1] = 0;
                second.at<cv::Vec3b>(i,j)[2] = 0;
            }
        }
    //блок сложения изображений
    for (unsigned i = 0; i < y2- y1 + 61; i++)
        for(unsigned j = 0; j < x2 - x1 + 61; j++){
            if (((work[i][j] == 0) || (work[i][j] > 18)) && (int(second.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[0]) == 255))
                work[i][j] = 255;
            if ((work[i][j] == 0) && (int(second.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[0]) == 255)){
                dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[0] = 0;
                dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[1] = 0;
                dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[2] = 0;
            }
            if ((int(second.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[0]) == 0) && (work[i][j] > 18))
                work[i][j] = 0;
        }
    for (unsigned i = 0; i < y2- y1 + 61; i++)
        for(unsigned j = 0; j < x2 - x1 + 61; j++){
            dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[0] = work[i][j];
            if ((work[i][j] == 0) || (work[i][j] == 254)){
                dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[1] = work[i][j];
                dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[2] = work[i][j];
            }
        }
        /*
    dst.at<cv::Vec3b>(105 + y1 - 30,804 + x1 - 30)[0] = 0;
    dst.at<cv::Vec3b>(105 + y1 - 30,804 + x1 - 30)[1] = 255;
    dst.at<cv::Vec3b>(105 + y1 - 30,804 + x1 - 30)[2] = 0;

    dst.at<cv::Vec3b>(137 + y1 - 30,807 + x1 - 30)[0] = 0;
    dst.at<cv::Vec3b>(137 + y1 - 30,807 + x1 - 30)[1] = 255;
    dst.at<cv::Vec3b>(137 + y1 - 30,807 + x1 - 30)[2] = 0;
    */
    imwrite( "end1.jpg", dst );
    
   //преобразование проводов !!!добавить обработку параллельного соединения!!!
   
    for(unsigned i = 0; i < y2-y1+61;i++)
        for (unsigned j = 0; j < x2 - x1 + 61; j++)
            
            if (work[i][j] == 255){ //ищем крайние точки
            //std::cout << "i = " << i << " j = " << j << std::endl;
                
                unsigned x1,y1,x2,y2;
                x1 = 0;
                y1 = 0;
                x2 = 0;
                y2 = 0;
                unsigned direction1 = 0;
                unsigned direction2 = 0;
                if ((work[i-1][j] > 0) && (work[i-1][j] < 19)){
                    x1 = j;
                    y1 = i - 1;
                    y2 = i + 1;
                    x2 = j;
                    unsigned p = 0;
                    for (unsigned j1 = j - 40; j1 < j + 41; j1++){
                            if (work[i][j1] == 255){
                                work[i][j1] = 0;
                            }   
                        }
                    direction2 = 3;
                }
                else {
                    direction1 = 4;
                    direction2 = 2;
                    unsigned p = 0;
                    x1 = j - 1;
                    y1 = i;
                    y2 = i;
                    x2 = j;
                }
                while (!((work[y1][x1] > 0) && (work[y1][x1] < 19))){
                    unsigned number = 0;
                    if ((direction1 == 1) || (direction1 == 3)){
                        for (unsigned j1 = x1 - 40; j1 < x1 + 41; j1++){
                            if (work[y1][j1] == 255){
                                work[y1][j1] = 0;
                                number++;
                            }   
                        }
                    }
                    if ((direction1 == 2) || (direction1 == 4)){
                        for (unsigned i1 = y1 - 40; i1 < y1 + 41; i1++){
                            if (work[i1][x1] == 255){
                                work[i1][x1] = 0;
                                number++;
                            }
                        }
                    }
                    if (direction1 == 1){
                        y1--;
                    }
                    if (direction1 == 2){
                        x1++;
                    }
                    if (direction1 == 3){
                        y1++;
                    }
                    if (direction1 == 4){
                        x1--;
                    }
                    if (number < 1){
                        if (direction1 == 1){
                            y1+=13;
                        }
                        if (direction1 == 2){
                            x1-=13;
                        }
                        if (direction1 == 3){
                            y1-=13;
                        }
                        if (direction1 == 4){
                            x1+=13;
                        }
                        if ((direction1 == 1) || (direction1 == 3)){
                            if (work[y1][x1 - 41] == 255){
                                x1 -= 41;
                                direction1 = 4;
                            }
                            else {
                                x1 += 41;
                                direction1 = 2;
                            }
                        }
                        if ((direction1 == 2) || (direction1 == 4)){
                            if (work[y1 - 41][x1] == 255){
                                y1 -= 41;
                                direction1 = 1;
                                continue;
                            }
                            else {
                                y1 += 41;
                                direction1 = 3;
                                continue;
                            }
                        }
                    }
                    //std::cout << y1 << " " << x1 << " " << direction1 << " " << number << " " << work[y1][x1]<<std::endl;
                }         
                //std::cout << "next\n";   
                while (!((work[y2][x2] > 0) && (work[y2][x2] < 19))){
                    unsigned number = 0;
                    if ((direction2 == 1) || (direction2 == 3)){
                        for (unsigned j1 = x2 - 40; j1 < x2 + 41; j1++){
                            if (work[y2][j1] == 255){
                                work[y2][j1] = 0;
                                number++;
                            }   
                        }
                    }
                    if ((direction2 == 2) || (direction2 == 4)){
                        for (unsigned i1 = y2 - 40; i1 < y2 + 41; i1++){
                            if (work[i1][x2] == 255){
                                work[i1][x2] = 0;
                                number++;
                            }
                        }
                    }
                    if (direction2 == 1){
                        y2--;
                    }
                    if (direction2 == 2){
                        x2++;
                    }
                    if (direction2 == 3){
                        y2++;
                    }
                    if (direction2 == 4){
                        x2--;
                    }
                    if (number < 1){
                        if (direction2 == 1){
                            y2+=13;
                        }
                        if (direction2 == 2){
                            x2-=13;
                        }
                        if (direction2 == 3){
                            y2-=13;
                        }
                        if (direction2 == 4){
                            x2+=13;
                        }
                        if ((direction2 == 1) || (direction2 == 3)){
                            if (work[y2][x2 - 41] == 255){
                                x2 -= 41;
                                direction2 = 4;
                                continue;
                            }
                            else {
                                x2 += 41;
                                direction2 = 2;
                                continue;
                            }
                        }
                        if ((direction2 == 2) || (direction2 == 4)){
                            if (work[y2 - 41][x2] == 255){
                                y2 -= 41;
                                direction2 = 1;
                            }
                            else {
                                y2 += 41;
                                direction2 = 3;
                            }
                        }
                    }
                    //std::cout << y2 << " " << x2 << " " << direction2 << " " << number << " " << work[y2][x2] << std::endl;
                }
                unsigned l1 = 0;
                unsigned m1 = 0;
                
                if ( work[y1][x1] % 2 == 1 ) {
                    l1 = x1;
                    m1 = x1;
                    while (work[y1][l1] != 0)
                        l1 = l1 - 1;
                    while (work[y1][m1] != 0)
                        m1 = m1 + 1;
                    x1 = (l1 + m1) / 2;
                }
                else if ( work[y1][x1] % 2 == 0 ){
                    l1 = y1;
                    m1 = y1;
                    
                    while (work[l1][x1] != 0){
                        l1 = l1 - 1;
                        //std::cout << l1 << " " << x1 << " " << work[l1][x1] << std::endl;
                    }
                    //std::cout << "l1 = " <<  l1 << " ";
                    //std::cout << l1 << " ";
                    //std::cout << std::endl;
                    while (work[m1][x1] != 0){
                        m1 = m1 + 1;
                        //std::cout << m1 << " ";
                    }
                    //std::cout << m1 << " ";
                    y1 = (l1 + m1) / 2;
                }
                //std::cout << m1 << " ";
                
                unsigned l2 = 0;
                unsigned m2 = 0;
                if ( work[y2][x2] % 2 == 1 ){
                    l2 = x2;
                    m2 = x2;
                    while (work[y2][l2] != 0)
                        l2 = l2 - 1;
                    while (work[y2][m2] != 0)
                        m2 = m2 + 1;
                    x2 = (l2 + m2) / 2;
                }
                else if ( work[y2][x2] % 2 == 0 ){
                    l2 = y2;
                    m2 = y2;
                    while (work[l2][x2] != 0)
                        l2 = l2 - 1;
                    while (work[m2][x2] != 0)
                        m2 = m2 + 1;
                    y2 = (l2 + m2) / 2;
                }
                
                std:: cout << y1 << " " << x1 << " " << y2 << " " << x2 << std::endl;
                //строим соединительные линии  
                //if (y1 == y2){ //прямые
                if ((y1 + 5 > y2 - 5) && (y1 - 5 < y2 + 5)){
                    if (x1 > x2){
                        swap(x1,x2);
                        swap(y1,y2);
                    }
                    for (unsigned l = y1 - 2; l < y1 + 3; l++)
                        for (unsigned m = x1 + 1; m < x1 + 10; m++)
                            work[l][m] = 254;
                    if (y2 > y1){
                        for (unsigned l = y1 - 2; l < y2 + 3; l++)
                            for (unsigned m = x1 + 10; m < x1 + 15; m++)
                                work[l][m] = 254;
                        for (unsigned l = y2 - 2; l < y2 + 3; l++)
                            for (unsigned m = x1 + 15; m < x2; m++)
                                work[l][m] = 254;
                    }
                    else{
                        for (unsigned l = y2 - 2; l < y1 + 3; l++)
                            for (unsigned m = x1 + 10; m < x1 + 15; m++)
                                work[l][m] = 254;
                        for (unsigned l = y2 - 2; l < y2 + 3; l++)
                            for (unsigned m = x1 + 15; m < x2; m++)
                                work[l][m] = 254;
                    }
                }
                else //if (x1 == x2){
                    if ((x1 + 5 > x2 - 5) && (x1 - 5 < x2 + 5)){
                    if (y1 > y2){
                        swap(x1,x2);
                        swap(y1,y2);
                    }
                    for (unsigned l = x1 - 2; l < x1 + 3; l++)
                        for (unsigned m = y1 + 1; m < y2; m++)
                            work[m][l] = 254;
                }    
                else {   //углы
                    if (x1 > x2){
                        swap(x1,x2);
                        swap(y1,y2);
                    }
                    if ((work[y1 - 1][x1] == 0) && (work[y2][x2 - 1] == 0)){
                        for (unsigned l = y2 - 2; l < y1; l++)
                            for (unsigned m = x1 - 2; m < x1 + 3;m++)
                                work[l][m] = 254;
                        for (unsigned l = y2 - 2; l < y2 + 3; l++)
                            for (unsigned m = x1 + 3; m < x2; m++)
                                work[l][m] = 254;
                    }
                    if ((work[y1][x1 + 1] == 0) && (work[y2 - 1][x2] == 0)){
                        for (unsigned l = y1 - 2; l < y2; l++)
                            for (unsigned m = x2 - 2; m < x2 + 3;m++)
                                work[l][m] = 254;
                        for (unsigned l = y1 - 2; l < y1 + 3; l++)
                            for (unsigned m = x1 + 1; m < x2 - 2; m++)
                                work[l][m] = 254;
                    }
                    if ((work[y1][x1 + 1] == 0) && (work[y2 + 1][x2] == 0)){
                        for (unsigned l = y2 + 1; l < y1 + 3; l++)
                            for (unsigned m = x2 - 2; m < x2 + 3;m++)
                                work[l][m] = 254;
                        for (unsigned l = y1 - 2; l < y1 + 3; l++)
                            for (unsigned m = x1 + 1; m < x2 - 2; m++)
                                work[l][m] = 254;
                    }
                    if ((work[y1 + 1][x1] == 0) && (work[y2][x2 - 1] == 0)){
                        for (unsigned l = y1 + 1; l < y2 + 3; l++)
                            for (unsigned m = x1 - 2; m < x1 + 3;m++)
                                work[l][m] = 254;
                        for (unsigned l = y2 - 2; l < y2 + 3; l++)
                            for (unsigned m = x1 + 3; m < x2; m++)
                                work[l][m] = 254;
                    }
                }
            
            }   
    
   
    

    //блок подстановки элементов
  

    Mat el;
    std::cout << "elements" << std:: endl;
    for (unsigned i = 0; i < y2- y1 + 61; i++)
        for(unsigned j = 0; j < x2 - x1 + 61; j++){
            if ((work[i][j] > 0) && (work[i][j] < 19)){
                //std::cout << work[i][j] << " " << i << " " << j << std ::endl;
                std::string element = "elements/" + std::to_string(work[i][j]) + ".jpg";
                el = cv::imread(element);
                for( int i1 = 0; i1 < el.rows; i1++ ){
                    for( int j1 = 0; j1 < el.cols; j1++ ){
                        if ((int(el.at<cv::Vec3b>(i1,j1)[0]) > 50) || (int(el.at<cv::Vec3b>(i1,j1)[1]) > 50) || (int(el.at<cv::Vec3b>(i1,j1)[2]) > 50))
                        {    
                            el.at<cv::Vec3b>(i1,j1)[0] = 255;
                            el.at<cv::Vec3b>(i1,j1)[1] = 255;
                            el.at<cv::Vec3b>(i1,j1)[2] = 255;
                        }
                        else
                        {
                            el.at<cv::Vec3b>(i1,j1)[0] = 0;
                            el.at<cv::Vec3b>(i1,j1)[1] = 0;
                            el.at<cv::Vec3b>(i1,j1)[2] = 0;
                        }
                    }
                }
                unsigned y5 = i;
                unsigned x5 = j;
                while (work[y5 + 1][j] != 0)
                    y5++;
                while (work[i][x5 + 1] != 0)
                    x5++;
                //std::cout<< i << " " << x5 <<std::endl << y5 << " " << j << std :: endl << "next\n";
                unsigned dir = work[y5][x5] % 2;
                for (unsigned i1 = i; i1 <= y5;i1++)
                    for (unsigned j1 = j; j1 <= x5; j1++)
                        work[i1][j1] = 0;
                y5 = (i + y5) / 2;
                x5 = (j + x5) / 2;
                //unsigned dir = work[y5][x5] % 2;
                //std::cout << y5 << " " << x5 << " " << work[y5][x5] << std ::endl;
                for (unsigned i1 = y5 - el.rows / 2; i1 < y5 + el.rows / 2 - 5; i1++)
                    for (unsigned j1 = x5 - el.cols / 2; j1 < x5 + el.cols / 2 - 5; j1++)
                        work[i1][j1] = el.at<cv::Vec3b>(i1 - y5 + el.rows / 2,j1 - x5 + el.cols / 2)[0];
                
                unsigned x6 = x5;
                unsigned y6 = y5;
                unsigned x7 = x5;
                unsigned y7 = y5;
                if (dir == 1){ //вертикальные провода
                    while (work[y6][x6] == 0)
                        y6++;
                    y6 += 7;
                    while (work[y7][x7] == 0)
                        y7--;
                    y7 -= 7;
                    unsigned x8 = x6;
                    unsigned x9 = x7;
                    unsigned y8 = y6;
                    unsigned y9 = y7;
                    y6 -= 4;
                    y7 += 4;
                    while (work[y8][x8] == 0)
                        y8++;
                    while (work[y9][x9] == 0)
                        y9--;
                    for (unsigned i1 = y6; i1 < y8; i1++)
                        for (unsigned j1 = x6 - 2; j1 < x6 + 3; j1++)
                            work[i1][j1] = 255;
                    for (unsigned i1 = y9; i1 < y7; i1++)
                        for (unsigned j1 = x7 - 2; j1 < x7 + 3; j1++)
                            work[i1][j1] = 255;
                    std::cout << "y9 = " << y9 << " y7 = " << y7 << " y6 = " << y6 << " y8 = " << y8 << std::endl;
                }else{
                    while (work[y6][x6] == 0)
                        x6++;
                    x6 += 7;
                    while (work[y7][x7] == 0)
                        x7--;
                    x7 -= 7;
                    unsigned x8 = x6;
                    unsigned x9 = x7;
                    unsigned y8 = y6;
                    unsigned y9 = y7;
                    x6 -= 4;
                    x7 += 4;
                    while (work[y8][x8] == 0)
                        x8++;
                    while (work[y9][x9] == 0)
                        x9--;
                    for (unsigned i1 = x6; i1 < x8; i1++)
                        for (unsigned j1 = y6 - 2; j1 < y6 + 3; j1++)
                            work[j1][i1] = 255;
                    for (unsigned i1 = x9; i1 < x7; i1++)
                        for (unsigned j1 = y7 - 2; j1 < y7 + 3; j1++)
                            work[j1][i1] = 255;
                }
                
            }
        }
    
    
    //блок обратного отражения
    
    
    for (unsigned i = 0; i < y2- y1 + 61; i++)
            for(unsigned j = 0; j < x2 - x1 + 61; j++){
                dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[0] = work[i][j];
                if ((work[i][j] == 0) || (work[i][j] == 254)){
                    dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[1] = work[i][j];
                    dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[2] = work[i][j];
                }
            }
    //убираем оставшиеся первичные провода
    /*
    for( int i = 0; i < dst.rows; i++ )
        for( int j = 0; j < dst.cols; j++ ){
            if (int(dst.at<cv::Vec3b>(i,j)[0]) == 255)
            {    
                dst.at<cv::Vec3b>(i,j)[0] = 0;
                dst.at<cv::Vec3b>(i,j)[1] = 0;
                dst.at<cv::Vec3b>(i,j)[2] = 0;
            }
        }
        */
    /*
    
    */
        
    /*
    //speed проверка
    for (unsigned i = 0; i < y2- y1 + 61; i++)
            for(unsigned j = 0; j < x2 - x1 + 61; j++){
                if (speed[i][j]){
                    dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[0] = 0;
                    dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[1] = 255;
                    dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[2] = 0;
                }
            }
    for( int i = 0; i < dst.rows; i++ )
        for( int j = 0; j < dst.cols; j++ ){
            if (int(dst.at<cv::Vec3b>(i,j)[0]) == 255)
            {    
                dst.at<cv::Vec3b>(i,j)[0] = 0;
                dst.at<cv::Vec3b>(i,j)[1] = 0;
                dst.at<cv::Vec3b>(i,j)[2] = 0;
            }
        }
    */
    
    for( int i = 0; i < dst.rows; i++ )
        for( int j = 0; j < dst.cols; j++ ){
            if ((int(dst.at<cv::Vec3b>(i,j)[0]) == 0) && (int(dst.at<cv::Vec3b>(i,j)[1]) == 0) && (int(dst.at<cv::Vec3b>(i,j)[2]) == 0))
            {    
                dst.at<cv::Vec3b>(i,j)[0] = 255;
                dst.at<cv::Vec3b>(i,j)[1] = 255;
                dst.at<cv::Vec3b>(i,j)[2] = 255;
                                       
            }
            else
            {
                dst.at<cv::Vec3b>(i,j)[0] = 0;
                dst.at<cv::Vec3b>(i,j)[1] = 0;
                dst.at<cv::Vec3b>(i,j)[2] = 0;
            }
        }
    
   
    //std::cout<<work[10][116];
    
/*
    dst.at<cv::Vec3b>(117 + y1 - 30,1281 + x1 - 30)[0] = 0;
    dst.at<cv::Vec3b>(117 + y1 - 30,1281 + x1 - 30)[1] = 255;
    dst.at<cv::Vec3b>(117 + y1 - 30,1281 + x1 - 30)[2] = 0;

    dst.at<cv::Vec3b>(120 + y1 - 30,584 + x1 - 30)[0] = 0;
    dst.at<cv::Vec3b>(120 + y1 - 30,584 + x1 - 30)[1] = 255;
    dst.at<cv::Vec3b>(120 + y1 - 30,584 + x1 - 30)[2] = 0;

    dst.at<cv::Vec3b>(483 + y1 - 30,111 + x1 - 30)[0] = 0;
    dst.at<cv::Vec3b>(483 + y1 - 30,111 + x1 - 30)[1] = 255;
    dst.at<cv::Vec3b>(483 + y1 - 30,111 + x1 - 30)[2] = 0;

    dst.at<cv::Vec3b>(608 + y1 - 30,1751 + x1 - 30)[0] = 0;
    dst.at<cv::Vec3b>(608 + y1 - 30,1751 + x1 - 30)[1] = 255;
    dst.at<cv::Vec3b>(608 + y1 - 30,1751 + x1 - 30)[2] = 0;

    dst.at<cv::Vec3b>(1095 + y1 - 30,1295 + x1 - 30)[0] = 0;
    dst.at<cv::Vec3b>(1095 + y1 - 30,1295 + x1 - 30)[1] = 255;
    dst.at<cv::Vec3b>(1095 + y1 - 30,1295 + x1 - 30)[2] = 0;

    dst.at<cv::Vec3b>(1097 + y1 - 30,585 + x1 - 30)[0] = 0;
    dst.at<cv::Vec3b>(1097 + y1 - 30,585 + x1 - 30)[1] = 255;
    dst.at<cv::Vec3b>(1097 + y1 - 30,585 + x1 - 30)[2] = 0;
*/
    for (unsigned i = 0; i < y2-y1+61;i++)
        delete [] work[i];
    delete work;
    
    for (unsigned i = 0; i < y2-y1+61;i++)
        delete [] speed[i];
    delete speed;
    
    imwrite( "end3.jpg", dst );
}
