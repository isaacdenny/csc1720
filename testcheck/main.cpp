#include<iostream>

using namespace std;

struct Bird {
public:
	double wingSpan;
	bool isFlying;
	string lawyerName;
};

int main() {
	Bird bird;
	bird.wingSpan = 3.5;
	cout << bird.wingSpan;
	return 0;
}