#pragma once
#ifndef _AIRPORTSYSTEM_
#define _AIRPORTSYSTEM_

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <cmath>
#include <cfloat>
#include <fstream>
#include <iomanip>

#define FLIGHT_DATA_PATH "flight.txt"
#define USERS_DATA_PATH "users.txt"
#define TICKET_DATA_PATH "ticket-bought.txt"
#define NOT_FOUND -1
#define FLIGHT_CODE_9 "VJA"
#define _FLIGHT_CODE_9 "VNA"
#define ISBN_VN "604"
#define OVERDUE_MONEY_VN_BOOK 10000
#define OVERDUE_MONEY_FOREIGN_BOOK 20000
using namespace std;

//Ham ho tro
bool IsEmpty(const string &data);
string ToLower(const string &str);

class AirportSystem
{
protected:
public:
	AirportSystem(){};
	virtual void Input() = 0;
	virtual void Output() = 0;
	virtual void InputFile(ifstream &input) = 0;
	virtual void OutputFile(ofstream &path) = 0;
	~AirportSystem(){};
};

#endif
