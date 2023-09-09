#ifndef COLOR_H
#define COLOR_H

#include "../Base/Base.h"

class Color
{
public:
    Color(f32 _r, f32 _g, f32 _b) :
        r(_r), g(_g), b(_b) {}
    f32 r, g, b;
};

#endif