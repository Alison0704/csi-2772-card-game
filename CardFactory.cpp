#include "CardFactory.h"

using namespace std;

class Deck;
class CardFactory;

CardFactory::CardFactory() {
    for (int i = 0; i < numBlue; i++) {
        cards.push_back(new Blue);
    }
    for (int i = 0; i < numChili; i++) {
        cards.push_back(new Chili);
    }
    for (int i = 0; i < numStink; i++) {
        cards.push_back(new Stink);
    }
    for (int i = 0; i < numGreen; i++) {
        cards.push_back(new Green);
    }
    for (int i = 0; i < numsoy; i++) {
        cards.push_back(new soy);
    }
    for (int i = 0; i < numblack; i++) {
        cards.push_back(new black);
    }
    for (int i = 0; i < numRed; i++) {
        cards.push_back(new Red);
    }
    for (int i = 0; i < numgarden; i++) {
        cards.push_back(new garden);
    }

}
CardFactory::~CardFactory() {
    for (int i = 0; i < total; ++i) {
        delete cards[i];
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




