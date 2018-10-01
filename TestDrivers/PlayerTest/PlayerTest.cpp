#include "../../Player/Player.h"
#include <iostream>
#include "../../Dice/Dice.h"

int main()
{
  std::cout << "This is a test of the player class." << std::endl;

  Player* player = new Player();
  std::cout << player -> toString() << std::endl;
  player -> rollDice();
}