#include "../../Player/Player.h"
#include <iostream>
#include "../../Dice/Dice.h"

int main()
{
  std::cout << "This is a test of the player class." << std::endl;

  Dice* dice = new Dice();
  dice -> roll();
  std::cout << dice -> toString() << std::endl;
  dice -> rollSelectedDice();
  std::cout << dice -> toString() << std::endl;
  return 0;
}