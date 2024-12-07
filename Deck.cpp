//
// Created by Alison Emilien on 2024-11-22.
//

#include "Deck.h"

#include <random>
#include <ostream>

using namespace std;

Deck::Deck() {}

//Read from file
Deck::Deck(istream& in, CardFactory*) {}

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


