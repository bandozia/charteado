#include <iostream>
#include <opencv2/opencv.hpp>
#include <charteado/histograms.h>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
    Mat teste = imread("/home/bruno/projetos/charteado/img/nature.jpg");
	Mat mat = chato::HsvImage1DHist(teste, 1280, 720, true);
	imshow("teste", mat);	
	waitKey();
	
    return 0;
}
