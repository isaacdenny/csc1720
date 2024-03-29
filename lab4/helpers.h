#ifndef HELPERS_H
#define HELPERS_H
#ifdef _WIN32
#include <Windows.h>
#else
#include <thread>
#include <chrono> 
#endif
#include <string>
#include <iostream>
#include <random>
#include <time.h>
using namespace std;

void lazyPrint(string toPrint, int time = 40, bool endline = true);
string getRoomDesc();
string getMonsterName();

extern string m_mTypes[10];
extern string m_adjs[13];
extern string m_rTypes[10];
extern string m_rAdd[12];

#endif // !HELPERS_H
