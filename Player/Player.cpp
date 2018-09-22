#include <string>
#include "Player.h"
#include "../Lib/StringFunctions.h"

Player::Player(std::string name)
{
  this -> name = name; //set the name of the player
  this -> health = 10; //start the game with 10 health points
  this -> energy = 0; //start the game with 0 energy cubes
  this -> victoryPoints = 0; //start the game with no victory points
}

std::string Player::toString()
{
  std::string output = "";
  output += "Player Name: " + name;
  output += "\n\tHealth Points: " + libString::to_string(health);
  output += "\n\tVictory Points: " + libString::to_string(victoryPoints);
  output += "\n\tEnergy Cubes: " + libString::to_string(energy);
  return output;
}