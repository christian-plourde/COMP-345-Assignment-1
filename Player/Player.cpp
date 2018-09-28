#include <string>
#include "Player.h"
#include "../Lib/StringFunctions.h"
#include "CharacterMethods.h"

//declaring the static variables
int Player::playerCount = 0;
enum Characters* Player::chosenCharacters = new Characters[6];

//default constructor for use in player arrays
Player::Player()
{
  //if the playerCount is 0 then initialize the array of chosenCharacters
  if(playerCount == 0)
  {
    Player::initializeChosenCharacters();
  }

  this -> name = "Player"; //set the name of the player
  this -> health = 10; //start the game with 10 health points
  this -> energy = 0; //start the game with 0 energy cubes
  this -> victoryPoints = 0; //start the game with no victory points
  playerCount++; //increment the number of players in the game
  playerNumber = playerCount; //set the player number to the current player count
  //we need to set the start zone of the player
  zone = playerNumber; //arbitrarily set it to the playerNumber, it will be changed after anyways
}

Player::Player(std::string name)
{
  //if the playerCount is 0 then initialize the array of chosenCharacters
  if(playerCount == 0)
  {
    Player::initializeChosenCharacters();
  }

  this -> name = name; //set the name of the player
  this -> health = 10; //start the game with 10 health points
  this -> energy = 0; //start the game with 0 energy cubes
  this -> victoryPoints = 0; //start the game with no victory points
  playerCount++; //increment the number of players in the game
  playerNumber = playerCount; //set the player number to the current player count
  //we need to set the start zone of the player
  zone = playerNumber; //arbitrarily set it to the playerNumber, it will be changed after anyways
}

Player::~Player()
{
  //class destructor

}

enum Characters Player::getCharacter()
{
  return character;
}

void Player::setCharacter(enum Characters character)
{
  if(character >= 0 && character < 6)
  {
    //we need to check if the character was already chosen
    if(playerCount == 1)
    {
      //if there is only one player, then this means that the player is free to choose any character he likes
      this -> character = character;
      //add the chosen character to the list of chosen characters
      chosenCharacters[playerCount-1] = character;
      return;
    }

    //otherwise if there is more than one player, we need to check if the character has already been chosen by another player
    for(int i = 0; i<6; i++)
    {
      //if the value at the index in the chosencharacters array matches the character we want to set we should return
      if(chosenCharacters[i] == character)
      {
        return;
      }
    }

    //if we got through the for loop that means the character has not been chosen yet
    this -> character = character;
    chosenCharacters[playerCount-1] = character;

  }
}

std::string Player::toString()
{
  std::string output = "";
  output += "Player Name: " + name;
  output += "\n\tPlayer: " + libString::to_string(playerNumber);
  output += "\n\tChosen Character: " + CharacterMethods::characterToString(this -> character);
  output += "\n\tHealth Points: " + libString::to_string(health);
  output += "\n\tVictory Points: " + libString::to_string(victoryPoints);
  output += "\n\tEnergy Cubes: " + libString::to_string(energy);
  output += "\n\tZone: " + libString::to_string(zone);
  return output;
}

std::string Player::getName()
{
  return name;
}

void Player::setName(std::string name)
{
  this -> name = name;
}

int Player::getHealth()
{
  return health;
}

void Player::setHealth(int health)
{
  //make sure that the value is greater than or equal to zero
  if(health < 0)
  {
    this -> health = 0;
  }

  else
  {
    this -> health = health;
  }
}

int Player::getVictoryPoints()
{
  return victoryPoints;
}

void Player::setVictoryPoints(int victoryPoints)
{
  if(victoryPoints < 0)
  {
    this -> victoryPoints = 0;
  }

  else
  {
    this -> victoryPoints = victoryPoints;
  }

}

int Player::getPlayerCount()
{
  return playerCount;
}

void Player::setPlayerCount(int players)
{
  if(players >= 2 && players <= 6)
  {
    playerCount = players;
  }
}

int Player::getPlayerNumber()
{
  return playerNumber;
}

void Player::setPlayerNumber(int number)
{
  //if the number is between 0 and 6 then it is valid
  if(number >= 0 && number <= 6)
  {
    playerNumber = number;
  }
}

enum Characters* Player::getChosenCharacters()
{
  return chosenCharacters;
}

void Player::initializeChosenCharacters()
{
  //this method is called once, when the player count is zero in the constructor
  //it exists to initialize everything in the chosen characters array to something that could not be picked
  for(int i = 0; i<6; i++)
  {
    chosenCharacters[i] = None;
  }
}

int Player::getZone()
{
  return zone;
}

void Player::setZone(int newZone)
{
  zone = newZone; //check for if the zone number is compatible must be checked by the calling method
}

