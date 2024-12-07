#include <iostream>
#include <fstream>
#include <sstream>



#include "Main.h"

using namespace std;

int main(){
    fstream file;
    ifstream savedDeck("Deck.txt");
    ifstream savedTable("Table.txt");

    file.open("deck.txt", ios::in);
    file.open("table.txt", ios::in);

    static CardFactory* factory;
    static Deck deck;

    Table* table;
    TradeArea* tradeArea = nullptr;
    DiscardPile* discardPile = nullptr;

    bool flagSave = false;
    bool newGame = true;

    string buff;

    cout << "--------------------------------------" << endl;
    cout << "              NEW GAME                " << endl;
    cout << "--------------------------------------" << endl;

    while(newGame && deck.numCards() > 0) {
        string pName1;
        string pName2;
        if(tradeArea == nullptr || discardPile == nullptr) {
            tradeArea = table->getTradeArea();
            discardPile = table->getDiscardPile();
        }
        if(newGame) {
            if(savedDeck.good() && savedTable.good()) {
                Player p2;
                Player p1;
                cout << "--------------------------------------" << endl;
                cout << "---Do you want to reload the game?----" << endl;
                cout << "--------------------------------------" << endl;

                cin >> buff;
                if(buff == "yes" || buff == "YES" || buff == "Y" || buff == "y") {
                    //reinitialize
                    factory = CardFactory::getFactory(savedDeck);
                    deck = factory->getDeck();
                    table = new Table(savedTable,factory);
                    savedDeck.close();
                    savedTable.close();
                    p1.player_Name = table->getPlayer(1)->getName();
                    p2.player_Name = table->getPlayer(2)->getName();
                    pName1 = table->getPlayer(1)->getName();
                    pName2 = table->getPlayer(2)->getName();

                }
                else if(buff == "no" || buff == "NO" || buff == "N" || buff == "n") {
                    //files not needed
                    savedDeck.close();
                    savedTable.close();

                    //create a new table
                    factory = CardFactory::getFactory();
                    table = new Table(p1,p2,*discardPile,*tradeArea,deck,*factory);
                    deck = factory->getDeck();
                    cout << "Player 1's name: ";
                    cin >> p1.player_Name;
                    cout << "Player 2's name: ";
                    cin >> p2.player_Name;
                }
            }
            if(flagSave) {
                ofstream saveTable;
                saveTable.open("Table.txt");
                table->saveTable(savedTable);
                savedTable.close();

                ofstream saveDeck;
                saveDeck.open("deck.txt");
                factory->save(saveDeck);
                saveDeck.close();
                cout << "----------------------------------------" << endl;
                cout << "------------The game is saved-----------" << endl;
                cout << "----------------------------------------" << endl;
                return 0;
            }
            for(int i = 0; i < 1; i++) {
                Player* player = table->getPlayer(i);
                string playerName = player->getName();
                Card* drawCard = deck.draw();
                player->addCardToHand(drawCard);
                cout << "----------------------------------------" << endl;
                cout << "        "+playerName+"'s turn           " << endl;
                cout << "----                               -----" << endl;
                cout <<"THE CARD DRAWN:" << *drawCard << endl;
                cout << *table;
                if (tradeArea->numCards() != 0) {
                    string reply1;
                    cout << "-  Any cards from Trade Area?" << endl;
                    cin >> reply1;
                    if(reply1 == "yes" || reply1 == "YES" || reply1 == "y"|| reply1 == "Y") {
                        auto* card_name = new string();
                        vector<Card*> selectedCards;
                        while ((*card_name != "e"||*card_name != "E") && tradeArea->numCards() != 0) {
                            string reply2;
                            Card* bufferCard = nullptr;
                            cout << "Which card do you want to trade with?" << endl;
                            cout << "Enter Name of Card or E/e to exit" << endl;
                            cin >> reply2;
                            if (*card_name != "e"||*card_name != "E") {
                                bufferCard = TradeArea::trade(*card_name);
                                if (!bufferCard) cout << "The card name you entered is not valid." << endl;
                                else selectedCards.push_back(bufferCard);
                            }
                        }
                        for(auto& card: selectedCards) {
                            if (card->getName() == player->player_Chain.at(0)->getChainType() || card->getName() == player->player_Chain.at(1)->getChainType() )
                                cout << *card << " added to your chain." << endl;
                            else {
                                cout <<  *card << " did not matched one of your chain." << endl;
                                string reply3;
                                cout << "Create a new chain for it?" << endl;
                                cin >> reply3;
                                if(reply1 == "yes" || reply1 == "YES" || reply1 == "y"|| reply1 == "Y")
                                    if (player->createChain(card)==nullptr)
                                        *discardPile += card;
                            }
                        }
                    }
                }
                tradeArea->discardAll(discardPile);

                //player plays
                player->player_Hand->top();

                if (player->player_Hand->numCards() != 0) {
                    cout << "Hand: ";
                    player->printHand(cout,true);
                    cout <<"Do you want to play one more card? (y/n):";
                    cin >> buff;
                    if (buff=="y")
                        player->player_Hand->top();
                    //player plays again

                    cout << "Discard 1 card from hand? (y/n):";
                    cin >> buff;
                    if (buff=="y") player->~Player(); //discards hand
                }
                else
                    cout << endl;
                cout << "Empty hand, so will skip playing";

                cout << "----- Three cards added in Trade Area -----" << endl;
                for(int i=0; i<3; i++) *tradeArea += deck.draw();
                while (!discardPile->empty() && tradeArea->legal(discardPile->top())) {
                    Card* bufferCard = discardPile->pickUp();
                    cout << "Card " << *bufferCard << " popped from discard pile and added to trade area." << endl;
                    *tradeArea += bufferCard;
                }
                cout << "---------- Trade Area ----------\n" << *tradeArea << endl;
                if(tradeArea->numCards() != 0) tradeArea->trade(player);   // prompt player to make decision on each card in trade area
                // step 6:
                for(int i=0; i<2; i++) {
                    Card* bufferCard = deck.draw();
                    player->addCardToHand(bufferCard);     // draw card to hand
                    cout << "Draws a card from deck: "<< *bufferCard << endl;
                }
            }
            cout << "-----------------------------------------" << endl;
            cout << "-----------------Save Game?--------------" << endl;
            cout << "-----------------------------------------" << endl;
            cin >> buff;
            if (buff=="y") flagSave = true;
        }
        cout << "--------EMPTY DECK DETECTED-------------" << endl;
        cout << "The winner is ";
        if (table->win(pName1)) cout << pName1 << ", CONGRATS" << endl;
        else cout << pName2 << ", CONGRATS" << endl;
    }
    return 0;
};