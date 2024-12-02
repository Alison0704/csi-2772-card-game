#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

using namespace std;

class Deck : public vector<Card*>{
public:
    //constructor
    Deck(istream& in, const class CardFactory* factory);
    Deck(CardFactory* factory);
    Deck();

    //given functions
    Card* draw();
    friend std::ostream& operator<<(std::ostream& os, const Deck& deck);

    //added functions
    bool isEmpty() const;
    void print(std::ostream&) const;

private:
    vector cardDeck;
};


#endif









