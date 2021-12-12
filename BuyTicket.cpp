#include "BuyTicket.h"
#include <iomanip>
#include "Airport.h"
using namespace std;
BuyTicket::BuyTicket()
{
	_MaKhachHang = "";
	_Ten = "";
	_ID = "";
}

BuyTicket::BuyTicket(const string &UserCode, const string &Name, const string &ID)
{
	_MaKhachHang = UserCode;
	_Ten = Name;
	_ID = ID;
}
BuyTicket::~BuyTicket()
{
}
string BuyTicket::GetKey()
{
	return _MaKhachHang;
}
string BuyTicket::GetName() const
{
	return _Ten;
}
string BuyTicket::GetGioiTinh() const
{
	return _GioiTinh;
}
string BuyTicket::GetID() const
{
	return _ID;
}
string BuyTicket::GetUserCode() const
{
	return _MaKhachHang;
}
string BuyTicket::GetMaISFC() const
{
	return _MaISFC;
}
void BuyTicket::SetDate(Date day)
{
	if (day.validityCheck_Fix())
		date = day;
}
void BuyTicket::SetName(const string &Name)
{
	if (!IsEmpty(Name))
		_Ten = Name;
}
void BuyTicket::SetGioiTinh(const string &gt)
{
	if (!IsEmpty(gt))
		_GioiTinh = gt;
}
void BuyTicket::SetID(const string &ID)
{
	if (CheckID(ID))
		_ID = ID;
}
void BuyTicket::SetUserCode(const string &UserCode)
{
	if (CheckUserCode(UserCode))
		_MaKhachHang = UserCode;
}
// void BuyTicket::SetMaISFC(const string &ma)
// {
// 	if (!IsEmpty(ma))
// 		_MaISFC = ma;
// }
void BuyTicket::SetKey(const string &ma)
{
	_MaISFC = ma;
	cout << _MaISFC;
}

bool BuyTicket::CheckID(const string &ID)
{
	if (ID.length() != 9)
	{
		cerr << "\nCMND Khach hang gom 9 ki tu!";
		return false;
	}
	for (int i = 0; i < ID.length(); ++i)
		if (ID[i] > '9' || ID[i] < '0')
		{
			cerr << "\nMa Khach hang phai la nhung chu so 0-9 !";
			return false;
		}
	return true;
}

bool BuyTicket::CheckUserCode(const string &UserCode)
{
	if (UserCode.length() != 6)
	{
		cerr << "\nUserCode phai co do dai la 6 !";
		return false;
	}
	for (int i = 0; i < UserCode.length(); ++i)
		if (UserCode[i] > '9' || UserCode[i] < '0')
		{
			cerr << "\nMa Khach hang phai la nhung chu so 0-9 !";
			return false;
		}
	return true;
}

void BuyTicket::Input()
{

	// while (1)
	// {
	// 	cout << "\nNgay mua (dd/mm/yyyy): ";
	// 	cin >> date;
	// 	// if ()
	// 	// 	break;
	// 	// cout << "\nNgay nhap khong hop le !";
	// 	if (date.validityCheck_Fix())
	// 		break;
	// 	cout << "\nVui long nhap ngay hop le va lon hon hoac bang ngay hien tai!!";
	// }

	while (1)
	{
		cout << "\nNhap ten Khach hang: ";
		getline(cin, _Ten);
		if (!IsEmpty(_Ten))
			break;
	}
	while (1)
	{
		cout << "\nGioi tinh: ";
		getline(cin, _GioiTinh);
		if (!IsEmpty(_GioiTinh))
			break;
	}
	while (1)
	{
		cout << "\nNhap CMND: ";
		getline(cin, _ID);
		if (CheckID(_ID))
			break;
	}
	while (1)
	{
		cout << "\nMa khach hang: ";
		getline(cin, _MaKhachHang);
		if (CheckUserCode(_MaKhachHang))
			break;
	}
}
void BuyTicket::Output()
{

	TextColor(SHOW_COLOR);
	cout << "  |   " << setw(16) << left << _MaISFC
		 << "|   " << setw(17) << _Ten
		 << "|      " << setw(9) << _GioiTinh
		 << "|     " << setw(9) << _ID
		 << "|     " << _MaKhachHang;
}

void BuyTicket::InputFile(ifstream &input)
{
	// input >> date;
	getline(input, _MaISFC);
	getline(input, _Ten);
	getline(input, _GioiTinh);
	getline(input, _ID);
	getline(input, _MaKhachHang);
}
void BuyTicket::OutputFile(ofstream &out)
{
	out << _MaISFC << endl;
	out << _Ten << endl;
	out << _GioiTinh << endl;
	out << _ID << endl;
	out << _MaKhachHang << endl;
	out << "" << endl;

	// out << date << endl;
}

BuyTicket &BuyTicket::operator=(const BuyTicket &BuyTicket)
{
	_Ten = BuyTicket._Ten;
	_GioiTinh = BuyTicket._GioiTinh;
	_ID = BuyTicket._ID;
	_MaKhachHang = BuyTicket._MaKhachHang;
	return *this;
}

ostream &operator<<(ostream &os, const BuyTicket &BuyTicket)
{
	os << BuyTicket._Ten << endl;
	os << BuyTicket._GioiTinh << endl;
	os << BuyTicket._ID << endl;
	os << BuyTicket._MaKhachHang << endl;
	os << BuyTicket._MaISFC << endl;
	// os << BuyTicket.date << endl;
	return os;
}
