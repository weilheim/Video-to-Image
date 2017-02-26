#include <iostream>
#include <fstream>
#include <string>

#include <direct.h>
#include <cstdlib>

#include "convert.h"

#include "opencv2/opencv.hpp"


using namespace std;
using namespace cv;


int main(int argc, char* argv[]){

	//ImageToVideo("C:/Users/robot1/Desktop/sm video/Wiper SUV", "Wiper SUV", 1, 0, 66, 10);
	VideoToImage("D:/BaiduYunDownload/Groundhog day.mp4");


	//string video = "C:/Users/robot1/Desktop/Supplementary Material/Real-world Videos/Wiper SUV.avi";
	//int slash = video.find_last_of('/');
	//int len = video.length();
	//string folder = video.substr(0, slash+1);
	//string name = video.substr(slash + 1, len - slash - 5);


	//VideoCapture vCap = VideoCapture(video);

	//int vWidth = int(vCap.get(CV_CAP_PROP_FRAME_WIDTH));
	//int vHeight = int(vCap.get(CV_CAP_PROP_FRAME_HEIGHT));
	//int frameRate = int(vCap.get(CV_CAP_PROP_FPS));
	//int nbFrames = int(vCap.get(CV_CAP_PROP_FRAME_COUNT));

	//cout << "width:" << vWidth << endl;
	//cout << "height:" << vHeight << endl;
	//cout << "framerate" << frameRate << endl;

	//Mat orgImage, dstImage;
	//Size s = Size(694, 394);

	//if (vCap.isOpened()) {
	//	for (int i = 1; i <= nbFrames; i++) {

	//		vCap.read(orgImage);
	//		if (vWidth != 694 || vHeight != 394) {
	//			resize(orgImage, dstImage, s);
	//		}
	//		else {
	//			dstImage = orgImage;
	//		}

	//		char buffer[5];
	//		_itoa_s(i, buffer, 10);
	//		string imageNb = buffer;
	//		//string imageName = folder + name + imageNb + ".jpg";
	//		string imageName = "U:/workspace/Cpp/Video to Image/Video to Image/output/" + name + imageNb + ".jpg";

	//		imwrite(imageName, dstImage);
	//		cout << "frame: " << i << endl;

	//	}
	//}

	return 0;
}