#include <iostream>
#include <opencv2/opencv.hpp>
#include <charteado/histograms.h>

using namespace std;
using namespace cv;

void main(int argc, char* argv[])
{
	Mat teste = imread("E:\\Andozianos\\charteado\\img\\face.jpg");		
	Mat mat = chato::HsvImage1DHist(teste, 1280, 720, true);
	imshow("teste", mat);	
	waitKey();
	
	
}