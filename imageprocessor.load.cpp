// Image Processor Main Function
// Reads an image into a 3D array (x, y, color).
// Each pixel is an object consisting of RGB values.
//
// Other functions will be developed to modify and save images.
//
// Cole Campbell
// 2014-11-14

#include <iostream>
#include <vector>

using namespace std;

class Image {	// Base image class.
	friend class BMPImage;
private:
	vector <unsigned char*> pixelData;

public:
	save(fout);
	resize(int x, int y);

//};

class BMPImage : private Image {	// BMP specific header data.
private:
	string bfType;
	int bfSize;
	short int bfReserved1;
	short int bfReserved2;
	int bfOffBits;

	int biSize;
	int biWidth;
	int biHeight;
	short int biPlanes;
	short int biBitCount;
	int biCompression;
	int biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	int biClrUsed;
	int biClrImportant;
};


int main (int argc, char* argv[]) { // Needs to be modified to make use of 
                                    // command line arguments.

//Input Argument Setup//////////////////////////////////////////////////////////
    
    for (int i = 0; i < argc; i++) {
        if (argv[i] == "-i") {		// Defines infile.
        	ifstream fin (argv[i+1]);
        }
        if (argv[i] == "-o") {		// Defines outfile.
        	ofstream fout (argv[i+1]);
        }
    }
    
////////////////////////////////////////////////////////////////////////////////



    return 0;
}
