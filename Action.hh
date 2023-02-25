#include "rgb.hh"
class Action
{
    public:
    virtual RGB* next()
    {
        return new RGB(0,0,0);
    }
};