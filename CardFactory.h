#include <random>

#include "Deck.h"
#include "Card.h"

using namespace std;

class CardFactory {
public:
    static CardFactory* getFactory() {
        if (!instance) {
            instance = new CardFactory();
        }
        return instance;
    }
    vector<unique_ptr<Card>> getDeck() {
        vector<unique_ptr<Card>> deck = cards;
        shuffle(deck.begin(), deck.end(), default_random_engine());
        return deck;
    }

    //Avoiding duplicates
    CardFactory(const CardFactory&) = delete;
    CardFactory& operator=(const CardFactory&) = delete;
private:
    vector<Card> cards;
    static CardFactory* instance;
    //Naming all the amount of bean cards in the deck
    const int   numBlue = 20,
                numChili = 18,
                numStink = 16,
                numGreen = 14,
                numSoy = 12,
                numBlack = 10,
                numRed = 8,
                numGarden = 6;

    // Private constructor to create the cards
    CardFactory() {
        for(int i = 0; i < numBlue; i++) {
            cards.emplace_back(new Card->Blue);
    }
};
















