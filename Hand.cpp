#include "Hand.h"

//  renvoie et supprime la première carte de la main du joueur
Hand::Hand() = default;

Card* Hand::play(){ 
    Card* card = player_Hand.front();
    player_Hand.pop(); 
    return card;
};

// renvoie mais ne supprime pas la première carte de la main du joueur
Card* Hand::top(){
    Card* card = player_Hand.front();
    return card;
} 
Card* Hand::getCard(int pos){
    Card* card = nullptr; // removed card to return
    if(pos > player_Hand.size()-1){
        std::cout << "(getCard) The index "  << pos << " can not be used. Current size of the hand = " << player_Hand.size() << std::endl;
    }else{
        std::queue <Card*, std::list<Card*>> temp; // temp player hand
        Card* temp_card = nullptr;  // temp card
        int find_idx = 0;
        while(!player_Hand.empty()){
            if(find_idx++ == pos){
                card = player_Hand.front();
            }
            temp_card = player_Hand.front(); // get the card
            player_Hand.pop();     // add it in the temporary queue
            temp.push(temp_card); // add the card in the queue
            
        }
        while(!temp.empty()){
            temp_card = temp.front(); // get the card
            temp.pop();     // add it in the temporary queue
            player_Hand.push(temp_card); // add the card in the queue
        }
    }
    return card;  
}
// affiche le nombre de cartes par main 
int Hand::numCards(){
    return player_Hand.size();
}

// opérateur d'insertion - la main affiche toutes les cartes dans l'ordre
std::ostream& operator<<( std::ostream& sortie, Hand& hand){
    for( int i = 0; i < hand.numCards() ; i++ ){
        sortie << hand.getCard(i) << std::endl;
    }
    return sortie;
};

// Sauvegarder la main 
void Hand::saveHand(std::ofstream& filename){

    Card* card = nullptr; 
    std::queue <Card*, std::list<Card*>> temp; 
    Card* temp_card = nullptr;  
    int find_idx = 0;
    while(!player_Hand.empty()){
        temp_card = player_Hand.front(); 
        temp_card -> saveCard(filename);
        player_Hand.pop();     
        temp.push(temp_card); 
    }
    while(!temp.empty()){
        temp_card = temp.front(); 
        temp.pop();    
        player_Hand.push(temp_card); 
    }
    std::cout << "Hand sauvegardée" << std::endl;
}

