#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  cout << fixed << showpoint << setprecision(2);
  double payPerHour;
  int hoursPerWeek;
  double total;
  double totalAfterTaxes;
  double foodMoney;

  cout << "Welcome to Summer Job Calculator";
  cout << endl;
  cout << endl;
  cout << "Enter the pay per hour> ";
  cin >> payPerHour;
  cout << "Enter the number of hours per week> ";
  cin >> hoursPerWeek;

  total = 10 * hoursPerWeek * payPerHour;
  totalAfterTaxes = total * 0.82;
  foodMoney = totalAfterTaxes * 0.2;

  cout << endl;
  cout << endl;
  cout << "For all 10 weeks, your gross pay will be $";
  cout << total;
  cout << endl;
  cout << "After taxes, your net income is $";
  cout << totalAfterTaxes;
  cout << endl;
  cout << "You set aside $";
  cout << foodMoney;
  cout << " for food.";
  cout << endl;
  cout << "You have $";
  cout << totalAfterTaxes - foodMoney;
  cout << " for spending money.";
  cout << endl;

  return 0;
}