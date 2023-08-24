/*
Programmer: Isaac Denny
*/

#include <iostream>

using namespace std;

int main() {
  int quantity = 0;
  double price = 1.5;
  double total = 0.0;

  cout << "How many donuts would you like (Enter an int): ";
  cin >> quantity;

  total = quantity * price;

  cout << "Your total is: $ ";
  cout << total;
  cout << endl;

  return 0;
}