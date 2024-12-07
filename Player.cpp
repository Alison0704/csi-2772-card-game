#include <string>
#include <fstream>
#include "Player.h"

// Get Player Name
std::string Player::getName() const{
    return this->player_Name;
}

// Get Player's number of Coins
int Player::getNumCoins() const{
    return player_Coins;
}

int Player::getNumChains(){
    return 0; // to be changed
}

int Player::getNumCards() const{
    return player_Hand->numCards();
}

int Player::getMaxnumChains() const{
    return num_chains_max;
}

void Player::buyThirdChain(){
    Card* card = nullptr;
    if( (player_Coins % 3 == 0) && (player_Coins > 0)  ){
        if(player_Chain.size() < num_chains_max){
            player_Coins -= 3;
            card = player_Hand->top();
            Chain_b* new_chain;
            if(card->getName() == "Blue") new_chain = new Chain<Blue>;
            else if(card->getName() == "Chili") new_chain = new Chain<Chili>;
            else if(card->getName() == "Stink") new_chain = new Chain<Stink>;
            else if(card->getName() == "Green") new_chain = new Chain<Green>;
            else if(card->getName() == "soy")   new_chain = new Chain<soy>;
            else if(card->getName() == "black") new_chain = new Chain<black>;
            else if(card->getName() == "Red")   new_chain = new Chain<Red>;
            else if(card->getName() == "garden")new_chain = new Chain<garden>;
            else {
                std::cout << "Valeur de la carte reçue non conforme : " << card->getName() << std::endl;
                new_chain = nullptr; 
                exit(1); 
            }
            *new_chain += card;
            player_Chain.push_back(new_chain);
        }else{
            std::cout << "Maximum nombre de chaines acquis"<< player_Chain.size() << std::endl;
        }
    }else{
        throw std::runtime_error("NotEnoughCoins");
    }
}

void Player::savePlayer(int p_id) const {
    
    std::ofstream file;
    char id[2];
    
    sprintf(id, "%d", p_id);
    std::string filename ="Player"+std::string(id)+".txt";

    file.open(filename, std::ios::trunc);

    // player name and players number of coins
    file << "Player's name " << player_Name << " " << "Player's number of coins " << player_Coins << std::endl;
    // sauvegarder la main
    player_Hand->saveHand(file);
    file << std::endl << "-chaines" << std::endl;

    for(int i = 0 ; i < player_Chain.size() ; i++){
        file << std::endl << "---" << std::endl;
        player_Chain.at(i)->saveChain(file);
    }
    
    file << std::endl << "-fin des chaines" << std::endl;
    file.close();
    std::cout << "Player-"+std::string(id) << " sauvegardé " << std::endl;
}
bool Player::cardMatch(Card * card) const {
    for(auto& chain: player_Chain)
        if (chain->match(card)) return true;
    return false;
}

inline void Player::addCardToHand(Card* card) const {*player_Hand += card;}



