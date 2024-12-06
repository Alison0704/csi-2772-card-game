#include <vector>
#ifndef DECK_H
#define DECK_H
#include "Card.h"

class CardFactory;
using namespace std;

class Deck : public vector<Card*>{
public:
    //constructor
    Deck(istream &in, CardFactory*);


    //given functions
    Card* draw();
    friend std::ostream& operator<<(std::ostream& os, const Deck& deck) {
        for (auto i : deck) {
            os << i << " ";
        }
        return os;
    }

    //added functions
    bool isEmpty() const;
    void print(std::ostream&) const;
    int numCards() const {
        return cardDeck.size();
    }

private:
    vector cardDeck;
};

#endif










