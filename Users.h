#pragma once
#include "AirportSystem.h"
#ifndef _USERS_
#define _USERS_

class Users : public AirportSystem
{
private:
	string _name;
	string _ID; //ID library card
	string _address;
	int _age;

public:
	Users();
	Users(const Users &users);
	Users(string name, string ID, int age, string address);
	~Users();

	string GetName() const;
	string GetID() const;
	string GetAddress() const;
	int GetAge() const;

	void SetName(const string &name);
	void SetID(const string &ID);
	void SetAddress(const string &address);
	void SetAge(int age);

	static bool CheckID(const string &ID);
	void Input();
	void Output();

	void InputFile(ifstream &input);
	void OutputFile(ofstream &path);

	Users &operator=(const Users &r);
	friend ostream &operator<<(ostream &os, const Users &users);
	friend bool operator==(const Users &r1, const Users &r2);
};

#endif
