#include<fstream>
#include<iostream>
#include<iomanip>
#include <sstream>
#include <string>

using namespace std;

void showMenu();
void getData(string(&names)[8], float(&prices)[8], int(&quantities)[8]);
void showTable(string(&names)[8], float(&prices)[8], int(&quantities)[8]);
void sortByName(string(&names)[8], float(&prices)[8], int(&quantities)[8]);
void sortByPrice(string(&names)[8], float(&prices)[8], int(&quantities)[8]);
void sortByQuantity(string(&names)[8], float(&prices)[8], int(&quantities)[8]);

int main() {
	string names[8];
	float prices[8];
	int quantities[8];

	getData(names, prices, quantities);

	char input = 'm';
	while (true)
	{
		switch (input) {
		case 'm':
			showMenu();
			break;
		case 's':
			showTable(names, prices, quantities);
			break;
		case 'n':
			sortByName(names, prices, quantities);
			break;
		case 'p':
			sortByPrice(names, prices, quantities);
			break;
		case 'q':
			sortByQuantity(names, prices, quantities);
			break;
		}

		cout << "What would you like to do? [m]enu: ";
		cin >> input;
		cout << endl;
	}

	return 0;
}

void getData(string (&names)[8], float (&prices)[8], int (&quantities)[8])
{
	ifstream inFile;
	inFile.open("items.txt");

	string line;
	int i = 0;
	while (getline(inFile, line))
	{
		std::istringstream iss(line);

		string name;
		int quantity;
		float cost, price;
		iss >> name >> price >> quantity;

		names[i] = name;
		prices[i] = price;
		quantities[i] = quantity;
		i++;
	}

	inFile.close();
}

void showMenu() {
	cout << "[S]how table" << endl;
	cout << "Sort by [n]ame" << endl;
	cout << "Sort by [p]rice" << endl;
	cout << "Sort by [q]uantity" << endl;
}

void showTable(string (&names)[8], float (&prices)[8], int (&quantities)[8])
{
	cout << left << setw(12) << "Item" << setw(11) << "Price" << setw(12) << right << "Quantity" << setw(12) << "Cost" << endl;
	cout << left << setw(12) << "-----------" << setw(11) << "---------" << setw(12) << right << "----------" << setw(12) << "---------" << endl;
	cout << fixed << showpoint << setprecision(2);

	float total = 0;
	for (int i = 0; i < 8; i++) {
		float cost = prices[i] * quantities[i];
		total += cost;
		cout << left << setw(12) << names[i] << setw(11) << prices[i] << setw(12) << right << quantities[i] << setw(12) << cost << endl;
	}
	cout << right << setw(35) << "Total: " << setw(12) << total << endl;
}

void sortByName(string (&names)[8], float (&prices)[8], int (&quantities)[8])
{
	for (int i = 0; i < 8 - 1; i++)
	{
		for (int j = i + 1; j < 8; j++)
		{
			if (names[i] > names[j]) {
				string stemp = names[i];
				names[i] = names[j];
				names[j] = stemp;

				float ftemp = prices[i];
				prices[i] = prices[j];
				prices[j] = ftemp;

				int itemp = quantities[i];
				quantities[i] = quantities[j];
				quantities[j] = itemp;
			}
		}
	}
}

void sortByPrice(string (&names)[8], float (&prices)[8], int (&quantities)[8])
{
	for (int i = 0; i < 8 - 1; i++)
	{
		for (int j = i + 1; j < 8; j++)
		{
			if (prices[i] < prices[j]) {
				string stemp = names[i];
				names[i] = names[j];
				names[j] = stemp;

				float ftemp = prices[i];
				prices[i] = prices[j];
				prices[j] = ftemp;

				int itemp = quantities[i];
				quantities[i] = quantities[j];
				quantities[j] = itemp;
			}
		}
	}
}

void sortByQuantity(string (&names)[8], float (&prices)[8], int (&quantities)[8])
{
	for (int i = 0; i < 8 - 1; i++)
	{
		for (int j = i + 1; j < 8; j++)
		{
			if (quantities[i] < quantities[j]) {
				string stemp = names[i];
				names[i] = names[j];
				names[j] = stemp;

				float ftemp = prices[i];
				prices[i] = prices[j];
				prices[j] = ftemp;

				int itemp = quantities[i];
				quantities[i] = quantities[j];
				quantities[j] = itemp;
			}
		}
	}
}
