#pragma pack(1)
#pragma pack(2)

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#include "bmp.h"

PBITMAPFILEHEADER file_header;
PBITMAPINFOHEADER info_header;

char *buffer = NULL;

bool fill(){
	ifstream file("img2.bmp");
	
	if(file) {
		file.seekg(0, file.end);
		int length = file.tellg();
		file.seekg(0, file.beg);
		
		if (buffer != NULL)
		{
			delete buffer;
		}
		
		buffer = new char[length];
		
		if (buffer!=NULL)
		{
			file.read(buffer,length);
			file.close();
			
			cout << "Filling buffer.\n" << endl;
			file.close();
			
			file_header = (PBITMAPFILEHEADER)(buffer);
			info_header = (PBITMAPINFOHEADER)(buffer + sizeof(BITMAPFILEHEADER));
			return true;
		}
	}
	return false;
}

int main(void) {

	if (fill())
	{
		
		long length = file_header->bfSize - file_header->bfOffBits;
		int const offset = file_header->bfOffBits;
		int const xpixels = info_header->biWidth;
		int const ypixels = info_header->biHeight;
		int const bytesPixel = 3;
	
		char *pixels = new char[xpixels, ypixels, bytesPixel];
		
		for(int y=0; y<ypixels; y++) {
			for(int x=0; x<xpixels*3; x+=3) {
				pixels[x, y, 0] = buffer[offset + (y*xpixels*3 + x)];
				pixels[x, y, 1] = buffer[offset + (y*xpixels*3 + x)+1];
				pixels[x, y, 2] = buffer[offset + (y*xpixels*3 + x)+2];
				
				
				printf("[%d,%d] %d %d %d\n", x, y, (int)pixels[x, y, 0], (int)pixels[x, y, 1], (int)pixels[x, y, 2]);
			}
		}
	}
	
	return 0;
}
		
