#ifndef PLAYER_H
#define PLAYER_H

#include "Chain.h"
#include "Hand.h"
#include <cstdlib>

class Player{
    public : 
        const int num_chains_max;
        const int num_chains_allowed;
        std::string player_Name;
        Hand* player_Hand;
        std::vector<Chain_b*> player_Chain;
        int player_Coins{};
        // Construire un nouvel objet Player
        Player(std::string& name): num_chains_max(3), num_chains_allowed(2){
            player_Name  = name;
            player_Coins = 0;
            player_Hand  = new Hand();
        };
        //Construire un nouvel objet Player avec un fichier
        Player(): num_chains_max(3), num_chains_allowed(2) {
            player_Coins = 0;
            player_Hand = new Hand();
        }
        std::string getName() const;
        int getNumCoins() const;
        int getNumCards() const;
        static int getNumChains();
        int getMaxnumChains() const;
        // Fonction qui ajoute un nombre de pièces 
        Player& operator+=(int coins){
            player_Coins += coins;
            return *this;
        }

        nullptr_t createChain(Card * card);

        bool cardMatch(Card * card) const;

        void addCardToHand(Card *card) const;

        // Construire un nouvel objet Player à partir du flux istream
        Player(istream&, const CardFactory* ): num_chains_max(3), num_chains_allowed(2){};

        // Destructeur
        ~Player(){
            delete player_Hand;
        };
        Chain_b& operator[](int i);
        void buyThirdChain();
        friend std::ostream& operator<<(std::ostream& os,  const Player& player ) {
            os << player.player_Name << " has " << player.player_Coins << " coins\n";
            os << "Chain 1: " << player.player_Chain.at(0)->getChainType();
            os << "Chain 2: " << player.player_Chain.at(1)->getChainType();
            return os;
        };
        void savePlayer(int p_id) const;
        // Print la main du player
        void printHand(std::ostream& sortie, bool boolean) const{
            if(!boolean){sortie << player_Hand->top()->getName()[0] << std::endl;}
            else{
                for(int i = 0; i < player_Hand->numCards(); i++){
                    sortie << player_Hand->getCard(i)->getName()[0] << " ";
                }
                sortie << std::endl;
            }
        };
};

#endif