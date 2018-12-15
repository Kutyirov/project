
#include "header.hpp"
using namespace cv;
unsigned low_canny = 100;
unsigned up_canny = 300;
unsigned img_coef = 120;
unsigned speed_coef = 300;

int main(int argc, char** argv) {
  Mat img;
  Mat dst;
  Mat src;
  Mat detected_edges;
  std::string path = "";
  std::cout << "Enter the path to image:";
  std::cin >> path;
  std::cout << "\n";
  img = cv::imread(path);
  src = img;
  if (!img.data) {
    std::cout << "Could not open or find the image" << std::endl;
    return -1;
  }

  Canny(img, detected_edges, low_canny, up_canny);
  dst = Scalar::all(0);

  src.copyTo(dst, detected_edges);

  unsigned x1, y1, x2, y2;
  x1 = 0;
  y1 = 0;
  x2 = 0;
  y2 = 0;

  delete_noise(dst, 0);

  for (unsigned i = 0; i < dst.rows; i++) {
    for (unsigned j = 0; j < dst.cols; j++)
      if (int(dst.at<cv::Vec3b>(i, j)[0]) == 255) {
        y1 = i;
        break;
      }
    if (y1) break;
  }
  for (unsigned j = 0; j < dst.cols; j++)
    for (unsigned i = 0; i < dst.rows; i++) {
      if (int(dst.at<cv::Vec3b>(i, j)[0]) == 255) {
        x1 = j;
        break;
      }
      if (x1) break;
    }
  for (int i = dst.rows - 1; i > 0; i--) {
    for (unsigned j = dst.cols - 1; j > 0; j--)
      if (int(dst.at<cv::Vec3b>(i, j)[0]) == 255) {
        y2 = i;
        break;
      }
    if (y2) break;
  }
  for (int j = dst.cols - 1; j > 0; j--)
    for (unsigned i = dst.rows - 1; i > 0; i--) {
      if (int(dst.at<cv::Vec3b>(i, j)[0]) == 255) {
        x2 = j;
        break;
      }
      if (x2) break;
    }

  // std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
  int** work;
  work = new int*[y2 - y1 + 61];
  for (unsigned i = 0; i < y2 - y1 + 61; i++) work[i] = new int[x2 - x1 + 61];
  for (unsigned i = 0; i < y2 - y1 + 61; i++)
    for (unsigned j = 0; j < x2 - x1 + 61; j++)
      work[i][j] = int(dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0]);

  std::pair<unsigned, bool>** speed;

  speed = new std::pair<unsigned, bool>*[y2 - y1 + 61];
  for (unsigned i = 0; i < y2 - y1 + 61; i++)
    speed[i] = new std::pair<unsigned, bool>[x2 - x1 + 61];
  for (unsigned i = 0; i < y2 - y1 + 61; i++) {
    for (unsigned j = 0; j < x2 - x1 + 61; j++) {
      speed[i][j].second = false;
      speed[i][j].first = 0;
    }
  }

  for (unsigned i = 0; i < y2 - y1 + 61 - 100; i++) {
    for (unsigned j = 0; j < x2 - x1 + 61 - 100; j++) {
      for (unsigned i1 = 0; i1 < 100; i1++)
        for (unsigned j1 = 0; j1 < 100; j1++)
          if (work[i + i1][j + j1] == 255) speed[i][j].first++;
      if (speed[i][j].first > speed_coef) speed[i][j].second = true;
    }
  }

  char answer1 = 'n';
  while (answer1 != 'y') {
    find_elements(work, x1, y1, x2, y2, speed_coef, speed);  //нашли элементы

    for (unsigned i = 0; i < y2 - y1 + 61; i++) {
      for (unsigned j = 0; j < x2 - x1 + 61; j++) {
        dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0] = work[i][j];
        if ((work[i][j] == 0) || (work[i][j] == 254)) {
          dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[1] = work[i][j];
          dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[2] = work[i][j];
        }
      }
    }
    imwrite("end1.jpg", dst);
    std::cout << "is ot ok? y/n\n";
    std::cin >> answer1;
    if (answer1 == 'n') {
      std::cout << "old speed coefficient = " << speed_coef
                << "\nnew speed coefficient=";
      std::cin >> speed_coef;
      std::cout << "\n";
    }
    for (unsigned i = 0; i < y2 - y1 + 61 - 100; i++) {
      for (unsigned j = 0; j < x2 - x1 + 61 - 100; j++) {
        if (speed[i][j].first > speed_coef)
          speed[i][j].second = true;
        else
          speed[i][j].second = false;
      }
    }
  }
  for (unsigned i = 0; i < y2 - y1 + 61; i++) delete[] speed[i];
  delete speed;

  imwrite("end2.jpg", dst);
  //блок сложения изображений
  char answer2 = 'n';
  while (answer2 != 'y') {
    Mat second;
    second = cv::imread(path);
    for (int i = 0; i < second.rows; i++)
      for (int j = 0; j < second.cols; j++) {
        if (int(second.at<cv::Vec3b>(i, j)[0]) +
                int(second.at<cv::Vec3b>(i, j)[1]) +
                int(second.at<cv::Vec3b>(i, j)[2]) <
            img_coef) {
          second.at<cv::Vec3b>(i, j)[0] = 255;
          second.at<cv::Vec3b>(i, j)[1] = 255;
          second.at<cv::Vec3b>(i, j)[2] = 255;

        } else {
          second.at<cv::Vec3b>(i, j)[0] = 0;
          second.at<cv::Vec3b>(i, j)[1] = 0;
          second.at<cv::Vec3b>(i, j)[2] = 0;
        }
      }

    for (unsigned i = 0; i < y2 - y1 + 61; i++)
      for (unsigned j = 0; j < x2 - x1 + 61; j++) {
        if (((work[i][j] == 0) || (work[i][j] > 18)) &&
            (int(second.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0]) == 255))
          work[i][j] = 255;
        if ((work[i][j] == 0) &&
            (int(second.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0]) == 255)) {
          dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0] = 0;
          dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[1] = 0;
          dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[2] = 0;
        }
        if ((int(second.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0]) == 0) &&
            (work[i][j] > 18))
          work[i][j] = 0;
      }
    for (unsigned i = 0; i < y2 - y1 + 61; i++)
      for (unsigned j = 0; j < x2 - x1 + 61; j++) {
        dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0] = work[i][j];
        if ((work[i][j] == 0) || (work[i][j] == 254)) {
          dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[1] = work[i][j];
          dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[2] = work[i][j];
        }
      }

    imwrite("end2.jpg", dst);
    std::cout << "is ot ok? y/n\n";
    std::cin >> answer2;
    if (answer2 == 'n') {
      std::cout << "old image coefficient = " << img_coef
                << "\nnew image coefficient=";
      std::cin >> img_coef;
      std::cout << "\n";
    }
  }
  //преобразование проводов
  find_wire(work, x1, y1, x2, y2);

  //блок подстановки элементов
  push_elements(work, x1, y1, x2, y2);

  //блок обратного отражения

  for (unsigned i = 0; i < y2 - y1 + 61; i++)
    for (unsigned j = 0; j < x2 - x1 + 61; j++) {
      dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0] = work[i][j];
      if ((work[i][j] == 0) || (work[i][j] == 254)) {
        dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[1] = work[i][j];
        dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[2] = work[i][j];
      }
    }

  for (int i = 0; i < dst.rows; i++) {
    for (int j = 0; j < dst.cols; j++) {
      if ((int(dst.at<cv::Vec3b>(i, j)[0]) == 0) &&
          (int(dst.at<cv::Vec3b>(i, j)[1]) == 0) &&
          (int(dst.at<cv::Vec3b>(i, j)[2]) == 0)) {
        dst.at<cv::Vec3b>(i, j)[0] = 255;
        dst.at<cv::Vec3b>(i, j)[1] = 255;
        dst.at<cv::Vec3b>(i, j)[2] = 255;

      } else {
        dst.at<cv::Vec3b>(i, j)[0] = 0;
        dst.at<cv::Vec3b>(i, j)[1] = 0;
        dst.at<cv::Vec3b>(i, j)[2] = 0;
      }
    }
  }

  // std::cout<<work[10][116];

  for (unsigned i = 0; i < y2 - y1 + 61; i++) delete[] work[i];
  delete work;

  // std::string end_path = path + "_"
  imwrite("end3.jpg", dst);
}

        x2 = 0;
        y2 = 0;
    
    delete_noize(dst, 0);

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
    
    std::pair<unsigned,bool>** speed;

    speed = new std::pair<unsigned,bool>*[y2-y1+61];
    for (unsigned i = 0; i < y2-y1+61;i++)
        speed[i] = new std::pair<unsigned,bool>[x2-x1+61];
    for(unsigned i = 0; i < y2-y1+61;i++){
        for (unsigned j = 0; j < x2 - x1 + 61; j++){
            speed[i][j].second = false;
            speed[i][j].first = 0;
        }
    }
    
    for(unsigned i = 0; i < y2-y1+61 - 100;i++){
        for (unsigned j = 0; j < x2 - x1 + 61 - 100; j++){
            for (unsigned i1 = 0; i1 < 100; i1++)
                for (unsigned j1 = 0; j1 < 100; j1++)
                    if (work[i + i1][j + j1] == 255)
                        speed[i][j].first++;
            if (speed[i][j].first > speed_coef)
                speed[i][j].second = true;
        }
    }
    
    char answer1 = 'n';
    while (answer1 != 'y') {
        find_elements(work,x1,y1,x2,y2,speed_coef,speed); //нашли элементы
    
        for (unsigned i = 0; i < y2- y1 + 61; i++){
            for(unsigned j = 0; j < x2 - x1 + 61; j++){
                dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[0] = work[i][j];
                if ((work[i][j] == 0) || (work[i][j] == 254)){
                    dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[1] = work[i][j];
                    dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[2] = work[i][j];
                }
            }
        }
        imwrite("end1.jpg", dst);
        std::cout << "is ot ok? y/n\n";
        std::cin >> answer1;
        if (answer1 == 'n') {
            std::cout << "old speed coefficient = " << speed_coef << "\nnew speed coefficient=";
            std::cin >> speed_coef;
            std::cout << "\n";
        }
        for(unsigned i = 0; i < y2-y1+61 - 100;i++){
            for (unsigned j = 0; j < x2 - x1 + 61 - 100; j++){
                if (speed[i][j].first > speed_coef)
                    speed[i][j].second = true;
                else 
                    speed[i][j].second = false;
            }
        }
    }
    for (unsigned i = 0; i < y2-y1+61;i++)
        delete [] speed[i];
    delete speed;
        

    imwrite( "end2.jpg", dst );
    //блок сложения изображений
    char answer2 = 'n';
    while (answer2 != 'y') {
        Mat second;
        second = cv::imread(path);
        for (int i = 0; i < second.rows; i++)
            for (int j = 0; j < second.cols; j++) {
                if (int(second.at<cv::Vec3b>(i, j)[0]) +
                    int(second.at<cv::Vec3b>(i, j)[1]) +
                    int(second.at<cv::Vec3b>(i, j)[2]) <
                    img_coef) {
                        second.at<cv::Vec3b>(i, j)[0] = 255;
                        second.at<cv::Vec3b>(i, j)[1] = 255;
                        second.at<cv::Vec3b>(i, j)[2] = 255;

                } else {
                    second.at<cv::Vec3b>(i, j)[0] = 0;
                    second.at<cv::Vec3b>(i, j)[1] = 0;
                    second.at<cv::Vec3b>(i, j)[2] = 0;
                }
            }

        for (unsigned i = 0; i < y2 - y1 + 61; i++)
            for (unsigned j = 0; j < x2 - x1 + 61; j++) {
                if (((work[i][j] == 0) || (work[i][j] > 18)) &&
                    (int(second.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0]) == 255))
                        work[i][j] = 255;
                if ((work[i][j] == 0) &&
                    (int(second.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0]) == 255)) {
                        dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0] = 0;
                        dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[1] = 0;
                        dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[2] = 0;
                }
                if ((int(second.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0]) == 0) &&
                    (work[i][j] > 18))
                        work[i][j] = 0;
            }
        for (unsigned i = 0; i < y2 - y1 + 61; i++)
            for (unsigned j = 0; j < x2 - x1 + 61; j++) {
                dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[0] = work[i][j];
                if ((work[i][j] == 0) || (work[i][j] == 254)) {
                    dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[1] = work[i][j];
                    dst.at<cv::Vec3b>(y1 + i - 30, x1 + j - 30)[2] = work[i][j];
                }
            }

        imwrite("end2.jpg", dst);
        std::cout << "is ot ok? y/n\n";
        std::cin >> answer2;
        if (answer2 == 'n') {
            std::cout << "old image coefficient = " << img_coef << "\nnew image coefficient=";
            std::cin >> img_coef;
            std::cout << "\n";
        }
    }    
    //преобразование проводов
    find_wire(work,x1,y1,x2,y2);
   
    //блок подстановки элементов
    push_elements(work,x1,y1,x2,y2);
    
    //блок обратного отражения
    
    
    for (unsigned i = 0; i < y2- y1 + 61; i++)
        for(unsigned j = 0; j < x2 - x1 + 61; j++){
            dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[0] = work[i][j];
            if ((work[i][j] == 0) || (work[i][j] == 254)){
                dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[1] = work[i][j];
                dst.at<cv::Vec3b>(y1 + i - 30,x1 + j - 30)[2] = work[i][j];
            }
        }

    
    for( int i = 0; i < dst.rows; i++ ){
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
    }
   
    //std::cout<<work[10][116];
    

    for (unsigned i = 0; i < y2-y1+61;i++)
        delete [] work[i];
    delete work;
    
    
    //std::string end_path = path + "_"
    imwrite( "end3.jpg", dst );
    
}
