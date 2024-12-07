#pragma once
#include <random>
#include "Deck.h"

using namespace std;

class Deck;
class CardFactory{
public:
    //----------Given functions
    //instance with file
    static CardFactory* getFactory(istream&) {
        if (!instance) {
            instance = new CardFactory();
        }
        return instance;
    }
    //instance without file
    static CardFactory* getFactory() {
        if (!instance) {
            instance = new CardFactory();
        }
        return instance;
    }
    
    Deck getDeck();
    //-----------added function
    ~CardFactory();
    static Card* createCard(const string& cardName);

    // Deleting the copy constructor to prevent copies
    CardFactory(const CardFactory& obj) = delete;

    //save game
    void save(ostream&) const;

    friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
    Deck cardDeck;
    static CardFactory* instance;
    // Given function: Private constructor to create the cards to make sure no one uses it outside of this one instance
    CardFactory();
    static const int numBlue = 20;
    static const int numChili = 18;
    static const int numStink = 16;
    static const int numGreen = 14;
    static const int numsoy = 12;
    static const int numblack = 10;
    static const int numRed = 8;
    static const int numgarden = 6;
    static const int total = numBlue+numChili+numStink+numGreen+numsoy+numblack+numRed+numgarden;
};
CardFactory* CardFactory::instance = nullptr;

















