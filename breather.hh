#pragma once 
#include "rgb.hh"
#include "Action.hh"

class Breather :Action
{
    int maxr,maxg,maxb;
    int step;
    int min=0;
    bool vydech=true;
    public:
    Breather(RGB* rgb,int step) :Action(rgb)
    {
        this->step=step;
        maxr=rgb->getRED();
        maxg=rgb->getGREEN();
        maxb=rgb->getBLUE();
    }
    
    RGB* next()
    {
        int r=this->rgb->getRED();
        int g=this->rgb->getGREEN();
        int b=this->rgb->getBLUE();
        if(vydech)
        {
            r-=step;
            g-=step;
            b-=step;
            if(r<0 && g<0 && b<0)
            {
                vydech=false;
            }
            if(r<=0)
            {
                r=0;
            }
            if(g<=0)
            {
                g=0;
            }
            if(b<=0)
            {
                b=0;
            }
        }
        else
        {
          
          
           // Serial.print(r);
            r+=step;
            g+=step;
            b+=step;
            if(r>=maxr && g>=maxg && b>=maxb)
            {
                vydech=true;
            }
            if(r>maxr)
            {
                r=maxr;
            }
            if(g>maxg)
            {
                g=maxg;
            }
            if(b>maxb)
            {
                b=maxb;
            }
            
        }
        delete this->rgb;
        this->rgb =new RGB(r,g,b);
        return this->rgb;
    }
};
