
// std libraries:
#include <list>
// project headers:
#include "CardFactory.h"
#include "DiscardPile.h"
#include "Player.h"
#include "TradeArea.h"


using namespace std;


TradeArea::TradeArea(istream& is, const CardFactory* factory) {
    string line;
    while(getline(is,line)) {
        auto delimiterPos = line.find("=");
        string type;
        string key = line.substr(0, delimiterPos);
        string value = line.substr(delimiterPos + 1);
        if(key=="trade"){
            istringstream buff(line);
            while(buff>>type) {
                if (type=="R") tradeArea.push_back(new Red());
                else if (type=="C") tradeArea.push_back(new Chili());
                else if (type=="G") tradeArea.push_back(new Green());
                else if (type=="B") tradeArea.push_back(new Blue());
                else if (type=="S") tradeArea.push_back(new Stink());
                else if (type=="g") tradeArea.push_back(new garden());
                else if (type=="s") tradeArea.push_back(new soy());
                else if (type=="b") tradeArea.push_back(new black());
                type.clear();
            }
        }
        break;
    } 
}
inline int TradeArea::numCards() const {return tradeArea.size();}
inline bool TradeArea::legal(const Card* c) const {
    for(auto const& card: tradeArea)
        if (card->getName()==c->getName()) return true;
    return false;
}
inline void TradeArea::discardAll(DiscardPile* pile) {
    for (auto& card: tradeArea) *pile += card;
    tradeArea.clear();
}

string operator*(const string & string);

void TradeArea::trade(Player* player) {
    string buff;
    int index = 0;
    for (Card* card: tradeArea) {
        bool erase = true;
        string pName = *(player->getName());
        cout << "Do you want to chain the card: "+card->getName()+" (y/n)? " << endl;
        cin >> buff;
        if (buff=="y") {
            if (!player->cardMatch(card)) {
                cout << "Do you want to create a new chain to match this card? (y/n): " << endl;
                cin >> buff;
                if (buff=="y") {
                    if (player->createChain(card)==nullptr) erase = false;
                    else cout << "(" << player->getName() << ") New " << card->getName() << " chain created." << endl;
                } else erase = false;
            } else cout << "(" << player->getName() << ") Card added to a chain." << endl;
            if (erase) {
                list<Card*>::iterator iter = tradeArea.begin();
                advance(iter,index);
                tradeArea.erase(iter);
                index--;
            }
        }
        index++;
    }
}

ostream& operator<< (ostream& os, const TradeArea& tradeArea) {
    if (tradeArea.tradeArea.size()==0) os << "Empty";
    else {
        for(auto& card: tradeArea.tradeArea)
            os << *card << " ";
    }
    return os;
}

void TradeArea::save(ostream& os){
    os << "trade= ";
    list<Card*>::iterator iter;
    for(iter = tradeArea.begin(); iter!=tradeArea.end(); iter++)
        os << **iter << " ";
}
