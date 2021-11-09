#include "Users.h"

Users::Users()
{
	_name = "";
	_ID = "";
	_age = 0;
	_address = "";
}
Users::Users(const Users &users)
{
	_name = users._name;
	_ID = users._ID;
	_age = users._age;
	_address = users._address;
}
Users::Users(string name, string ID, int age, string address)
{
	_name = name;
	_ID = ID;
	_age = age;
	_address = address;
}
Users::~Users()
{
}

string Users::GetName() const
{
	return _name;
}
string Users::GetAddress() const
{
	return _address;
}
string Users::GetID() const
{
	return _ID;
}
int Users::GetAge() const
{
	return _age;
}

void Users::SetName(const string &name)
{
	if (!IsEmpty(name))
		_name = name;
}
void Users::SetID(const string &ID)
{
	if (CheckID(ID))
		_ID = ID;
}
void Users::SetAddress(const string &address)
{
	if (!IsEmpty(address))
		_address = address;
}
void Users::SetAge(int age)
{
	if (age > 0)
		_age = age;
}

bool Users::CheckID(const string &ID)
{

	for (int i = 0; i < ID.length(); ++i)
		if (ID[i] < '0' || ID[i] > '9')
		{
			cerr << "\nID phai la so tu 0-9 !" << endl;
			return false;
		}
	return true;
}
void Users::Input()
{
	while (1)
	{
		cout << "\nNhap ho ten: ";
		getline(cin, _name);
		if (!IsEmpty(_name))
			break;
	}
	while (1)
	{
		cout << "\nNhap ID: ";
		getline(cin, _ID);
		if (!IsEmpty(_ID) && CheckID(_ID))
			break;
	}
	while (1)
	{
		cout << "\nNhap dia chi: ";
		getline(cin, _address);
		if (!IsEmpty(_address))
			break;
	}
	while (1)
	{
		cout << "\nNhap tuoi: ";
		cin >> _age;
		if (cin.fail())
			throw "NaN - du lieu nhap phai la 1 so";
		if (_age > 0)
			break;
		cerr << "\nTuoi phai lon > 0 !";
	}
}
void Users::Output()
{
	cout << "\nHo Ten: " << _name;
	cout << "\nID: " << _ID;
	cout << "\nDia chi: " << _address;
	cout << "\nTuoi: " << _age;
}

void Users::InputFile(ifstream &input)
{
	getline(input, _name);
	getline(input, _ID);
	getline(input, _address);
	input >> _age;
}
void Users::OutputFile(ofstream &out)
{
	out << _name << endl;
	out << _ID << endl;
	out << _address << endl;
	out << _age << endl;
}

Users &Users::operator=(const Users &users)
{
	_name = users._name;
	_ID = users._ID;
	_age = users._age;
	_address = users._address;
	return *this;
}

ostream &operator<<(ostream &os, const Users &users)
{
	os << users._name << endl;
	os << users._ID << endl;
	os << users._address << endl;
	os << users._age << endl;
	return os;
}

bool operator==(const Users &r1, const Users &r2)
{
	return ToLower(r1._name) == ToLower(r2._name) && ToLower(r1._address) == ToLower(r2._address) && r1._ID == r2._ID && r1._age == r2._age;
}
