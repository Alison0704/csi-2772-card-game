
#include "DiscardPile.h"

#include <Card.h>
#include <iostream>

using namespace std;

DiscardPile& DiscardPile::operator+=(Card* card) {
    discard_cards.push_back(card);
    return *this;
}

Card* DiscardPile::pickUp() {
    Card* topCard = nullptr;
    if(!discard_cards.empty()) {
        topCard = discard_cards.back();
        discard_cards.pop_back();
    }
    return topCard;
}

Card* DiscardPile::top() const {
    Card* topCard = nullptr;
    if(!discard_cards.empty()) {
        topCard = discard_cards.back();
    }
    return topCard;
}

void DiscardPile::print(ostream& out) const {
    for(const auto & discard_card : discard_cards) {
        discard_card->print(out);
    }
}

bool DiscardPile::empty() const {
    return discard_cards.empty();
}
