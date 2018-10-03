//this provides a test for the dice rolling facility
//IMPORTANT!!! The methods for rolling select dice are tested in detail in the player tests, since it is the player
//class that will be using it. This simply tests that we can roll 6 dice, with proper checking when entering data and
//that the distribution in uniform and that each face is equally likely to come up
#include <iostream>
#include "../../Dice/Dice.h"
#include <string>

int main()
{
  //create a new dice
  std::cout << "Creating a new dice object..." << std::endl;
  Dice* dice = new Dice();

  //the counts for each face that comes up
  int energyCount = 0;
  int attackCount = 0;
  int destructionCount = 0;
  int healCount = 0;
  int celebrityCount = 0;
  int ouchCount = 0;
  int otherCount = 0;

  for(int i = 0; i<100000; i++)
  {
    //roll the dice
    dice -> roll();
    //std::cout << dice -> toString() << std::endl;

    //for each dice, check its face and increment the appropriate counter
    for(int j = 0; j<6; j++)
    {
      if(dice -> getResult()[j] == Energy)
      {
        energyCount++;
        continue;
      }

      if(dice -> getResult()[j] == Attack)
      {
        attackCount++;
        continue;
      }

      if(dice -> getResult()[j] == Destruction)
      {
        destructionCount++;
        continue;
      }

      if(dice -> getResult()[j] == Heal)
      {
        healCount++;
        continue;
      }

      if(dice -> getResult()[j] == Celebrity)
      {
        celebrityCount++;
        continue;
      }

      if(dice -> getResult()[j] == Ouch)
      {
        ouchCount++;
        continue;
      }

      //if it was none of these faces and we did not continue the iterations, increment the othercount
      otherCount++;

    }
  }

  //now we should output the count of each face to see if it is uniformly distributed

  std::cout << "Energy Count: " << energyCount << std::endl;
  std::cout << "Attack Count: " << attackCount << std::endl;
  std::cout << "Destruction Count: " << destructionCount << std::endl;
  std::cout << "Heal Count: " << healCount << std::endl;
  std::cout << "Celebrity Count: " << celebrityCount << std::endl;
  std::cout << "Ouch Count: " << ouchCount << std::endl;

  delete dice;
  dice = NULL;
  return 0;

}