//this file contains some functions that are used to set up a new game
#include <iostream>
#include "../Player/Player.h"
#include "StringFunctions.h"

#ifndef GAME_SETUP_FUNCTIONS_H
#define GAME_SETUP_FUNCTIONS_H

namespace GameSetupFunctions
{
  int getNumberOfPlayers(); //a method to get the number of players that will be playing the game
  Player* initializePlayers(int); //a method to initialize a player character, accepts an integer containing the number of players
}

#endif