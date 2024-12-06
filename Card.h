#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
public:
    virtual ~Card() = default;
    virtual int getCardsPerCoin(int coins) const = 0;
    virtual string getName() const = 0;
    virtual void print(ostream& out) const = 0;
};
class Blue : public Card {
    int coinslist[4] = {4, 6, 8, 10};
public:
    int getCardsPerCoin(int coins) const override {
        return coinslist[coins-1];
    }
    string getName() const override {
        return "Blue";
    }
    void print(ostream& out) const override {
        out << "B";
    }
};
class Chili : public Card {
    int coinslist[4] = {3, 6, 8, 9};
public:
    int getCardsPerCoin(int coins) const override {
        return coinslist[coins-1];
    }
    string getName() const override {
        return "Chili";
    }
    void print(ostream& out) const override {
        out << "C";
    }
};
class Stink : public Card {
    int coinslist[4] = {3,5,7,8};
public:
    int getCardsPerCoin(int coins) const override {
        return coinslist[coins-1];
    }
    string getName() const override {
        return "Stink";
    }
    void print(ostream& out) const override {
        out << "S";
    }
};
class Green : public Card {
    int coinslist[4] = {3,5,6,7};
public:
    int getCardsPerCoin(int coins) const override {
        return coinslist[coins-1];
    }
    string getName() const override {
        return "Green";
    }
    void print(ostream& out) const override {
        out << "G";
    }
};
class soy : public Card {
    int coinslist[4] = {2,4,6,7};
public:
    int getCardsPerCoin(int coins) const override {
        return coinslist[coins-1];
    }
    string getName() const override {
        return "soy";
    }
    void print(ostream& out) const override {
        out << "s";
    }
};
class black : public Card {
    int coinslist[4] = {2,4,5,6};
public:
    int getCardsPerCoin(int coins) const override {
        return coinslist[coins-1];
    }
    string getName() const override {
        return "black";
    }
    void print(ostream& out) const override {
        out << "b";
    }
};
class Red : public Card {
    int coinslist[4] = {2,3,4,5};
public:
    int getCardsPerCoin(int coins) const override {
        return coinslist[coins-1];
    }
    string getName() const override {
        return "Red";
    }
    void print(ostream& out) const override {
        out << "R";
    }
};
class garden : public Card {
    int coinslist[4] = {0,2,3,0};
public:
    int getCardsPerCoin(int coins) const override {
        return coinslist[coins-1];
    }
    string getName() const override {
        return "garden";
    }
    void print(ostream& out) const override {
        out << "g";
    }
};

#endif


