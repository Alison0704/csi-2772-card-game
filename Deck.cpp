//
// Created by Alison Emilien on 2024-11-22.
//

#include "Deck.h"

#include <random>
#include <ostream>
#include <__random/random_device.h>

using namespace std;

Card* Deck::draw() {
    Card* topCard = nullptr;
    //check if empty
    if (!cardDeck.empty()) {
        topCard = cardDeck.back();
        cardDeck.pop_back();
    }
    return topCard;
}

bool Deck::isEmpty() const {
    if (cardDeck.empty()) {
        return true;
    }
    else {
        return false;
    }
}

void Deck::print(std::ostream& out) const {
    for (const auto i : cardDeck) {
        i->print(out);
    }
}
