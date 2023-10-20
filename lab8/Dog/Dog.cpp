#include"Dog.h"

Dog::Dog() : price(10), breed("weenie"), color("blue") {}

void Dog::setPrice(double p) {
    if (price > 0) price = p;
}

void Dog::setBreed(string b) {
    breed = b;
}

void Dog::setColor(string c) {
    color = c;
}