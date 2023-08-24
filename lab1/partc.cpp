#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  cout << fixed << showpoint << setprecision(2);
  double payPerHour;
  int hoursPerWeek;
  double total;
  double totalAfterTaxes;
  double clothesMoney;
  double schoolSupplies;
  double savingsBonds;
  double parentsContribution;

  cout << "Welcome to Summer Job Calculator";
  cout << endl;
  cout << endl;
  cout << "Enter the pay per hour> ";
  cin >> payPerHour;
  cout << "Enter the number of hours per week> ";
  cin >> hoursPerWeek;

  total = 10 * hoursPerWeek * payPerHour;
  totalAfterTaxes = total - (total * 0.14);
  clothesMoney = totalAfterTaxes * 0.1;
  schoolSupplies = totalAfterTaxes * 0.3;
  savingsBonds = (totalAfterTaxes - clothesMoney - schoolSupplies) * 0.25;
  parentsContribution = savingsBonds * 0.5;

  cout << endl;
  cout << endl;
  cout << "Your total income is $";
  cout << total;
  cout << endl;
  cout << "Your after-tax income is $";
  cout << totalAfterTaxes;
  cout << endl;
  cout << "Money spent on clothes is $";
  cout << clothesMoney;
  cout << endl;
  cout << "Money spent on school supplies $";
  cout << schoolSupplies;
  cout << endl;
  cout << "Personal investment is $";
  cout << savingsBonds;
  cout << endl;
  cout << "Total investment is $";
  cout << savingsBonds + parentsContribution;
  cout << endl;

  return 0;
}