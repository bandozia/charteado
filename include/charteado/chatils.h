#pragma once
#include <opencv2/opencv.hpp>


namespace chato
{
	cv::Scalar hsvToRgbColor(float h, float s, float v, bool bgr = true)
	{
		float C = v * s;
		float X = C * (1 - abs(fmod(h / 60, 2) - 1));
		float m = v - C;

		float erregebes[6][3] = { {C,X,0}, {X,C,0}, {0,C,X}, {0,X,C}, {X,0,C}, {C,0,X} };
		float* rgb = erregebes[cvFloor(h / 60)];

		if (bgr)
		{
			return cv::Scalar(cvRound((rgb[2] + m) * 255), cvRound((rgb[1] + m) * 255), cvRound((rgb[0] + m) * 255));
		}
		else
		{
			return cv::Scalar(cvRound((rgb[0] + m) * 255), cvRound((rgb[1] + m) * 255), cvRound((rgb[2] + m) * 255));
		}
	}

	cv::Mat GetChartBackground(int width, int heigth, cv::Vec2f widthRange, cv::Vec2f heigthRange)
	{
		int mw = cvRound(width / 14), mh = cvRound(heigth / 14);
		cv::Mat chartBg(heigth + mh, width + mw, CV_8UC3, cv::Scalar(0, 0, 0));

		float bw = width / 10;

		cv::line(chartBg,
			cv::Point((mw/2) - 1, mh),
			cv::Point((mw/2) - 1, heigth + (mh / 2)),
			cv::Scalar(255, 255, 255), 1);

		cv::line(chartBg,
			cv::Point(mw/4, heigth+2),
			cv::Point(width + (mw/2), heigth+2),
			cv::Scalar(255, 255, 255), 1);

		if (widthRange != cv::Vec2f::zeros())
		{
			assert(widthRange[1] > widthRange[0]);
			
			for (int i = 1; i < bw; i++)
			{
				cv::Point p0((mw/2) + (i * bw), heigth);
								
				cv::line(chartBg,
					p0,
					cv::Point(p0.x, p0.y+10),
					cv::Scalar(255, 255, 255), 1);							
				
				cv::putText(chartBg, std::to_string(cvRound(widthRange[0] + (i * (widthRange[1] / 10)))), cv::Point(p0.x - 10, p0.y + 25), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
			}
		}

		return chartBg;
	}

}