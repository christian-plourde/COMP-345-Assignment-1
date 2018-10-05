#include <string>
#include <iostream>
#include "Player.h"

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
  dice = new Dice(); //the dice that the player will be using
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
  dice = new Dice(); //the dice that the player will be using
}

Player::~Player()
{
  //class destructor
  //make sure the dice object is deleted
  delete dice;
  dice = NULL;
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

Dice* Player::getDice()
{
  return dice;
}

void Player::rollDice()
{
  //a method to roll the dice that the player is using as per the rules of the game
  //on the first roll, which is mandatory, all dice must be rolled

  int rollCount = 0; //this will track the number of times that the dice have been rolled

  //the player will roll once regardless of the situation
  dice -> roll();
  rollCount++;
  std::cout << dice -> toString() << std::endl;

  //now that the dice has been rolled once, we need to ask the player if he would like to roll again

  bool badInput = true; //check to see it the input was either Y or N
  std::string answer;

  while(rollCount < 3)
  {
    std::cout << "Would you like to roll again? (Y/N): ";

    while(badInput)
    {
      //the user enters something
      try
      {
        std::cin >> answer;

        if(!(answer == "Y" || answer == "N"))
        {
          //if the answer was not Y or N, then we throw an exception
          throw answer;
        }

        //if the user entered Y or N, then badInput becomes false
        badInput = false;

      }

      catch(std::string s)
      {
        //let the user see what his mistake was and prompt him once again
        std::cout << "The answer " << s << " is not valid. Please enter either Y or N: ";
      }

    }

    //since we know that we are still in the allowed rolls count, there are two options.
    //if the user said N, then we simply break and that is it
    if(answer == "N")
    {
      //output the result of the dice and exit
      std::cout << name << ", your final roll result is: " << dice -> toString() << std::endl;
      break;
    }

    if(answer == "Y")
    {
      //if the user answered yes, then we need to ask him to roll selected dice
      dice -> rollSelectedDice();
      std::cout << name << ", the result of your roll was: " << dice -> toString() << std::endl;
      rollCount++; //add one to the number of times the dice was rolled
      badInput = true; //we want the user to be prompted again for the third reroll
    }
  }

}

void Player::move(Graph<std::string>* graph)
{
  //this method will allow the player to move from one location to another in the graph, as long as it is possible
  bool regionIsValid = false; //a check to see if the region that the player wants to move to is valid
  int region = 0; //the index of the region where the player wants to move (these match the index of the region in the array)
                  //in the graph

  do
  {
    //this do while loop will prompt the user to enter the name of the region where he would like to move
    std::cout << "Please enter the number corresponding to the region where you would like to move: " << std::endl;

    //now we should display each vertex in the graph in a list for the user to choose from
    /*
    The player should only be allowed to move (by choice) if he is in an outer region. If he is within manhattan, we will be moved
    automatically, therefore this method need only consider those cases where the player is in an outer region.
    */
    for(int i = 0; i < graph -> getVertexCount(); i++)
    {
      /*
      The player will be shown each node, but only the outer and master nodes are valid choices
      */
      std::cout << (i + 1) << ". " << graph -> getVertex(i) -> toString() << std::endl;
    }

    /*
    Now the player is prompted to enter a choice between 1 and the number of vertices in the graph
    There are two ways he can mess up his choice. He could either enter a number less than 1 or a number greater than the number of vertices in the graph
    Or he could mess up by entering a node that is not an outer node or the master node. If he chooses the master node, this is only valid as long as manhattan is
    not full. However, since we don't know if it is full because thate depends on the other players' positions, then we need not catch this exception here and place
    the responsibility of catching that exception on the calling method
    */

    std::cout << "Enter your choice here: ";

    try
    {
      std::cin >> region;

      if(region < 1 || region > graph -> getVertexCount())
      {
        //if the region is less than 1 or greater than the vertex count of the graph, then that number is invalid and the player should be prompted once again
        throw region;
      }

      if(graph -> getVertex(region - 1) -> getData() == "inner")
      {
        //if the type of the vertex the player has selected is an inner vertex, i.e. on the island of manhattan, then it is not a valid choice
        throw graph -> getVertex(region - 1);
      }

      if(graph -> getVertex(region - 1) -> getData() == "master")
      {
        //if a player wants to move to manhattan, then throw an exception that is handled by the calling method to check
        //if it is possible to move to manhattan or not.
        throw MasterNodeFullException();
      }

      //if we made it here then the selected node was valid
      this -> setZone(region - 1);
      regionIsValid = true;

    }

    catch (int e)
    {
      //if the value was less than 1 or larger than the vertex count, then display a message and then repeat the loop
      std::cout << "You cannot move to a node that does not exist! Please try again..." << std::endl;
      regionIsValid = false;
    }

    catch (GraphVertex<std::string>* g)
    {
      //if the vertex that the player wants to move to is an inner vertex, then we should send a message and repeat
      std::cout << "You cannot move to a node that is within the goal region! Please try again..." << std::endl;
      regionIsValid = false;
    }


  } while(!regionIsValid);

}

