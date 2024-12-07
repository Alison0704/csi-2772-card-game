#include "Card.h"

#include <fstream>
using namespace std;


std::ostream& operator<<(std::ostream& out, Card& card) 
{ 
    card.print(out);
    return out; 
} 

void Card::saveCard(std::ofstream& filename){
    std::ostream& out = filename;  
    out << *this;  
}