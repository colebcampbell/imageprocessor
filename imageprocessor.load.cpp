/*  Image Processor Main Function
    Reads an image into a 3D array (x, y, color).
    Each pixel is an object consisting of RGB values.
  
    Other functions will be developed to modify and save images.
  
    Konrad Erlends, Cole Campbell
    2014-11
   
    To-Do: 
        Change variable types for BMPImageHeader to save memory.

*/

#include <iostream>
#include <fstream>

// For I/O stream formatting. May not be used.

#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Classes /////////////////////////////////////////////////////////////////////

using namespace std;

class Image {	// Base image class. Stores only generic pixel data.
    friend class BMPImage;
private:
	vector <char*> pixelData; // Vector of sequentially stored pixels.
	long length;

public:

// Virtual so that specific filetypes can be read and saved.

    virtual bool read(ifstream& fin) {}
    virtual bool save(ofstream& fout) {}
    
// Filters are generic, acting only on pixel data.

	resize(int x, int y);
};

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
	
public:
    bool read(ifstream& fin);
    bool save(ofstream& fout);
};

// Main ////////////////////////////////////////////////////////////////////////


int main (int argc, char* argv[]) { // Needs to be modified to make use of 
                                    // command line arguments.

// Input Argument Setup
    
    for (int i = 0; i < argc; i++) {
        if (argv[i] == "-i") {		// Defines infile.
        	ifstream fin (argv[i+1]);
        }
        if (argv[i] == "-o") {		// Defines outfile.
        	ofstream fout (argv[i+1]);
        }
    }
    
    if (read(fin)) // Calls read function
	{
		long length = file_header->bfSize - file_header->bfOffBits;
		
/* Commented out until I get to understanding it.
		
// Needs to accomodate the fact that bfOffBits is part of the offset.

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

*/

    return 0;
}

// BMPImage methods ////////////////////////////////////////////////////////////

/* Reads an image file, return value indicates success. Most likely needs
   more error checking, especially to make sure pixel data is valid. 
   
   I think buffer should be an intermediary, used only to bring the data in.
   After the data is read it should be sifted into the headers and PixelData. */

bool BMPImage::read(ifstream& fin) {
	
	if(fin) {
	
// Seeks to end to get length, seeks back to start for actual reading.
// Could possibly be replaced with better notation.

		fin.seekg(0, fin.end);
		int length = fin.tellg();
		fin.seekg(0, fin.beg);
		
// Checks for existing file buffer and deletes if found.
		
		if (buffer != NULL)
		{
			delete buffer;
		}
		
// Initializes new buffer.
		
		buffer = new char[length];
		
// Fills buffer, closes file.
		
		fin.read(buffer,length);
		fin.close();
		
		cout << "Buffer filled." << endl;
		
		/* What are the following things? They don't have a datatype.
		
		fin_header = (PBITMAPFILEHEADER)(buffer);
		info_header = (PBITMAPINFOHEADER)(buffer + sizeof(BITMAPFILEHEADER));
		
		*/
		
		return true;
	}
	return false;
}
