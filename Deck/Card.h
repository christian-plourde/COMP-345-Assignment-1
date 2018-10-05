//this contains a class that contains information about a card in the game
#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

enum HowTo { Empty, Goal, Keep, Discard };

class Card {
	private:
		string name;
		int cost;
		HowTo howTo;
		string effect;

	public:
		Card();
		Card(string, int, HowTo, string);
		~Card();
		
		void setName(string);
		void setCost(int);
		void setHowTo(HowTo);
		void setEffect(string);

		string getName() const;
		int getCost() const;
		HowTo getHowTo() const;
		string getEffect() const;

		void Print();
};

#endif