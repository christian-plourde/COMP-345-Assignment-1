#include "Dice.h"
#include <iostream>
#include <cstddef>
#include <string>
#include "DiceFacesMethods.h"

Dice::Dice()
{
  //creates a new Dice object
  rolled = new enum DiceFaces[6];
  rolled[0] = Attack;
  rolled[1] = Attack;
  rolled[2] = Attack;
  rolled[3] = Attack;
  rolled[4] = Attack;
  rolled[5] = Attack;
}

Dice::~Dice()
{
  //destructor
  //delete all the values in the rolled array
  delete[] rolled;
}

void Dice::roll()
{
  //method to roll the dice.
  //we need to create a random number generator
  std::cout << "Rolling the dice..." << std::endl;

  //we need to generate 6 random numbers
  RandomNumberGenerator* r = new RandomNumberGenerator(); //my random number generator
  long* randomNumbers = r -> randomGen(6,0,6);

  for(int i = 0; i<6; i++)
  {
    enum DiceFaces face = Attack; //the face of the dice

    //set the face of the dice properly
    switch(randomNumbers[i])
    {
      case 0: face = Energy;
      break;
      case 1: face = Attack;
      break;
      case 2: face = Destruction;
      break;
      case 3: face = Heal;
      break;
      case 4: face = Celebrity;
      break;
      case 5: face = Ouch;
      break;
    }

    //assign the dice face to the position in the array of roll results
    rolled[i] = face;

  }

  //now that we no longer need the random number generator we should delete its resources and also the random number array
  delete r;
  r = NULL;
  delete[] randomNumbers;
  randomNumbers = NULL;

}

enum DiceFaces* Dice::getResult()
{
  //this method returns the result of the last roll
  return rolled;
}

std::string Dice::toString()
{
  std::string output = "";
  output += "[";
  for(int i = 0; i<6; i++)
  {

    output += DiceFacesMethods::DiceFaceToString(rolled[i]);

    if(i != 5)
    {
       output += ",";
    }

  }

  output += "]";
  return output;
}
