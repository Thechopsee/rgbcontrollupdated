#pragma once 
#include "rgb.hh"
#include "Action.hh"

class Breather :Action
{
    private:
    int maxr,maxg,maxb;
    int step;
    int min=0;
    bool vydech=true;
    
    public:
    Breather(RGB* rgb,int step);
    RGB* next();
   
};
