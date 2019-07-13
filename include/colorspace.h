#ifndef __COLORSPACE__
#define __COLORSPACE__

struct ColorHSV
{
	double hue;
	double sat;
	double val;
};

struct ColorRGB
{
	char r;
	char g;
	char b;
};

struct ColorHSV rgbToHsv(struct ColorRGB rgb);
struct colorRGB hsvToRgb(struct ColorHSV hsv);

#endif
