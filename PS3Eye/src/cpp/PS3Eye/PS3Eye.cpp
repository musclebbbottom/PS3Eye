#include "stdafx.h"
#include "PS3Eye.h"
#include <stdio.h>

PS3Eye::PS3Eye(){


}
PS3Eye::~PS3Eye(){

}

void PS3Eye::start(int _w, int _h, int _rate){

	this->imageWidth = _w;
	this->imageHeight = _h;
	this->rate = _rate;

	pCam=IPS3EyeLib::Create();
	pBuffer=new BYTE[(640*480*24)/8];
	this->cameraPixels = new unsigned char[_w*_h*3];
	pCam->SetFormat(IPS3EyeLib::GetFormatIndex(_w,_h,_rate));
	pCam->StartCapture();
}

void PS3Eye::stop(){
	delete [] pBuffer;
	delete [] this->cameraPixels;
	pCam->StopCapture();
	pCam->LED(false);
	delete pCam;
}

void PS3Eye::update(){
	if(pCam->GetFrame(this->cameraPixels, 24, false))
	{
		//printf("update\n");
		// Process/display video frame here
		// ...
		// If your program is done set 'done=true;'
	}
}

int PS3Eye::width(){
	return this->imageWidth;
}
int PS3Eye::height(){
	return this->imageHeight;
}

unsigned char *PS3Eye::image(){
	return this->cameraPixels;
}
