#include "BuyTicket.h"

BuyTicket::BuyTicket()
{
	_Flight_list.resize(0);
	_returned.resize(0);
}
BuyTicket::BuyTicket(const BuyTicket &bt)
{
	_planes = bt._planes;
	_Flight_list = bt._Flight_list;
	_borrow_date = bt._borrow_date;
	_Flight_return_date = bt._Flight_return_date;
	_returned = bt._returned;
}
BuyTicket::~BuyTicket()
{
}

Plane BuyTicket::GetPlane() const
{
	return _planes;
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

void BuyTicket::SetPlane(const Plane &r)
{
	_planes = r;
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
	cout << "\n===== Nhap thong tin nguoi mua =====";
	cout << "\nNhap ma chuyen bay: ";
	_planes.Input();
	cout << "\n===== Nhap thong tin ve mua =====";
	cin.ignore();
	_Flight_list.resize(1);
	cout << "\n==== Nhap thong tin ve ====";
	_Flight_list[0].Input();
	cin.ignore();
	while (1)
	{
		cout << "\nNgay mua (dd/mm/yyyy): ";
		cin >> _borrow_date;
		if (_borrow_date.validityCheck_Fix())
			break;
		cout << "\nNgay nhap khong hop le !";
	}
	_returned.push_back(0);
}
void BuyTicket::Output()
{
	cout << "\n===== Thong tin nguoi mua ve =====";
	_planes.Output();
	cout << "\n\n===== Thong tin cac ve =====";
	for (int i = 0; i < _Flight_list.size(); ++i)
	{
		cout << "\n========== Ve " << i + 1 << " ==========";
		_Flight_list[i].Output();
	}
	// cout << "\n\n========== Thong tin Muon/Tra ==========" << endl;
	// cout << "Ngay muon sach: " << _borrow_date;
	// cout << "\nNgay tra sach: " << endl;
	// for (int i = 0; i < _returned.size(); ++i)
	// {
	// 	cout << "-->Quyen " << i + 1 << ": ";
	// 	if (!_returned[i])
	// 		cout << "... (chua tra)" << endl;
	// 	else
	// 		cout << _Flight_return_date[i] << endl;
	// }
}

void BuyTicket::InputFile(ifstream &input)
{
	_planes.InputFile(input);
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
	out << _planes;
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
