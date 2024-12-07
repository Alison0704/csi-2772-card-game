#include "Table.h"

bool Table::win(std::string& player_Name) const {
    bool win = false;
    if(deck->size() == 0){
       if(p1->getNumCoins() > p2->getNumCoins()){
           player_Name = p1->getName();
       }
       else if(p1 ->getNumCoins() < p2->getNumCoins()){
           player_Name = p2->getName();
       }
       else{
           player_Name = "It's a tie";
       }
       win = true;
    }
    return win;
}
void Table::printHand(bool in) const {
    Player* curr_player = current_player == 0 ? p1 : p2; // id = 0 corresponds to player 1
    curr_player -> printHand(std::cout, in);
}
Player* Table::getPlayer(int id){
    current_player = id;
    if (id==0) return p1;
    else return p2;
}
// Deck* Table::getDeck(){
//     if(deck == nullptr){deck = cardFactory->getDeck();}
//     return deck;
// }
DiscardPile* Table::getDiscardPile() const {return discardP;}
TradeArea* Table::getTradeArea() const {return tradeArea;}
std::ostream& operator<<( std::ostream& output,  const Table&  tb){
    output << "Player 1 : " << std::endl << std::endl << *(tb.p1) << std::endl;
    output << "Player 2 : " << std::endl << std::endl << *(tb.p2) << std::endl;
    output << "Discard Pile : "  << *tb.discardP << std::endl << std::endl;
    output << "Trade Area : "  << *tb.tradeArea << std::endl;
    output << std::endl;
    return output;
};