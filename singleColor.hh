#pragma once
#include "rgb.hh"
#include "action.hh"
class singleColor :Action
{   

    public:
    singleColor(RGB *rgb) :Action(rgb)
    {
        return;
    }
    RGB* next()
    {
        return this->rgb;
    }
};
