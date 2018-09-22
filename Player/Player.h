#include <string>
#include "Characters.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
  private:
    std::string name; //the name of the player
    enum Characters character; //the character that the player is playing as
    int health; //the number of health points the player has
    int energy; //the number of energy cubes the player has
    int victoryPoints; //the number of victoryPoints the player has

  public:
    Player(std::string); //a constructor that sets the name of the player
    std::string getName(); //a method to get the name of the player
    void setName(std::string); //a method to set the name of the player
    int getHealth(); //a method to get the health of a player
    void setHealth(int); //a method to set the health of a player
    int getVictoryPoints(); //a method to get the number of victory points a player has
    void setVictoryPoints(); //a method to set the number of victoryPoints a player has
    std::string toString(); //returns a string containing information about the current status of the player
};

#endif