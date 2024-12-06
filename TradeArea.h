#ifndef TRADEAREA_H
#define TRADEAREA_H

#include "Card.h"
#include <list>

class CardFactory;

class TradeArea {
    private : 
        std::list<Card*> tradeArea; 
    public : 
        // Constructeur 
        TradeArea(std::istream, CardFactory*);

        // renvoie true si la carte peut être légalement ajouté à l’échange,
        bool legal( Card* );
       
        // ajoute une carte à l’échange
        TradeArea& operator+=(Card* card){
            if(this->legal(card)){ tradeArea.push_back(card);}
            else{
                if(tradeArea.size() < 3){tradeArea.push_back(card);}
                else{std::cout<< "La carte " << card->getName() << "ne peut pas etre ajoutée à la Trade Area." << std::endl;}
            }
            return *this;
        };
        
        //  supprime de l’échange une carte du correspondant nom
        Card* trade(std::string);
        // renvoie le nombre courant de cartes en échange
        int numCards();

        friend std::ostream& operator<<( std::ostream&, const TradeArea& );

};

#endif