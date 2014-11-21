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

bool BMPImage::read(ifstream& fin) {

// Reads file header.

	fin.read(bfType, 2);
	fin.read(bfSize, 4);
	fin.read(bfReserved1, 2);
	fin.read(bfReserved2, 2);
	fin.read(bfOffBits, 4);
	
// Reads image header.
	
	fin.read(biSize, 4);
	fin.read(biWidth, 4);
	fin.read(biHeight, 4);
	fin.read(biPlanes, 2);
	fin.read(biBitCount, 2);
	fin.read(biCompression, 4);
	fin.read(biSizeImage, 4);
	fin.read(biXPelsPerMeter, 4);
	fin.read(biYPelsPerMeter, 4);
	fin.read(biClrUsed, 4);
	fin.read(biClrImportant, 4);
	
// Reads pixel data into pixelData array. Bit depth is assumed to be 24.

    int pixelDataLength = bfSize - bfOffBits;
    
// Needs loop to account for padding based on row length.

    fin.read(pixelData, pixelDataLength);
    


    

    
    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
