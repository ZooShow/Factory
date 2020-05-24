#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum TASTE{
    sweet,
    sour,
    sugary
};

enum COLOR{
    red,
    green,
    orange,
    yellow
};

string returnColor(COLOR color){
    switch (color) {
        case COLOR::red:
            return "Red";
        case COLOR::green:
            return "Green";
        case COLOR::yellow:
            return "Yellow";
        case COLOR::orange:
            return "Orange";
    }
}

string returnTaste(TASTE taste){
    switch (taste){
        case TASTE::sugary:
            return "Sugary";
        case TASTE::sweet:
            return "Sweet";
        case TASTE::sour:
            return "Sour";
    }
}

class Fruit{
    TASTE taste;
    unsigned int size;
    unsigned int weight;
    COLOR color;
    string description;
public:
    Fruit(TASTE taste, unsigned int size, unsigned int weight, COLOR color, string description){
        this->taste = taste;
        this->size = size; // in cm
        this->weight = weight; // in gramm
        this->color = color;
        this->description = description;
    }

    string getTaste() const {
        return returnTaste(taste);
    }

    unsigned int getSize() const {
        return size;
    }

    unsigned int getWeight() const {
        return weight;
    }

    string getColor() const {
        return returnColor(color);
    }

    const string &getDescription() const {
        return description;
    }

    static Fruit *giveAppleRed(){
        return new Fruit(TASTE::sweet, 5, 100, COLOR::red, "Red apple");
    }

    static Fruit *giveAppleGreen(){
        return new Fruit (TASTE::sour,4, 90, COLOR::red, "Green apple");
    }

    static Fruit *giveWatermellon(){
        return new Fruit(TASTE::sugary, 70 , 8000, COLOR::green, "Watermellon");
    }

    static Fruit *giveOrange(){
        return new Fruit(TASTE::sour, 10, 300, COLOR::orange, "Orange");
    }

    static Fruit *giveMellon(){
        return new Fruit(TASTE::sugary, 70, 2000, COLOR::yellow, "Mellon");
    }
};

class ShoppingList{
    vector<const Fruit*> fruits;
public:
    void add(Fruit &fruit){
        fruits.push_back(&fruit);
    }

    void print(){
        size_t size = fruits.size();
        if (size == 0){
            cout << "Empty" << endl;
        } else {
            for (int i = 0; i < size; ++i){
                cout << fruits[i]->getDescription() << " taste: " << fruits[i]->getTaste()
                << " size: " << fruits[i]->getSize() << " wegiht: " << fruits[i]->getWeight()
                << " color: " << fruits[i]->getColor() << endl;
            }
        }
    }
};

int main() {
    ShoppingList shoppingList;
    shoppingList.add(*Fruit::giveWatermellon());
    shoppingList.add(*Fruit::giveMellon());
    shoppingList.add(*Fruit::giveAppleGreen());
    shoppingList.add(*Fruit::giveOrange());
    shoppingList.add(*Fruit::giveAppleRed());
    shoppingList.print();
    return 0;
}
