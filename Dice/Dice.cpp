#include "Dice.h"
#include <iostream>
#include <stdlib.h> //for the random numbers generation
#include <time.h> //for the random generator to get a random seed
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

void Dice::roll()
{
  //method to roll the dice.
  //we need to create a random number generator
  std::cout << "Rolling the dice..." << std::endl;
  int randomNumber; //the random number we will use to set the dice rolls
  srand(time(NULL)); //set the seed of the random number generator to a random seed

  for(int i = 0; i<6; i++)
  {
    //we need to generate 6 random numbers
    randomNumber = rand()%6;
    enum DiceFaces face; //the face of the dice

    //set the face of the dice properly
    switch(randomNumber)
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
