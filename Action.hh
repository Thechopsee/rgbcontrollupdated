#pragma once
#include "rgb.hh"
class Action
{
    protected:
    RGB *rgb;
    public:
    Action(RGB *rgb)
    {
        this->rgb=rgb;
    }
    RGB * getRGB()
    {
        return this->rgb;
    }
    virtual RGB* next()
    {
        return new RGB(0,0,0);
    }
};
