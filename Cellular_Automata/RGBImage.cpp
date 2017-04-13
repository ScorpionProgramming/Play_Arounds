﻿#include "RGBImage.h"

RGBImage::RGBImage(unsigned int Width, unsigned int Height)
{
	m_Width = Width;
	m_Height = Height;
	m_Image = new Color[Width * Height];
}

RGBImage::RGBImage()
{
	
}

RGBImage::~RGBImage()
{
	delete m_Image;
	delete m_Image_r;
}

void RGBImage::setPixelColor(unsigned int x, unsigned int y, const Color & c)
{
	if(x >= 0 && x <= m_Width-1 && y >= 0 && y < m_Height)
		m_Image[ x + y * m_Width] = c;
}

const Color & RGBImage::getPixelColor(unsigned int x, unsigned int y) const
{
	if (x >= 0 && x <= m_Width-1 && y >= 0 && y < m_Height)
		return m_Image[ x + y * m_Width];
}

unsigned int RGBImage::width() const
{
	return m_Width;
}

unsigned int RGBImage::height() const
{
	return m_Height;
}

unsigned char* RGBImage::getCharImage()
{
	return m_Image_r;
}

unsigned char RGBImage::convertColorChannel(float f)
{
	if (f<0) return (int)(0);
	if (f>255) return (int)(255);
	return (int)(floor(f * 255));
}

bool RGBImage::saveToDisk(const char * Filename)
{
	int w = this->m_Width;
	int h = this->m_Height;

	FILE *f;
	unsigned char *img = NULL;
	int filesize = 54 + 3 * w*h;
	if (img) free(img); // Ist das her �berhaupt n�tig?

	img = (unsigned char *)malloc(filesize);
	memset(img, 0, sizeof(img));

	int x, y;
	for (x = 0; x<w; x++)
	{
		for (y = 0; y<h; y++)
		{
			Color c = this->m_Image[y*this->m_Width + x];

			img[(x + y*w) * 3 + 2] = this->convertColorChannel(c.R);
			img[(x + y*w) * 3 + 1] = this->convertColorChannel(c.G);
			img[(x + y*w) * 3 + 0] = this->convertColorChannel(c.B);
		}
	}
	unsigned char bmpfileheader[14] = { 'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };
	unsigned char bmpinfoheader[40] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0 };
	unsigned char bmppad[3] = { 0, 0, 0 };

	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);

	bmpinfoheader[4] = (unsigned char)(w);
	bmpinfoheader[5] = (unsigned char)(w >> 8);
	bmpinfoheader[6] = (unsigned char)(w >> 16);
	bmpinfoheader[7] = (unsigned char)(w >> 24);
	bmpinfoheader[8] = (unsigned char)(h);
	bmpinfoheader[9] = (unsigned char)(h >> 8);
	bmpinfoheader[10] = (unsigned char)(h >> 16);
	bmpinfoheader[11] = (unsigned char)(h >> 24);

	f = fopen(Filename, "wb");
	fwrite(bmpfileheader, 1, 14, f);
	fwrite(bmpinfoheader, 1, 40, f);

	int i;
	for (i = 0; i<h; i++)
	{
		fwrite(img + (w*(h - i - 1) * 3), 3, w, f);
		fwrite(bmppad, 1, (4 - (w * 3) % 4) % 4, f);
	}
	fclose(f);
	free(img);
	return true;
}

bool RGBImage::loadFromDisk(const char * Filename)
{
	
	/*
	TODO Bumpmap Images Header Dateien ausgeben

	http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/

	https://de.wikipedia.org/wiki/Windows_Bitmap
	*/
	FILE *file = fopen(Filename, "rb");
	if (!file) {
		std::cout << "Bild konnte nicht ge�ffnet werden" << std::endl;
		return false;
	}
	unsigned char bfheader[54];
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
							    
	unsigned char *rgbdata; // Actual RGB data

	if (fread(bfheader, 1, 54, file) != 54) {
		std::cout << "Keine BMP - Datei" << std::endl;
		return false;
	}

	if (bfheader[0] != 'B' || bfheader[1] != 'M') {
		std::cout << "Keine BMP - Datei" << std::endl;
		return 0;
	}

	dataPos = bfheader[10];
	width = bfheader[18];
	height = bfheader[22];
	imageSize = bfheader[34];

	//Falls es nicht korrekt geladen werden kann gibt es noch 'diese' m�glichkeit
	if (width <= 0 || height <= 0) {
		dataPos		= *(int*)&bfheader[0x0A];
		imageSize	= *(int*)&bfheader[0x22];
		width		= *(int*)&bfheader[0x12];
		height		= *(int*)&bfheader[0x16];
	}
	if (imageSize == 0) {
		imageSize = width * height * 3; // 3 f�r jede pixelfarbe rot gr�n blau
	}
	if (dataPos == 0) {
		dataPos = 54;
	}

	//create Buffer
	rgbdata = new unsigned char[imageSize];

	fread(rgbdata, 1, imageSize, file);

	//So sollte das Klappen.
	m_Width = width;
	m_Height = height;
	m_Image = new Color[width * height];
	m_Image_r = new unsigned char[width * height * 3];
	
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			//RGB farben
			//Bild wird von "unten nach Oben" interpretiert
			setPixelColor(x, width - (y + 1), //ohne width-(y+1) steht es beim speichern auf dem Kopf und bei OpenGL nicht, und mit ist es genau umgekehrt
				Color(convertColorChannel((int)rgbdata[(x + y*width) * 3 + 2]),
					convertColorChannel((int)rgbdata[(x + y*width) * 3 + 1]),
					convertColorChannel((int)rgbdata[(x + y*width) * 3 + 0])
				));
		}
	}

	//fill the data for the output to openGL shader image loader
		for (int x = 0; x<width; x++)
		{
			for (int y = 0; y<height; y++)
			{
		Color c = this->m_Image[x + this->m_Width * y];

		m_Image_r[(x + y*width) * 3 + 2] = this->convertColorChannel(c.B);
		m_Image_r[(x + y*width) * 3 + 1] = this->convertColorChannel(c.G);
		m_Image_r[(x + y*width) * 3 + 0] = this->convertColorChannel(c.R);
	}
}

	//m_Image_r = rgbdata;
	fclose;
	return true;
}
