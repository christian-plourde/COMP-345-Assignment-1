#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

enum HowTo { Empty, Goal, Keep, Discard };

class Card {
	private:
		int id;
		string name;
		int cost;
		HowTo howTo;
		string effect;

	public:
		Card();
		Card(int, string, int, HowTo, string);
		~Card();
		
		void setID(int);
		void setName(string);
		void setCost(int);
		void setHowTo(HowTo);
		void setEffect(string);

		string getName() const;
		int getCost() const;
		HowTo getHowTo() const;
		string getEffect() const;
		int getID() const;

		void Print();
};

#endif