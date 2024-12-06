#include <iostream>

#include "Main.h"

using namespace std;

int loadFromFile(const string& fileName) {
    ifstream file;
    file.open(fileName);
    if (!file.is_open()) {
        cout << "Error opening file " << fileName << endl;
        return -1;

    } else {
        cout << "Successfully opened file " << fileName << endl;
        return 0;
    }
}
int saveToFile(const string& fileName) {
    ofstream file;
    file.open(fileName);
    if (!file.is_open()) {
        cout << "Error opening file " << fileName << endl;
        return -1;
    } else {
    cout << "Successfully opened file " << fileName << endl;
    return 0;
    }
}

int main(){

return 0;

}