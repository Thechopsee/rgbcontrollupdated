#pragma once
#include "rgb.hh"
#include "Action.hh"
#include "enumerators.hh"


  /*int r, g, b;
 
  // fade from blue to violet
  for (r = 0; r < 256; r++) { 
    analogWrite(REDPIN, r);
    delay(FADESPEED);
  } 
  // fade from violet to red
  for (b = 255; b > 0; b--) { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  } 
  // fade from red to yellow
  for (g = 0; g < 256; g++) { 
    analogWrite(GREENPIN, g);
    delay(FADESPEED);
  } 
  // fade from yellow to green
  for (r = 255; r > 0; r--) { 
    analogWrite(REDPIN, r);
    delay(FADESPEED);
  } 
  // fade from green to teal
  for (b = 0; b < 256; b++) { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  } 
  // fade from teal to blue
  for (g = 255; g > 0; g--) { 
    analogWrite(GREENPIN, g);
    delay(FADESPEED);
  } */
  

class Fader :Action
{
  int step;
  colorType ct=red;
  faderTypes ft=up;
  public:
  Fader(int step) :Action(new RGB(0,255,255))
  {
    this->step=step;
  }
  RGB * next()
  {
    int r=this->rgb->getRED();
    int g=this->rgb->getGREEN();
    int b=this->rgb->getBLUE();

    if(ft==up &&ct==red)
    {
      r++;
      if(r>=255)
      {
        ct=blue;
        ft=down;
      }
    }
    if(ft==down && ct==blue)
    {
      b--;
      if(b<=0)
      {
        ct=green;
        ft=up;
      }
    }
    if(ft==up && ct==green)
    {
      g++;
      if(g>=255)
      {
        ct=red;
        ft=down;
      }
    }
    if(ft==down && ct==red)
    {
      r--;
      if(r<=0)
      {
        ct=blue;
        ft=up;
      }
    }
    if(ft==up && ct==blue)
    {
      b++;
      if(b>=255)
      {
        ct=green;
        ft=down;
      }
    }
    if(ft==down && ct==green)
    {
      g--;
      if(g<=0)
      {
        ct=red;
        ft=up;
      }
    }
    delete this->rgb;
    this->rgb=new RGB(r,g,b);
    return this->rgb;
  }

  };
