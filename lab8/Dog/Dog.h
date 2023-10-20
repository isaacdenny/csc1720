#ifndef DOG_H
#define DOG_H

#include<string>

using namespace std;

class Dog {
private:
    double price;
    string breed;
    string color;

public:
    Dog();
    double getPrice() { return price; }
    void setPrice(double p);
    string getBreed() { return breed; }
    void setBreed(string b);
    string getColor() { return color; }
    void setColor(string c);
};

#endif