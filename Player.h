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
        int player_Coins;
        // Construire un nouvel objet Player
        Player(std::string& name): num_chains_max(3), num_chains_allowed(2){
            player_Name  = name;
            player_Coins = 0;
            player_Hand  = new Hand();
        };
        
        std::string getName();
        int getNumCoins(); 
        int getNumCards();
        int getNumChains();
        int getMaxnumChains();

        // Fonction qui ajoute un nombre de pièces 
        Player& operator+=(int coins){
            player_Coins += coins;
            return *this;
        };

        // Construire un nouvel objet Player à partir du flux istream
        Player(istream&, const CardFactory* ): num_chains_max(3), num_chains_allowed(2){

        }; 

        // Destructeur 
        ~Player(){
            delete player_Hand;
        };
        
    
        Chain_b& operator[](int i);
        void buyThirdChain();
        friend std::ostream& operator<<(std::ostream&,  const Player& );
        void savePlayer(int p_id);
        // Print la main du player
        void printHand(std::ostream& sortie, bool boolean){
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