#include<iostream>
#include"Dog/Dog.h"
#include"Contact/Contact.h"
#include<vector>

using namespace std;

void printMenu();
void listContacts(vector<Contact> contacts);
Contact addNew(vector<Contact> contacts);
void sortByLName(vector<Contact>& contacts);
void findByLName(vector<Contact> contacts);

int main() {
    Contact i("Isaac", "Denny", "idenny@highpoint.edu", "123 rd");
    Contact m("Michael", "Adder", "madder@highpoint.edu", "124 rd");
    Contact j("Michael", "Boyd", "jboyd@highpoint.edu", "125 rd");
    vector<Contact> contacts;

    contacts.push_back(i);
    contacts.push_back(m);
    contacts.push_back(j);

    char input = 'm';
    cout << "\nWelcome to the Contact Manager!\n\n";
    while (input != 'q')
    {
        switch(input) {
            case 'm':
                printMenu();
                break;
            case 'l':
                listContacts(contacts);
                break;
            case 'a':
                contacts.push_back(addNew(contacts));
                break;
            case 's':
                sortByLName(contacts);
                break;
            case 'f':
                findByLName(contacts);
                break;
            default:
                break;
        }
        cout << "What would you like to do? ";
        cin >> input;
        cout << endl;
    }
    return 0;
}

void printMenu() {
    cout << "Your options are:\n";
    cout << "(l) List all contacts unsorted\n";
    cout << "(a) Add a new contact\n";
    cout << "(s) Sort and list all contacts by last name\n";
    cout << "(f) Find and list contacts by last name\n\n";
}

void listContacts(vector<Contact> contacts)
{
    for (int i = 0; i < contacts.size(); i++)
    {
        cout << contacts.at(i).toString() << endl;
    }
}

Contact addNew(vector<Contact> contacts) {
    string f, l, e, a;
    cout << "### Create New Contact ###\n\n";
    cout << "First Name: ";
    cin >> f;
    cout << endl;
    cout << "Last Name: ";
    cin >> l;
    cout << endl;
    cout << "Email: ";
    cin >> e;
    cout << endl;
    cout << "Address: ";
    cin >> a;
    cout << endl;
    cin.ignore(1);

    Contact c(f, l, e, a);
    return c;
}

void sortByLName(vector<Contact>& contacts) {
    int index = 0;
    for (int i = 0; i < contacts.size() - 1; i++)
    {
        cout << i;
        index = i;
        for (int j = i + 1; j < contacts.size(); j++)
        {
            if (contacts.at(j).getLName() < contacts.at(index).getLName())
            {
                index = j;
            }
        }

        Contact temp = contacts.at(i);
        contacts.at(i) = contacts.at(index);
        contacts.at(index) = temp;
    }
}

void findByLName(vector<Contact> contacts) {

    vector<Contact> result;
    string search = "";
    cout << "Search Last Name: ";
    cin >> search;

    for (int i = 0; i < contacts.size(); i++)
    {
        if (!contacts.at(i).getLName().compare(search)) {
            result.push_back(contacts.at(i));
        }
    }

    if (result.size() > 0) {
        cout << "Results:\n";
        for (int i = 0; i < result.size(); i++)
        {
            cout << result.at(i).toString();
        }
    }
    else {
        cout << "No results\n";
    }
}