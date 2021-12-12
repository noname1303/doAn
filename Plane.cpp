#include "Plane.h"
#include <iomanip>
#include <stdlib.h>
Plane::Plane()
{
	_maHieu = "";
	_loaiMB = "";
	_code = "";
}
Plane::Plane(const Plane &plane)
{
	_maHieu = plane._maHieu;
	_code = plane._code;
}
Plane::Plane(string maHieu, string loaiMB, string Code)
{
	_maHieu = maHieu;
	_loaiMB = loaiMB;
	_code = Code;
}
Plane::~Plane()
{
}
string Plane::GetKey()
{
	return _maHieu;
}
// void Plane::PrintSeats()
// {
// 	int soDay = GetSoDay();
// 	int soGhe = GetSoGhe();
// 	for (int i = 0; i < soDay; i++)
// 	{
// 		for (int j = 0; j < soGhe; j++)
// 		{
// 			cout << " "
// 				 << (char)(i + 65) << j;
// 		}
// 		cout << "\n";
// 	}
// }

string Plane::GetMaHieu() const
{
	return _maHieu;
}
string Plane::GetLoaiMB() const
{
	return _loaiMB;
}
string Plane::GetCodeMB() const
{
	return _code;
}

void Plane::SetMaHieu(const string &maHieu)
{
	if (!IsEmpty(maHieu))
		_maHieu = maHieu;
}
void Plane::SetLoaiMB(const string &loaiMB)
{
	if (!IsEmpty(loaiMB))
		_loaiMB = loaiMB;
}
void Plane::SetCodeMB(const string &codeMB)
{
	if (CheckCode(codeMB))
		_code = codeMB;
}
void Plane::SetKey(const string &key)
{

	_maHieu = key;
}

bool Plane::CheckCode(const string &Code)
{
	if (Code.length() != 6)
	{
		cerr << "\nCode phai co do dai la 6 !";
		return false;
	}
	for (int i = 0; i < Code.length(); ++i)
		if (Code[i] < '0' || Code[i] > '9')
		{
			cerr << "\nCode phai la so tu 0-9 !" << endl;
			return false;
		}
	return true;
}
bool Plane::CheckMaMayBay(const string &maHieu)
{
	if (maHieu.length() != 5)
	{
		cerr << "\nMa hieu do do dai 5 ki tu!";
		return false;
	}
	return true;
}
void Plane::Input()
{
	while (1)
	{
		cout << "\nNhap ma hieu may bay: ";
		getline(cin, _maHieu);
		if (!IsEmpty(_maHieu) && CheckMaMayBay(_maHieu))
			break;
	}
	while (1)
	{
		cout << "\nNhap loai may bay: ";
		getline(cin, _loaiMB);
		if (!IsEmpty(_loaiMB))
			break;
	}
	while (1)
	{
		cout << "\nNhap Code: ";
		getline(cin, _code);
		if (!IsEmpty(_code) && CheckCode(_code))
			break;
	}
}
void Plane::Output()
{
	TextColor(SHOW_COLOR);
	cout << "  |     " << setw(12) << left << _maHieu
		 << "|   "
		 << setw(11) << _loaiMB
		 << "|     "
		 << setw(9) << _code;
}

void Plane::InputFile(ifstream &input)
{
	getline(input, _maHieu);
	getline(input, _loaiMB);
	getline(input, _code);
}
void Plane::OutputFile(ofstream &out)
{
	out << _maHieu << endl;
	out << _loaiMB << endl;
	out << _code << endl;
	out << "" << endl;
}

Plane &Plane::operator=(const Plane &plane)
{
	_maHieu = plane._maHieu;
	_loaiMB = plane._loaiMB;
	_code = plane._code;
	return *this;
}

ostream &operator<<(ostream &os, const Plane &plane)
{
	os << plane._maHieu << endl;
	os << plane._loaiMB << endl;
	os << plane._code << endl;
	return os;
}

bool operator==(const Plane &r1, const Plane &r2)
{
}
