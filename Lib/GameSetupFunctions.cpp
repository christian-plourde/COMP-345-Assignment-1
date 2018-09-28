#include "GameSetupFunctions.h"

int GameSetupFunctions::getNumberOfPlayers()
{
  //set the number of players that will be playing the game, assuming the number entered is between 2 and 6
  std::cout << "Please enter the number of players: ";

  int numberOfPlayers = 0; //the number of players

  std::cin >> numberOfPlayers; //set the number of players from the command line

  //if the number of players is greater than 6 or less than 2 then this is not a valid number
  if(numberOfPlayers > 6 || numberOfPlayers < 2)
  {
    throw numberOfPlayers;
  }

  //otherwise, return the valid number of players
  return numberOfPlayers;
}

Player* GameSetupFunctions::initializePlayers(int numberOfPlayers)
{
  //a method to initialize all the player characters that will be playing the game
  //it returns a pointer to a player array that contains all the players

  Player* players = new Player[numberOfPlayers]; //an array to hold all the player objects

  std::cout << "Choose your characters!" << std::endl;
  std::string playerName; //the name of the new player that will be obtained from command line

  for(int i = 0; i<numberOfPlayers; i++)
  {
    //for each player, set the name of the player
    std::cout << "Player " << (i + 1) << " please enter your name: "; //let the player enter his name
    std::cin >> playerName; //get name input
    players[i].setName(playerName); //set the name of the player
    std::cout << "Player " << (i + 1) << " please choose your character: " << std::endl; //now the player must choose his character

    
  }

  return players;
}