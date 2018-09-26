#include <string>
#include "Characters.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
  private:
    static Characters* chosenCharacters; // an array holding all the characters that have been chosen so far so that no character is played by more than one player
    static int playerCount; //the number of players that are playing the game
    int playerNumber; //player 1, player 2, etc.
    std::string name; //the name of the player
    enum Characters character; //the character that the player is playing as
    int health; //the number of health points the player has
    int energy; //the number of energy cubes the player has
    int victoryPoints; //the number of victoryPoints the player has
    int zone; //the zone that the player is currently in
    void initializeChosenCharacters(); //a method to initialize the chosen characters when beginning the game

  public:
    Player(std::string); //a constructor that sets the name of the player
    ~Player(); //class destructor
    std::string getName(); //a method to get the name of the player
    void setName(std::string); //a method to set the name of the player
    int getHealth(); //a method to get the health of a player
    void setHealth(int); //a method to set the health of a player
    int getVictoryPoints(); //a method to get the number of victory points a player has
    void setVictoryPoints(int); //a method to set the number of victoryPoints a player has
    void setCharacter(); //set the character that the player is playing as
    std::string toString(); //returns a string containing information about the current status of the player
    enum Characters getCharacter(); //get the character that the player is playing as
    void setCharacter(enum Characters); //set the character that the player is playing as
    static int getPlayerCount(); //get the number of players in the game
    static void setPlayerCount(int); //set the number of players in the game
    void setPlayerNumber(int); //set the number of the player: player1, player2, etc.
    int getPlayerNumber(); //get the number of the player: player1,player 2, etc.
    static enum Characters* getChosenCharacters(); //gets a pointer to an array holding the chosen characters
    int getZone(); //return the zone that the player is currently in as an array index in graph. to get the name of the zone, call a method from graph
                   //with the returned integer
    void setZone(int); //set the zone that the player should now be in.
};

#endif