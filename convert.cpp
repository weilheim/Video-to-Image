#include <iostream>
#include <fstream>
#include <string>

#include <direct.h>
#include <cstdlib>

#include "opencv2/opencv.hpp"

#include "convert.h"

using namespace std;
using namespace cv;

void VideoToImage(string videoPath){

	//string videoPath("C:/Users/robot1/Desktop/Graffiti/VID_20161020_130548.mp4");
	string videoName = videoPath.substr(19, 5);
	cout << videoName << endl;

	cv::VideoCapture vCap(videoPath);
	cv::Mat img;

	string fileName = videoPath.substr(0, 24);
	fileName.append(".avi");
	cout << fileName << endl;
	int vWidth = int(vCap.get(CV_CAP_PROP_FRAME_WIDTH));
	int vHeight = int(vCap.get(CV_CAP_PROP_FRAME_HEIGHT));
	int frameRate = int(vCap.get(CV_CAP_PROP_FPS));

	Size size(vWidth, vHeight);
	cv::VideoWriter vWri = VideoWriter(fileName, CV_FOURCC('M', 'J', 'P', 'G'), frameRate, size);

	int nbFrames;
	nbFrames = vCap.get(CV_CAP_PROP_FRAME_COUNT);


	string folderName("./output/Paper test/");
	folderName.append(videoName);

	_mkdir(folderName.c_str());

	int j = 1;
	while (j++ < nbFrames) {

		char buffer[7];
		_itoa_s(j - 1, buffer, 10);

		string imgNb(buffer);
		if (imgNb.length() < 7) {
			imgNb.insert(0, 7 - imgNb.length(), '0');
		}
		string imgName(folderName);
		imgName = imgName.append("/I_");
		imgName = imgName.append(imgNb);
		imgName = imgName.append(".jpg");

		vCap.read(img);
		vWri.write(img);
		cv::imwrite(imgName, img);

		cout << j << endl;
	}

}

void ImageToVideo(string folderName, string imN, int step, int firstFrame, int lastFrame, int frameRate){

	string videoName;
	videoName = folderName;
	videoName.append(".avi");

	cv::Mat img;

	char buffer[5];
	_itoa_s(firstFrame, buffer, 10);

	string imgNb(buffer);
	//while (imgNb.length() < 5) {
	//	imgNb.insert(size_t(0), '0');
	//}

	string imgName(folderName);
	imgName = imgName.append("/");
	imgName = imgName.append(imN);
	imgName = imgName.append(imgNb);
	imgName = imgName.append(".jpg");

	img = imread(imgName);
	Size imgSize = img.size();
	VideoWriter vW = VideoWriter(videoName, CV_FOURCC('M', 'J', 'P', 'G'), (double)frameRate, imgSize);

	for (int j = 1; j <= 8; j++) {
		vW.write(img);
	}

	//namedWindow("Img");
	//imshow("Img", img);

	for (int j = firstFrame + step; j <= lastFrame; j = j + step){

		char buffer[5];
		_itoa_s(j, buffer, 10);

		string imgNb(buffer);
		/*while (imgNb.length() < 5) {
			imgNb.insert(size_t(0), '0');
		}*/

		string imgName(folderName);
		imgName = imgName.append("/");
		imgName = imgName.append(imN);
		imgName = imgName.append(imgNb);
		imgName = imgName.append(".jpg");

		img = imread(imgName);
		vW.write(img);
		//vW.write(img);
		//vW.write(img);

	}

}