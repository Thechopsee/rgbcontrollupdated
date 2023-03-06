#pragma once
#include "action.hh"
#include "enumerators.hh"
#include <cstdlib>
class Randomizer :Action
{
    colorType clr;
    int hodnota=0;
    int running=0;
    public:
    Randomizer(RGB * rgb,colorType type) :Action(rgb)
    {
        this->clr=type;
    }
    RGB * next()
    {
        if(running==10)
        {
            if(clr==red)
            {
                int value=rand() % 10;
                this->hodnota=rand()%245;
                if(value<5)
                {
                    this->clr=blue;
                    this->rgb->UpdateBLUE(hodnota); 
                }
                else
                {
                    this->clr=green;
                    this->rgb->UpdateGREEN(hodnota);
                }
            }
            else if (clr==blue)
            {
                int value=rand() % 10;
                this->hodnota=rand()%245;
                if(value<0)
                {
                    this->clr=red;
                    this->rgb->UpdateRED(hodnota);
                }
                else
                {
                    this->clr=green;
                    this->rgb->UpdateGREEN(hodnota);
                }
            }
            else
            {

                int value=rand() % 10;
                this->hodnota=rand()%245;
                if(value<0)
                {
                    this->clr=blue;
                    this->rgb->UpdateBLUE(hodnota); 
                }
                else
                {
                    this->clr=red;
                    this->rgb->UpdateRED(hodnota);
                }
            }
            running=0;
        }
        else
        {
            RGB* newColor;
            if(clr==red)
            {
                
                int i=this->rgb->getRED();  
                i++;
                newColor=new RGB(i,rgb->getGREEN(),rgb->getBLUE());
            }
            else if(clr==blue)
            {
                int i=this->rgb->getBLUE();
                i++;
                newColor=new RGB(rgb->getRED(),rgb->getGREEN(),i);
            }
            else
            {
                int i=this->rgb->getGREEN();
                i++;
                newColor=new RGB(rgb->getRED(),i,rgb->getBLUE());
            }
            delete this->rgb;
            this->rgb=newColor;
            running++;
        }
        return this->rgb;
    }
};
