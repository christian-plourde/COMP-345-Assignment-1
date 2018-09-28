#include "GameSetupFunctions.h"
#include "../Player/Player.h"
#include "StringFunctions.h"

void GameSetupFunctions::setNumberOfPlayers()
{
  //set the number of players that will be playing the game, assuming the number entered is between 2 and 6
  std::cout << "Please enter the number of players:";

  int numberOfPlayers = 0; //the number of players

  std::cin >> numberOfPlayers; //set the number of players from the command line

  //now try to set the number of players
  try
  {
    Player::setPlayerCount(numberOfPlayers);
  }

  catch(int e)
  {
    //if an exception is thrown it will throw the number of players

    if(numberOfPlayers > 6)
    {
      std::cout << "The game is for 2-6 players. " + libString::to_string(numberOfPlayers) + " is too many players!" << std::endl;
    }

    if(numberOfPlayers < 2)
    {
      std::cout << "The game is for 2-6 players. " + libString::to_string(numberOfPlayers) + " is too few players!" << std::endl;
    }

  }

}