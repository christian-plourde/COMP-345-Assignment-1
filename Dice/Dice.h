#include "DiceFaces.h"
#include <string>

#ifndef DICE_H
#define DICE_H

class Dice
{
  //the dice class
  private:
    enum DiceFaces* rolled; //an array of size 6 holding the result of the dice roll


  public:
    Dice(); //default constructor
    ~Dice(); //destructor
    void roll(); //method to roll the dice
    enum DiceFaces* getResult(); //method to get the result of the dice roll
    std::string toString(); //method to display the result of the roll

};

#endif