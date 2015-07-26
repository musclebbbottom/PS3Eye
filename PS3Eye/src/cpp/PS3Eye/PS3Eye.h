// PS3Eye.h
#include "IPS3EyeLib.h"

//using namespace System;

class PS3Eye{
public:
	PS3Eye();
	~PS3Eye();
//	IPS3EyeLib *pCam;
//	PBYTE pBuffer;
	void start(int w, int h, int rate);
	void stop();
	void update();

	int width();
	int height();

	unsigned char *image();

private:
	IPS3EyeLib *pCam;

	PBYTE pBuffer;

	int imageWidth;
	int imageHeight;
	int rate;

	unsigned char *cameraPixels;
};
