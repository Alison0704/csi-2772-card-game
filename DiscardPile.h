#ifndef DISCARDPILE_H
#define DISCARDPILE_H
#include <vector>

class CardFactory;
class Card;
using namespace std;

class DiscardPile : public vector<Card*>{
    public:
        //constructor
        DiscardPile(istream&, const CardFactory*);
        DiscardPile& operator+=(Card*);
        Card* pickUp();
        Card* top() const;
        bool empty() const;
        void print(std::ostream&) const;
        friend ostream& operator<<(ostream& os, const DiscardPile& DiscardPile);
    private:
        vector<Card*> discard_cards;
};

#endif
