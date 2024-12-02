#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <queue>
#include <list>
#include <sstream>

class CardFactory;

class Hand{
    public :
        std::queue <Card*, std::list<Card*>> player_Hand; // Queue qui contient les cartes du player - représente la main
        // Constructeur sans arguments
        Hand(){};
        // Constructeur avec args 
        Hand(std::istream& entree, const CardFactory* card_fact){
            std::string line;
            Card* card = nullptr;
            int card_cnt = 0; 
            while (std::getline(entree, line)){
                std::istringstream iss(line);
                std::string line_data;
                if (!(iss >> line_data)) { 
                    continue; // ligne vide - passer à la prochaine itération
                } 
                card_cnt++;
                if(line_data == "B")       card = new Blue;
                else if(line_data == "C")  card = new Chili;
                else if(line_data == "S")  card = new Stink;
                else if(line_data == "G")  card = new Green;
                else if(line_data == "s")  card = new soy;
                else if(line_data == "b")  card = new black;
                else if(line_data == "R")  card = new Red;
                else if(line_data == "g")  card = new garden;
                else {
                    std::cout << "Carte reçue n'appartient à aucune catégorie de cartes, valeur de carte reçue : " << line_data << std::endl;
                    exit(1);
                }
                // carte non nulle - push dans la main
                if(card != nullptr) player_Hand.push(card);

            }

            std::cout << "La main a maintenant " << card_cnt << " cartes reçues du fichier" <<std::endl;
        };

        // Ajouter la carte 
        Hand& operator+=(Card* card){
            player_Hand.push(card);
            return *this;
        };

        Card* play(); // renvoie et supprime la première carte de la main du joueur
        Card* top(); // renvoie mais ne supprime pas la première carte de la main du joueur
        Card* getCard(int pos); 
        Card* operator[](int c_position){
            int remove_id = 0;  // Index de la carte qui doit etre supp
            Card* card = nullptr; // carte qui doit etre retournée
            std::queue <Card*, std::list<Card*>> temp; // copie de la main du player
            Card* temp_card = nullptr;  // copie de la carte

            while(!player_Hand.empty()){
                if(remove_id++ == c_position){
                    card = player_Hand.front();
                    player_Hand.pop();
                }
                else{
                    temp_card = player_Hand.front(); 
                    player_Hand.pop();     
                    temp.push(temp_card); 
                }
            }

            while(!temp.empty()){
                temp_card = temp.front();
                temp.pop();    
                player_Hand.push(temp_card); 
            }
            return card; 
        };

        int numCards();
        friend std::ostream& operator<<( std::ostream&,  Hand& );
        void saveHand(std::ofstream& filename);
};

#endif