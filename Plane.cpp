#include "Plane.h"
#include <iomanip>
#include <stdlib.h>
Plane::Plane()
{
	_maHieu = "";
	_loaiMB = "";
	_code = "";
	_soDay = 0;
	_soGhe = 0;
}
Plane::Plane(const Plane &plane)
{
	_maHieu = plane._maHieu;
	_code = plane._code;
	_soDay = plane._soDay;
	_soGhe = plane._soGhe;
}
Plane::Plane(string maHieu, string loaiMB, string Code, int soDay, int soGhe)
{
	_maHieu = maHieu;
	_loaiMB = loaiMB;
	_code = Code;
	_soDay = soDay;
	_soGhe = soGhe;
}
Plane::~Plane()
{
}

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
int Plane::GetSoDay() const
{
	return _soDay;
}
int Plane::GetSoGhe() const
{
	return _soGhe;
}
int Plane::GetVe() const
{
	return _soDay * _soGhe;
}

void Plane::SetMaHieu(const string &maHieu)
{
	if (!IsEmpty(maHieu))
		_maHieu = maHieu;
}
void Plane::SetLoaiMB(const string &loaiMB)
{
	if (CheckCode(loaiMB))
		_loaiMB = loaiMB;
}
void Plane::SetCodeMB(const string &codeMB)
{
	if (CheckCode(codeMB))
		_code = codeMB;
}

void Plane::SetSoDay(int soDay)
{
	if (soDay > 0)
		_soDay = soDay;
}
void Plane::SetSoGhe(int soGhe)
{
	if (soGhe > 0)
		_soGhe = soGhe;
}

bool Plane::CheckCode(const string &Code)
{
	if (Code.length() != 6)
	{
		cerr << "\nCode phai co do dai la 6 !";
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

	while (1)
	{
		cout << "\nNhap so day: ";
		cin >> _soDay;
		if (cin.fail())
			throw "NaN - du lieu nhap phai la 1 so";
		if (_soDay > 0)
			break;
		cerr << "\nSo day phai > 0 !";
	}
	while (1)
	{
		cout << "\nNhap so ghe: ";
		cin >> _soGhe;
		if (cin.fail())
			throw "NaN - du lieu nhap phai la 1 so";
		if (_soGhe > 0)
			break;
		cerr << "\nSo ghe phai > 0 !";
	}
}
void Plane::Output()
{
	cout << setiosflags(ios::left) << "\nMa hieu: " << setw(6) << _maHieu
		 << "\tLoai: "
		 << setw(15) << _loaiMB
		 << "\tCode: "
		 << setw(7) << _code
		 << "\tSo day: "
		 << setw(4) << _soDay
		 << "\tSo Ghe: "
		 << setw(4) << _soGhe
		 << "\tSo ve:"
		 << GetVe();
}

void Plane::InputFile(ifstream &input)
{
	getline(input, _maHieu);
	getline(input, _loaiMB);
	getline(input, _code);
	input >> _soDay;
	input >> _soGhe;
}
void Plane::OutputFile(ofstream &out)
{
	out << _maHieu << endl;
	out << _loaiMB << endl;
	out << _code << endl;
	out << _soGhe << endl;
	out << _soDay << endl;
}

Plane &Plane::operator=(const Plane &plane)
{
	_maHieu = plane._maHieu;
	_loaiMB = plane._loaiMB;
	_code = plane._code;
	_soDay = plane._soDay;
	_soGhe = plane._soGhe;
	return *this;
}

ostream &operator<<(ostream &os, const Plane &plane)
{
	os << plane._maHieu << endl;
	os << plane._loaiMB << endl;
	os << plane._code << endl;
	os << plane._soGhe << endl;
	os << plane._soDay << endl;
	return os;
}

bool operator==(const Plane &r1, const Plane &r2)
{
	return ToLower(r1._maHieu) == ToLower(r2._maHieu) && ToLower(r1._loaiMB) == ToLower(r2._loaiMB) && r1._code == r2._code && r1._soDay == r2._soDay && r1._soGhe == r2._soGhe;
}
