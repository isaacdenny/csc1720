#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  cout << fixed << showpoint << setprecision(2);
  double payPerHour;
  int hoursPerWeek;
  double total;

  cout << "Welcome to Summer Job Calculator";
  cout << endl;
  cout << "Enter the pay per hour> ";
  cin >> payPerHour;
  cout << "Enter the number of hours per week> ";
  cin >> hoursPerWeek;

  total = 10 * hoursPerWeek * payPerHour;

  cout << endl;
  cout << "For all 10 weeks, you will be paid $";
  cout << total;
  cout << endl;

  return 0;
}