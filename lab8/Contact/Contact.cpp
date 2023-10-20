#include "Contact.h"

Contact::Contact(string f, string l, string e, string a) : fName(f), lName(l), eMail(e), addr(a) {}

void Contact::setFName(string f)
{
    fName = f;
}

void Contact::setLName(string l)
{
    lName = l;
}

void Contact::setEmail(string e)
{
    eMail = e;
}

void Contact::setAddress(string a)
{
    addr = a;
}

string Contact::toString() {
    string toReturn = "";
    toReturn += fName + " " + lName + "\n";
    toReturn += "Email: " + eMail + "\n";
    toReturn += "Address: " + addr + "\n";
    return toReturn;
}
