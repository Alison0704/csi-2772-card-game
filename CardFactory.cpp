#include "CardFactory.h"
#include "Deck.h"
using namespace std;

class Deck;
class CardFactory;

CardFactory::CardFactory() {
    auto deck = Deck();
    for (int i = 0; i < numBlue; i++) {
        cardDeck.push_back(new Blue);
    }
    for (int i = 0; i < numChili; i++) {
        cardDeck.push_back(new Chili);
    }
    for (int i = 0; i < numStink; i++) {
        cardDeck.push_back(new Stink);
    }
    for (int i = 0; i < numGreen; i++) {
        cardDeck.push_back(new Green);
    }
    for (int i = 0; i < numsoy; i++) {
        cardDeck.push_back(new soy);
    }
    for (int i = 0; i < numblack; i++) {
        cardDeck.push_back(new black);
    }
    for (int i = 0; i < numRed; i++) {
        cardDeck.push_back(new Red);
    }
    for (int i = 0; i < numgarden; i++) {
        cardDeck.push_back(new garden);
    }
    //shuffle on creation
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    shuffle(cardDeck.begin(), cardDeck.end(), default_random_engine(seed));

}
CardFactory::~CardFactory() {
    for (int i = 0; i < total; ++i) {
        delete cardDeck[i];
    }
}

Card* CardFactory::createCard(const std::string& cardName) {
    if (cardName == "Blue") return new Blue();
    if (cardName == "Black") return new black();
    if (cardName == "Chili") return new Chili();
    if (cardName == "Stink") return new Stink();
    if (cardName == "Green") return new Green();
    if (cardName == "Soy") return new soy();
    if (cardName == "Red") return new Red();
    if (cardName == "Garden") return new garden();
    return nullptr; // Invalid card name
}

Deck CardFactory::getDeck(){
    return cardDeck;
}

std::ostream& operator<<(ostream& os, const Card& card) {
    os << card.getName() << endl;
    return os;
}

void CardFactory::save(ostream & os) const {
    for(Card* card : cardDeck) os << *card << endl;
}




