#include "helpers.h"

string m_mTypes[10] = {
	" creature",
	" seal",
	" cheezit",
	" alien",
	" mouse",
	" skeleton",
	" chef",
	" child",
	" fish",
	" animal"
};

string m_adjs[13] = {
	" a slippery",
	" a strange",
	" an upset",
	" a disgusting",
	" a well-sized",
	" a large",
	" a small",
	" a dimly-lit",
	" an unrecognizable",
	" a stuffy",
	" an under-appreciated",
	" a filthy",
	" a gigantic"
};

string m_rTypes[10] = {
	" room",
	" foyer",
	" kitchen",
	" church",
	" attic",
	" greenhouse",
	" bedroom",
	" living room",
	" bathroom",
	" cathedral"
};

string m_rAdd[12] = {
	" with a humidifier in the corner. ",
	" devoid of light. ",
	" devoid of happiness. ",
	" with little ventilation. ",
	" with torches lining the walls. ",
	" with a delapidated floor. ",
	" built of sticks. ",
	" that that is undeniably smelly. ",
	" where none escape (except you maybe). ",
	" where children cry. ",
	" filled with light. ",
	" with large open corridors. "
};

#ifdef _WIN32
void lazyPrint(string toPrint, int time, bool endline) {
	while (toPrint.length() > 0) {
		cout << toPrint[0];
		toPrint.erase(0, 1);
		Sleep(time);
	}
	if (endline) {
		cout << endl;
	}
}
#else
void lazyPrint(string toPrint, int time, bool endline) {
	for (char c : toPrint) {
        cout << c << flush; // Print the character and flush the buffer
        this_thread::sleep_for(chrono::milliseconds(time));
    }
	if (endline) {
		cout << endl;
	}
}
#endif

string getRoomDesc() {
	size_t nadj = sizeof(m_adjs) / sizeof(m_adjs[0]);
	size_t nTypes = sizeof(m_rTypes) / sizeof(m_rTypes[0]);
	size_t nadd = sizeof(m_rAdd) / sizeof(m_rAdd[0]);
	return m_adjs[rand() % nadj] + m_rTypes[rand() % nTypes] + m_rAdd[rand() % nadd];
}

string getMonsterName()
{
	size_t nadj = sizeof(m_adjs) / sizeof(m_adjs[0]);
	size_t nTypes = sizeof(m_mTypes) / sizeof(m_mTypes[0]);
	return m_adjs[rand() % nadj] + m_mTypes[rand() % nTypes];
}
