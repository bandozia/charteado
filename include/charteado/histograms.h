#pragma once
#include <opencv2/opencv.hpp>
#include "chatils.h"

namespace chato
{
	using namespace cv;
	void AutoImageHist(Mat src, int width, int heigth)
	{
		std::cout << src.channels() << std::endl;
	}

	void AutoImageHist(const char* imgPath, int width, int heigth)
	{
		Mat src = imread(imgPath);
		AutoImageHist(src, width, heigth);
	}

	Mat HsvImage1DHist(Mat src, int width, int heigth, bool colorfull = false)
	{				
		Mat hsv;
		cvtColor(src, hsv, COLOR_BGR2HSV);

		int histSize = 180;
		float range[] = { 0,180};
		const float* histRange = { range };
		const int chanels[] = { 0 };
		MatND hist;
		calcHist(&hsv, 1, chanels, Mat(), hist, 1, &histSize, &histRange, true, false);

		Mat histPlot = GetChartBackground(width, heigth, Vec2f(0,180), Vec2f(0,0));

		normalize(hist, hist, 0, heigth, NORM_MINMAX);

		int bw = cvRound(width / histSize);
		int mw = cvRound(width / 14);
		
		float* p = hist.ptr<float>();

		//TODO: montar o grafico transparente tembem

		for (int i = 1; i < histSize; i++)
		{
			line
			(
				histPlot,
				Point((mw / 2) + bw * (i-1), heigth - cvRound(p[i-1])),
				Point((mw / 2) + bw * i, heigth - cvRound(p[i])),
				colorfull ? hsvToRgbColor((float)i*2, 1, 1) : Scalar(255, 255, 255, 255),
				1
			);
		}
		return histPlot;
	}
}

