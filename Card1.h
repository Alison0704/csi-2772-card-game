// //
// // Created by Alison Emilien on 2024-11-17.
// //
//
// #include <string>
// #include <iostream>
//
// using namespace std;
// enum cardType {
//     Blue,Chili,Stink,Green,soy,black,Red,garden
// };
// class Card1 {
// public:
//     Card1(cardType type) {
//         name = type;
//     }
//     virtual ~Card1() = default;
//     virtual int getCardsPerCoin(int coins) const = 0;
//     virtual int getCardsPerCoin(int coins) {
//         int cardCoins[8][4]={4,6,8,10,
//                         3,6,8,9,
//                         3,5,7,8,
//                         3,5,6,7,
//                         2,4,6,7,
//                         2,4,5,6,
//                         2,3,4,5,
//                         0,2,3,0};
//
//         return cardCoins[name][coins-1];
//     }
//     virtual string getName() {
//         switch (name) {
//             case 0:
//                 return "Blue";
//             case 1:
//                 return "Chili";
//             case 2:
//                 return "Stink";
//             case 3:
//                 return "Green";
//             case 4:
//                 return "soy";
//             case 5:
//                 return "black";
//             case 6:
//                 return "Red";
//             case 7:
//                 return "garden";
//         }
//
//
//     }
//     virtual void print(ostream& out) {
//         out << getName()[0];
//     }
// private:
//     cardType name;
// };
