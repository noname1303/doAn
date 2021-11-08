#include "BuyTicket.h"

BuyTicket::BuyTicket()
{
	_Flight_list.resize(0);
	_returned.resize(0);
}
BuyTicket::BuyTicket(const BuyTicket &bs)
{
	_users = bs._users;
	_Flight_list = bs._Flight_list;
	_borrow_date = bs._borrow_date;
	_Flight_return_date = bs._Flight_return_date;
	_returned = bs._returned;
}
BuyTicket::~BuyTicket()
{
}

Users BuyTicket::GetUsers() const
{
	return _users;
}
Date BuyTicket::GetBorrowDate() const
{
	return _borrow_date;
}
vector<Date> BuyTicket::GetFlightReturnDate() const
{
	return _Flight_return_date;
}
vector<int> BuyTicket::GetReturned() const
{
	return _returned;
}
vector<Flight> BuyTicket::GetFlightList() const
{
	return _Flight_list;
}
int BuyTicket::GetReturned(int pos) const
{
	if (pos >= 0 && pos < _returned.size())
		return _returned[pos];
	else
	{
		throw "Loi truy cap";
		return -1;
	}
}

void BuyTicket::SetUsers(const Users &r)
{
	_users = r;
}
void BuyTicket::SetBorrowDate(Date date)
{
	if (date.validityCheck_Fix())
		_borrow_date = date;
}
void BuyTicket::SetFlightReturnDate(int pos, Date date)
{
	if (date.validityCheck_Fix() && date >= _borrow_date && pos >= 0 && pos < _Flight_return_date.size())
		_Flight_return_date[pos] = date;
}
void BuyTicket::SetReturned(int pos, int returned)
{
	if (pos >= 0 && pos < _returned.size())
		_returned[pos] = returned;
}

void BuyTicket::Input()
{
	cout << "\n===== Nhap thong tin nguoi muon =====";
	_users.Input();
	cout << "\n===== Nhap thong tin cac loai sach muon =====";
	int n;
	while (1)
	{
		cout << "\nNhap so luong sach muon: ";
		cin >> n;
		if (cin.fail())
			throw "NaN - du lieu nhap phai la 1 so";
		if (n > 0)
			break;
		cerr << "\nSo sach muon > 0";
	}
	cin.ignore();
	_Flight_list.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cout << "\n==== Nhap thong tin sach thu " << i + 1 << " ====";
		_Flight_list[i].Input();
		cin.ignore();
	}
	while (1)
	{
		cout << "\nNgay muon sach (dd/mm/yyyy): ";
		cin >> _borrow_date;
		if (_borrow_date.validityCheck_Fix())
			break;
		cout << "\nNgay nhap khong hop le !";
	}
	for (int i = 0; i < n; ++i)
		_returned.push_back(0);
}
void BuyTicket::Output()
{
	cout << "\n===== Thong tin nguoi muon =====";
	_users.Output();
	cout << "\n\n===== Thong tin cac sach da muon =====";
	for (int i = 0; i < _Flight_list.size(); ++i)
	{
		cout << "\n========== Quyen " << i + 1 << " ==========";
		_Flight_list[i].Output();
	}
	cout << "\n\n========== Thong tin Muon/Tra ==========" << endl;
	cout << "Ngay muon sach: " << _borrow_date;
	cout << "\nNgay tra sach: " << endl;
	for (int i = 0; i < _returned.size(); ++i)
	{
		cout << "-->Quyen " << i + 1 << ": ";
		if (!_returned[i])
			cout << "... (chua tra)" << endl;
		else
			cout << _Flight_return_date[i] << endl;
	}
}

void BuyTicket::InputFile(ifstream &input)
{
	_users.InputFile(input);
	if (input.eof())
		return;
	int n;
	input >> n;
	if (input.fail())
		throw "Khong the doc file";
	_Flight_list.resize(n);
	for (int i = 0; i < n; ++i)
	{
		input.ignore();
		_Flight_list[i].InputFile(input);
	}
	input >> _borrow_date;

	_returned.resize(n);
	_Flight_return_date.resize(n);
	for (int i = 0; i < n; ++i)
	{
		input >> _returned[i];
		if (_returned[i] != 0)
			input >> _Flight_return_date[i];
	}
}
void BuyTicket::OutputFile(ofstream &out)
{
	out << _users;
	out << _Flight_list.size() << endl;
	for (int i = 0; i < _Flight_list.size(); ++i)
		out << _Flight_list[i];
	out << _borrow_date << endl;
	for (int i = 0; i < _returned.size(); ++i)
	{
		if (_returned[i] != 0)
		{
			out << _returned[i] << " ";
			if (i != _returned.size() - 1)
				out << _Flight_return_date[i] << " ";
			else
				out << _Flight_return_date[i];
		}
		else
		{
			if (i != _returned.size() - 1)
				out << _returned[i] << " ";
			else
				out << _returned[i];
		}
	}
	out << endl;
}
