//
// Created by Alison Emilien on 2024-11-17.
//

#include "Card.h"

#include <iostream>
#include <string.h>

using namespace std;

//TODO lookout for errors
int main() {
    Card card(Chili);
    int coin = 4;
    cout << "You need " << card.getCardsPerCoin(coin) << " cards to get " << coin << " coins"<< endl;
    cout<< "Your bean cards: ";
    card.print(cout);
    card.print(cout);
    card.print(cout);
}