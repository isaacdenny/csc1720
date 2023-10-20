#ifndef CONTACT_H
#define CONTACT_H

#include<string>
using namespace std;

class Contact {
    private:
        string fName;
        string lName;
        string eMail;
        string addr;
    public:
        Contact(string f, string l, string e, string a);
        string getFName() { return fName; }
        string getLName() { return lName; }
        string getEmail() { return eMail; }
        string address() { return addr; }
        void setFName(string f);
        void setLName(string l);
        void setEmail(string e);
        void setAddress(string a);
        string toString();
};

#endif