#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include  "CardFactory.h"

class Table {
    Player* p1; 
    Player* p2;
    DiscardPile* discardP;
    TradeArea* tradeArea;
    Deck* deck;
    CardFactory* cardFactory;
    int current_player{};
    
    public:
    // Constructeur
    Table(Player& player1, Player& player2, DiscardPile& d_pile, TradeArea& trade_area, Deck& Deck, CardFactory& cfactory){
        p1 = &player1;
        p2 = &player2;
        discardP = &d_pile;
        tradeArea = &trade_area;
        deck = &Deck;
        cardFactory = &cfactory;
    }

    //Constructor from file -- newly added
        Table(const ifstream & ifstream, CardFactory * factory);

    // Destructeur
        ~Table(){
            delete p1;
            delete p2;
            delete discardP;
            delete tradeArea;
            delete deck;
            delete cardFactory;
        }
        bool win(std::string&) const;
        void printHand(bool) const;
        friend std::ostream& operator<<(std::ostream&,  const Table&);
        void saveTable(ifstream&);
        void reloadPlayer(int);
        void reloadDeck();
        void reloadDiscardPile();
        void reloadTradeArea();
        Deck* getDeck();
        Player* getPlayer(int);
        DiscardPile* getDiscardPile() const;
        TradeArea* getTradeArea() const;
};

#endif