/*
 * This file borrows heavily from Robert Atkins' RGBConverter library,
 * reproduced under the terms of the WTFPL.
 *
 * The original library may be found on Github:
 * https://github.com/ratkins/RGBConverter/
 */
#include <Arduino.h>
#include "colorspace.h"

struct ColorHSV rgbToHsv(struct ColorRGB rgb)
{
    double rd = (double) rgb.r/255;
    double gd = (double) rgb.g/255;
    double bd = (double) rgb.b/255;
    double max = max(rd, max(gd, bd));
    double min = min(rd, min(gd, bd));

    double h, s, v = max;

    double d = max - min;
    s = max == 0 ? 0 : d / max;

    if (max == min) {
        h = 0; // achromatic
    } else {
        if (max == rd) {
            h = (gd - bd) / d + (gd < bd ? 6 : 0);
        } else if (max == gd) {
            h = (bd - rd) / d + 2;
        } else if (max == bd) {
            h = (rd - gd) / d + 4;
        }
        h /= 6;
    }

    return {h,s,v};
}

struct ColorRGB hsvtoRgb(struct ColorHSV hsv)
{
	double r,g,b;

	double &h = hsv.hue;
	double &s = hsv.sat;
	double &v = hsv.val;

    int i = int(h * 6);
    double f = h * 6 - i;
    double p = v * (1 - s);
    double q = v * (1 - f * s);
    double t = v * (1 - (1 - f) * s);

    switch(i % 6){
        case 0: r = v, g = t, b = p; break;
        case 1: r = q, g = v, b = p; break;
        case 2: r = p, g = v, b = t; break;
        case 3: r = p, g = q, b = v; break;
        case 4: r = t, g = p, b = v; break;
        case 5: r = v, g = p, b = q; break;
    }

    return {r * 255, g * 255, b * 255};
}
