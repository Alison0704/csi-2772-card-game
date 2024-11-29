//
// Created by Alison Emilien on 2024-11-29.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Card {

public:
    virtual ~Card() = default;

    virtual int getCardsPerCoin(int coins) const = 0;
    virtual string getName() const = 0;
    virtual void print(ostream& out) const = 0;

    friend ostream& operator<<(ostream& out, const Card& card);
};

inline ostream& operator<<(ostream& out, const Card& card) {
    card.print(out);
    return out;
}

class Blue : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        return cardCoins[0][coins-1];
    }

    string getName() const override {
        return "Blue";
    }

    void print(ostream& out) const override {
        out << "B";
    }
};
class Chili : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        return cardCoins[1][coins-1];
    }
    string getName() const override {
        return "Chili";
    }
    void print(ostream& out) const override {
        out << "C";
    }
};
class Stink : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        return cardCoins[2][coins-1];
    }

    string getName() const override {
        return "Stink";
    }

    void print(ostream& out) const override {
        out << "S";
    }
};
class Green : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        return cardCoins[3][coins-1];
    }

    string getName() const override {
        return "Green";
    }

    void print(ostream& out) const override {
        out << "G";
    }
};
class soy : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        return cardCoins[4][coins-1];
    }

    string getName() const override {
        return "soy";
    }

    void print(ostream& out) const override {
        out << "S";
    }
};
class black : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        return cardCoins[5][coins-1];
    }

    string getName() const override {
        return "Black";
    }

    void print(ostream& out) const override {
        out << "b";
    }
};
class Red : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        return cardCoins[6][coins-1];
    }

    string getName() const override {
        return "Red";
    }

    void print(ostream& out) const override {
        out << "R";
    }
};
class Garden : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        return cardCoins[7][coins-1];
    }

    string getName() const override {
        return "Garden";
    }

    void print(ostream& out) const override {
        out << "G";
    }
};


