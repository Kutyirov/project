#include "header.hpp"
void delete_noize (Mat &img, unsigned coef){
    //std::cout << "works\n";
    for( int i = 0; i < img.rows; i++ ){
        for( int j = 0; j < img.cols; j++ ){
            if ((int(img.at<cv::Vec3b>(i,j)[0]) > coef) || (int(img.at<cv::Vec3b>(i,j)[1]) > coef) || (int(img.at<cv::Vec3b>(i,j)[2]) > coef))
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
    }
}

void find_elements(int** &work, unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned speed_coef,std::pair<unsigned,bool>** &speed){
    
    std::string capa = "";
    std::string tor = ".jpg";
    std::string ci = "";
    std::string capacitor = "";
    Mat cap;
    //здесь цикл по папкам
    unsigned y3,x3;
    for (unsigned t = 1; t < 10; t++){ //папки
        for (unsigned k = 1; k < 10; k++){ //образы
            capa = std::to_string(t) + "/";
            ci = std::to_string(k);
            capacitor = capa + ci + tor;
            cap = cv::imread(capacitor);
            if(cap.data ) {
                std::cout << capacitor << std::endl;
            }
            delete_noize(cap,50);
            y3 = y2 + 60 - y1 - cap.rows;
            x3 = x2 + 60 - x1 - cap.cols;
            for(unsigned i = 0; i < y3; i++){
                for(unsigned j = 0; j < x3; j++){
                    unsigned quanity = 0;
                    if (speed[i][j].second)
                    for (unsigned i1 = 0; i1 < cap.rows; i1++)
                        for (unsigned j1 = 0; j1 < cap.cols; j1++)
                            if (work[i+i1][j+j1] == int(cap.at<cv::Vec3b>(i1,j1)[0]))
                                quanity++;
                    if (quanity > cap.rows*cap.cols-400)
                    for (unsigned i1 = i; i1 < cap.rows+i; i1++)
                        for (unsigned j1 = j; j1 < cap.cols+j; j1++)
                            work[i1][j1] = t;
                }
            }
                
        }
    }
    
}

void find_wire(int** &work, unsigned x1, unsigned y1, unsigned x2, unsigned y2){
    for(unsigned i = 0; i < y2-y1+61;i++)
        for (unsigned j = 0; j < x2 - x1 + 61; j++)
            
            if (work[i][j] == 255){ //ищем крайние точки
            std::cout << "i = " << i << " j = " << j << std::endl;
                
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
                std::cout << "first\n"; 
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
                    std::cout << y1 << " " << x1 << " " << direction1 << " " << number << " " << work[y1][x1]<<std::endl;
                }         
                std::cout << "second\n";   
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
                    std::cout << y2 << " " << x2 << " " << direction2 << " " << number << " " << work[y2][x2] << std::endl;
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
                
                std:: cout << std::endl << y1 << " " << x1 << " " << y2 << " " << x2 << std::endl;
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
    
}

void push_elements(int** &work, unsigned x1, unsigned y1, unsigned x2, unsigned y2){
    Mat el;
    std::cout << "elements" << std:: endl;
    for (unsigned i = 0; i < y2- y1 + 61; i++)
        for(unsigned j = 0; j < x2 - x1 + 61; j++){
            if ((work[i][j] > 0) && (work[i][j] < 19)){
                //std::cout << work[i][j] << " " << i << " " << j << std ::endl;
                std::string element = "elements/" + std::to_string(work[i][j]) + ".jpg";
                el = cv::imread(element);
                delete_noize(el,50);
               
               
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
                    //std::cout << "y9 = " << y9 << " y7 = " << y7 << " y6 = " << y6 << " y8 = " << y8 << std::endl;
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
}