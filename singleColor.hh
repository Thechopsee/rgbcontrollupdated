#include "rgb.hh"
#include "action.hh"
class singleColor :Action
{   
    private:
    RGB *rgb;
    private:
    singleColor(RGB *rgb)
    {
        this->rgb=rgb;
    }
    RGB* next()
    {
        return this->rgb;
    }
};