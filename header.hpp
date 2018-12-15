#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
using namespace cv;

void delete_noize (Mat&, unsigned);

void find_elements(int** &, unsigned, unsigned, unsigned, unsigned, unsigned,std::pair<unsigned,bool>**&);

void find_wire(int** &, unsigned, unsigned, unsigned, unsigned);

void push_elements(int** &, unsigned, unsigned, unsigned, unsigned);