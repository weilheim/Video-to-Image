#ifndef _CONVERT_H_
#define _CONVERT_H_

#include <string>

#include "opencv2/opencv.hpp"

using namespace std;

void VideoToImage(string videoName);

void ImageToVideo(string imagePath, string imN, int step, int firstFrame, int lastFrame, int frameRate);

#endif