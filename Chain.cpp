#include "Chain.h"
#include "Card.h"
#include <iomanip>
#include <fstream>

int Chain_b::getSize(){
    return chain.size();
}
void Chain_b::setChainType(std::string chainType){
    this->chainType = chainType;
}
std::string Chain_b::getChainType(){
    return chainType;
}

void Chain_b::saveChain(std::ofstream& filename){
    filename << std::endl << chainType << std::endl;
    for(int i = 0; i < chain.size() ; i++){
        chain.at(i)->saveCard(filename);
        filename << std::endl;
    }
    std::cout << "Chaine sauvegardée" << std::endl;
}
std::ostream& operator<<( std::ostream &output, const Chain<Card*> & d ){
    output << d.chainType << " ";
    for(int i = 0; i < d.chain.size(); i++){
        d.chain.at(i)->print(output);
        output << " ";
    }
    return output;
};
std::ostream& operator<<( std::ostream &output, const Chain_b & d ){
    output << d.chainType  << " " << std::setw(4);
    for(int i = 0; i < d.chain.size(); i++){
        d.chain.at(i)->print(output);
        output << " ";
    }
    return output;
}