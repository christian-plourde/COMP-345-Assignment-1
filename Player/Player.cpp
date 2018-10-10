#include <string>
#include <iostream>
#include "Player.h"

//declaring the static variables
int Player::playerCount = 0;
enum Characters* Player::chosenCharacters = new Characters[6];
SinglyLinkedList<Player*>* Player::players = new SinglyLinkedList<Player*>();

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
  cards = new SinglyLinkedList<Card>(); //this will hold the cards the player has in his possession
  node<Player*>* newNode = new node<Player*>();
  newNode -> setData(this);
  players -> add(newNode);
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
  cards = new SinglyLinkedList<Card>(); //this will hold the cards the player has in his possession
  node<Player*>* newNode = new node<Player*>();
  newNode -> setData(this);
  players -> add(newNode);
}

Player::~Player()
{
  //class destructor
  //make sure the dice object is deleted
  delete dice;
  dice = NULL;
  delete cards;
  cards = NULL;
  delete[] chosenCharacters;
  chosenCharacters = NULL;
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

  else if(health > 10)
  {
    //the maximum health a player can have is ten.
    //therefore if a number greater than 10 is entered, set the health to the maximum value
    this -> health = 10;
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

void Player::move()
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
    for(int i = 0; i < MapLoader::getMap() -> getVertexCount(); i++)
    {
      /*
      The player will be shown each node, but only the outer and master nodes are valid choices
      */
      std::cout << (i + 1) << ". " << MapLoader::getMap() -> getVertex(i) -> toString() << std::endl;
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

      if(region < 1 || region > MapLoader::getMap() -> getVertexCount())
      {
        //if the region is less than 1 or greater than the vertex count of the graph, then that number is invalid and the player should be prompted once again
        throw region;
      }

      if(MapLoader::getMap() -> getVertex(region - 1) -> getData() == "inner")
      {
        //if the type of the vertex the player has selected is an inner vertex, i.e. on the island of manhattan, then it is not a valid choice
        throw MapLoader::getMap() -> getVertex(region - 1);
      }

      if(MapLoader::getMap() -> getVertex(region - 1) -> getData() == "master")
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

SinglyLinkedList<Card>* Player::getCards()
{
  return cards;
}

void Player::resolveDice()
{
  /*method to resolve the dice that the player has rolled
  there are six possible outcomes from the dice
  we will deal with each one one by one
  */

  //for the energy cubes, we simply need to count the number of energy cubes that the player has in his dice
  //rolled array and for each one, we increment his energycube count by one
  int i = 0;
  int ouchCount = 0; //we need to count the number of these, since the effect depends on the number of them
                     //that was rolled.
  int destructionCount = 0; //same as before, we need to know how many the player has rolled before we do
                            //anything
  int celebrityCount = 0; //same as before, we need to know how many the player has rolled before doing anything

  for(i = 0; i < 6; i++)
  {
    if(dice -> getResult()[i] == Energy)
    {
      energy++;
    }

    //for the heal cubes, you gain one health for each heart rolled, unless you are in manhattan and the max is 10
    if(dice -> getResult()[i] == Heal && health < 10 && (MapLoader::getMap() -> getVertex(zone) -> getData() != "master" && MapLoader::getMap() -> getVertex(zone) -> getData() != "inner"))
    {
      health++;
    }

    //for the attack cubes, the effect depends on where the player is
    if(dice -> getResult()[i] == Attack && MapLoader::getMap() -> getVertex(zone) -> getData() == "inner")
    {
      //if the player is within manhattan, then each player outside of manhattan loses a health point for each attack rolled
      //we need to go through each node in our player list and check if the player is outside manhattan
      node<Player*>* currentNode = players -> getHead();

      while(currentNode != NULL)
      {
        //if the other player is in an outer zone, then he gets hit for one point
        if(MapLoader::getMap() -> getVertex(currentNode -> getData() -> getZone()) -> getData() == "outer")
        {
          //we need to set the health of the player to one less than his current health
          currentNode -> getData() -> setHealth(currentNode -> getData() -> getHealth() - 1);
        }
        //then move to the next node in the list
        currentNode = currentNode -> getNext();
      }

    }

    //for the attack cubes, the effect depends on where the player is
    //now we do the opposite from before
    if(dice -> getResult()[i] == Attack && MapLoader::getMap() -> getVertex(zone) -> getData() == "outer")
    {
      //if the player is outside manhattan, then each player inside of manhattan loses a health point for each attack rolled
      //we need to go through each node in our player list and check if the player is inside manhattan
      node<Player*>* currentNode = players -> getHead();

      while(currentNode != NULL)
      {
        //if the other player is in an inner zone, then he gets hit for one point
        if(MapLoader::getMap() -> getVertex(currentNode -> getData() -> getZone()) -> getData() == "inner")
        {
          //we need to set the health of the player to one less than his current health
          currentNode -> getData() -> setHealth(currentNode -> getData() -> getHealth() - 1);
        }
        //then move to the next node in the list
        currentNode = currentNode -> getNext();
      }

    }

    //for the building destruction cubes, we need to know how many the player rolled before doing anything
    if(dice -> getResult()[i] == Destruction)
    {
      destructionCount++;
    }

    //for the ouch cubes, we need to know which tiles are in the player's borough, and also how many ouches he rolled
    //therefore in this for loop, we will simply count the number of ouch cubes
    if(dice -> getResult()[i] == Ouch)
    {
      ouchCount++;
    }

    //for the celebrity cubes, we also need to know how many the player rolled before doing anything, since
    //if he got 3 or more, then he gets a special card and otherwise nothing happens
    if(dice -> getResult()[i] == Celebrity)
    {
      celebrityCount++;
    }

  }

  //now we need to apply the effect of the cubes that we counted, i.e. the ouch, destruction and celebrity cubes


}

//a method for the player to purchase cards with his energy cubes
void Player::buyCards(CardDeck* deck)
{

  //for the player to buy cards, since the deck is not static, we need to pass it the cardDeck in the method
  //when the player wants to buy cards, the top three cards in the deck are revealed.
  //since we know that three cards will be revealed, assuming there are three cards to reveal, then
  //we should display those three cards

  //this variable will hold the response that the player has given
  std::string response = "";
  int cardSelected = 0;
  bool validResponse = true;

  do
  {

    //we ask the user once what he would like to do
    try
    {
      //request input from the user..
      std::cout << this -> getName() << ", would you like to purchase some cards? Please enter (Y/N): ";
      std::cin >> response; //store the response

      //if the user said yes or no, then we should exit the loop and allow him to buy cards or exit
      if(response == "Y" || response == "N")
      {
        validResponse = true;
      }

      //otherwise the response was invalid and we should catch the exception
      else
      {
        validResponse = false;
        throw response;
      }
    }

    catch(std::string e)
    {
      //show an error message and try again
      std::cout << "The response: \'" << response << "\' is invalid. Please try again..." << std::endl;
    }


  } while(!validResponse);

  //if we have made it here, this means that the response was valid
  //if the player said no, then we simply return since he does not want to buy cards

  if(response == "N")
  {
     std::cout << "Cancelling..." << std::endl;
     return;
  }


  else
  {
    //this is the case where the player said yes to purchasing cards
    bool newCardsRequested = false; //this will keep track of whether or not the player has requested new cards
    bool moreCardsDesired = false; //this will keep track of whether or not the player would like
                                   //to purchase more cards
    SinglyLinkedList<Card>* topThree = deck -> getDeck(); //the list of the cards that are still not discarded
    node<Card>* currentCard = topThree -> getHead(); //the head of the list
    //we need to check if there are even three cards available
    int count = topThree -> getCount();

    do
    {
      //first make sure that both the options are set to false so that we don't go into an infinite loop
      moreCardsDesired = false;
      newCardsRequested = false;

      //we perform this operation so long as the player has requested new cards
      std::cout << "Select a card from the following: " << std::endl;

      //we need to display the top three cards from the deck for him to purchase
      topThree = deck -> getDeck();
      currentCard = topThree -> getHead();
      count = topThree -> getCount();

      if(count >= 3)
      {
        //if there are at least three cards, then we should display three cards
        for(int i = 0; i < 3; i++)
        {
          std::cout << (i+1) << ". ";
          currentCard -> getData().Print();
          currentCard = currentCard -> getNext();
        }

        std::cout << "4. Reveal new cards (2 energy required)" << std::endl;
      }

      else if(count > 0)
      {
        //if there are still cards in the deck but less than 3, then we only display the ones that are available
        int i = 0;
        for(i = 0; i < count; i++)
        {
          std::cout << (i+1) << ". ";
          currentCard -> getData().Print();
          currentCard = currentCard -> getNext();
        }

        std::cout << (i+1) << ". Reveal new cards (2 energy required)" << std::endl;
      }

      else
      {
        //otherwise, if there are no cards in the deck, then obviously the player cannot purchase cards so we tell
        //him and we return
        std::cout << "The deck is empty!" << std::endl;
        return;
      }

      //now that we have shown the top three cards, we need to ask the user to input a number between 1 and 3
      //we have two cases to consider: either we have three or more cards, or we have less than 3

      //first case where we have at least three cards
      if(count >= 3)
      {
        //we need to ask the user for a number between 1 and 4 and we keep doing so until he enters something valid
        //the fourth option is for him to reveal three new cards
        do
        {
          try
          {
            //the user will enter a number between 1 and 3, or try again
            std::cout << "Please enter a number between 1 and 4: ";
            std::cin >> cardSelected;

            //if the number is less than 1 or greater than 3, then that is an invalid choice and we should start over
            if(cardSelected < 1 || cardSelected > 3)
              throw cardSelected;

            //otherwise, the response was valid and we can move on
            validResponse = true;
          }

          catch(int e)
          {
            //if the card was not 4
            if(cardSelected != 4)
            {
              std::cout << "The number \'" << cardSelected << "\' is invalid." << std::endl;
              validResponse = false;
            }

            else
            {
              //if the player selected 4, then it is a valid response
              validResponse = true;
            }

          }

        } while(!validResponse);

        //if the response was valid, then we are here.
        //Either the player decided to reveal new cards, in which case the choice is 4

        if(cardSelected == 4)
        {
          //in this case, we need to display new cards
          //first we should check if the player has enough energy to do this

          try
          {
            if(energy < 2)
            {
              throw NotEnoughEnergyException();
            }

            //if he does have enough energy, then we need to place the first three cards to the back of the deck,
            //and then restart the process by setting the newCardsRequested parameter to true and calling a new iteration

            //the process needs to be done three times

            for(int i = 0; i < 3; i++)
            {
              node<Card> *card = topThree -> getHead();
              topThree -> remove(card); //remove the card from the deck
              topThree -> addLast(card); //add it back to the end
            }

            //now that the cards have been moved, set newCardsRequested to true and continue
            //we also need to decrease the player's energy by 2
            energy -= 2;
            newCardsRequested = true;
            continue;

          }

          catch(NotEnoughEnergyException e)
          {
            //display the error message
            std::cout << e.what();
            //if the player requested new cards, then he was not happy with the initial cards, and so if he doesn't
            //have enough to reveal new, then we simply return
            return;
          }

        }

        //in the other case, where the player wants to purchase one of the selected cards
        //We now need to retrieve the card that the player requested
        //and add it to his deck, at the same time removing it from the deck
        //begin at the head
        else
        {
          currentCard = topThree -> getHead();
          int j = 1;

          while(j < cardSelected)
          {
            //while we are still not at the card he wanted, we move down the list until we find it
            j++;
            currentCard = currentCard -> getNext();
          }


          //now that the current card pointer points to the card that he wants, add it to his hand
          Card toAdd = currentCard -> getData();
          node<Card> cardToAdd;
          cardToAdd.setData(toAdd);

          //we need to check if the player has enough energy to actually purchase the card
          try
          {
            if(energy >= toAdd.getCost())
            {
              //if the energy was greater than the cost of the carde, then the player can purchase it
              cards -> add(&cardToAdd); //add the card to the player's cards
              topThree -> remove(currentCard); //remove it from the cards available
            }

            else
            {
              throw NotEnoughEnergyException();
            }
          }

          catch(NotEnoughEnergyException e)
          {
            std::cout << e.what() << std::endl;
          }

          //regardless of whether or not the card was purchased, we need to ask the player if he wants to purchase another card
          //we will once again need to check the validity of his response
          validResponse = false;

          do
          {
            try
            {
              //we ask the user if he would like to purchase another card
              std::cout << "Would you like to purchase more cards? Please enter (Y/N): ";
              std::cin >> response;

              if(response == "Y" || response == "N")
              {
                //if the repsonse was either Y or N then that is a valid response
                validResponse = true;
              }

              else
              {
                //otherwise we throw the response
                validResponse = false;
                throw response;
              }
            }

            catch(std::string e)
            {
              std::cout << "The response \'" << response << "\' is invalid. Please try again..." << std::endl;
            }

          } while(!validResponse);

          //now that we have a valid response:

          //if the user said yes, then set moreCardsDesired to true and repeat
          //otherwise we simply return

          if(response == "Y")
          {
            moreCardsDesired = true;
            continue;
          }

        }

      }

      //now for the case where we have less than three cards

    } while(newCardsRequested || moreCardsDesired); //repeat as long as he wants more cards, or he wants to purchase
                                                    //more from the three already revealed

  }

}


