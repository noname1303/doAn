#include "Flight.h"
Flight::Flight()
{
	_maChuyenBay = "";
	_noiDen = "";
	_noiDi = "";
	_ISBN = "";
	_price = 0;
}
Flight::Flight(const Flight &Flight)
{
	_maChuyenBay = Flight._maChuyenBay;
	_noiDen = Flight._noiDen;
	_noiDi = Flight._noiDi;
	_code = Flight._code;
	_ISBN = Flight._ISBN;
	_price = Flight._price;
}
Flight::Flight(const string &name, const string &noiDen, const string &noiDi, const string &code, const string &ISBN, double price)
{
	_maChuyenBay = name;
	_noiDen = noiDen;
	_noiDi = noiDi;
	_code = code;
	_ISBN = ISBN;
	if (price < 0)
		_price = 0;
	else
		_price = price;
}
Flight::~Flight()
{
}

string Flight::GetNoiDen() const
{
	return _noiDen;
}
string Flight::GetCode() const
{
	return _code;
}
string Flight::GetISBN() const
{
	return _ISBN;
}
string Flight::GetNoiDi() const
{
	return _noiDi;
}
string Flight::GetMaChuyenBay() const
{
	return _maChuyenBay;
}
double Flight::GetPrice() const
{
	return _price;
}

void Flight::SetTitle(const string &title)
{
	if (!IsEmpty(title))
		_maChuyenBay = title;
}
void Flight::SetAuthor(const string &noiDen)
{
	if (!IsEmpty(noiDen))
		_noiDen = noiDen;
}
void Flight::SetPublisher(const string &pub)
{
	if (!IsEmpty(pub))
		_noiDi = pub;
}
void Flight::SetCode(const string &code)
{
	if (CheckFlightCode(code))
		_code = code;
}
void Flight::SetISBN(const string &ISBN)
{
	if (CheckISBN(ISBN))
		_ISBN = ISBN;
}
void Flight::SetPrice(double price)
{
	if (price > 0)
		_price = price;
}

bool Flight::CheckISBN(const string &ISBN)
{
	if (IsEmpty(ISBN))
		return false;

	if (ISBN.length() != 13)
	{
		cerr << "\nMa ISBN gom 13 chu so !";
		return false;
	}
	string check;
	check = check + ISBN[0] + ISBN[1] + ISBN[2];
	if (check != _EAN_13 && check != EAN_13)
	{
		cerr << "\nMa ISBN-13 bat dau bang 978 hoac 979 !";
		return false;
	}
	for (int i = 0; i < ISBN.length(); ++i)
		if (ISBN[i] > '9' || ISBN[i] < '0')
		{
			cerr << "\nMa ISBN phai la nhung chu so 0-9 !";
			return false;
		}
	return true;
}
bool Flight::CheckFlightCode(const string &code)
{
	for (int i = 0; i < code.length(); ++i)
		if (code[i] > '9' || code[i] < '0')
		{
			cerr << "\nMa Sach phai la nhung chu so 0-9 !";
			return false;
		}
	return true;
}
bool Flight::IsVNFlight(const string &ISBN)
{
	if (CheckISBN(ISBN))
		if (ISBN.substr(3, 3) == ISBN_VN)
			return true;
	return false;
}

string Flight::FormatISBN() const
{
	string res = _ISBN;
	res.insert(3, "-");
	return res;
}
void Flight::Input()
{
	while (1)
	{
		cout << "\nMa hieu may bay: ";
		getline(cin, _maChuyenBay);
		if (!IsEmpty(_maChuyenBay))
			break;
	}
	while (1)
	{
		cout << "\nNhap loai may bay:";
		getline(cin, _noiDen);
		if (!IsEmpty(_noiDen))
			break;
	}
	while (1)
	{
		cout << "\nNhap so day: ";
		getline(cin, _noiDi);
		if (!IsEmpty(_noiDi))
			break;
	}
	while (1)
	{
		cout << "\nNhap so ghe: ";
		getline(cin, _code);
		if (!IsEmpty(_code))
			break;
		if (CheckFlightCode(_code))
			break;
	}
	while (1)
	{
		cout << "\nNhap ISBN-13: ";
		getline(cin, _ISBN);
		if (CheckISBN(_ISBN))
			break;
	}
	while (1)
	{
		cout << "\nNhap gia sach: ";
		cin >> _price;
		if (cin.fail())
		{
			cerr << "NaN - du lieu nhap phai la 1 so !";
			exit(0);
		}
		if (_price > 0)
			break;
		cerr << "\nGia sach phai lon hon 0 !";
	}
}
void Flight::Output()
{
	cout << "\nTen sach: " << _maChuyenBay;
	cout << "\nTac gia: " << _noiDen;
	cout << "\nNXB: " << _noiDi;
	cout << "\nMa sach: " << _code;
	cout << "\nISBN: " << FormatISBN();
	cout << "\nGia sach: " << setprecision(10) << _price;
}

void Flight::InputFile(ifstream &input)
{
	getline(input, _maChuyenBay);
	getline(input, _noiDen);
	getline(input, _noiDi);
	getline(input, _code);
	getline(input, _ISBN);
	input >> _price;
}
void Flight::OutputFile(ofstream &out)
{
	out << _maChuyenBay << endl;
	out << _noiDen << endl;
	out << _noiDi << endl;
	out << _code << endl;
	out << _ISBN << endl;
	out << _price << endl;
}

Flight &Flight::operator=(const Flight &Flight)
{
	_maChuyenBay = Flight._maChuyenBay;
	_noiDen = Flight._noiDen;
	_noiDi = Flight._noiDi;
	_code = Flight._code;
	_ISBN = Flight._ISBN;
	_price = Flight._price;
	return *this;
}

ostream &operator<<(ostream &os, const Flight &Flight)
{
	os << Flight._maChuyenBay << endl;
	os << Flight._noiDen << endl;
	os << Flight._noiDi << endl;
	os << Flight._code << endl;
	os << Flight._ISBN << endl;
	os << Flight._price << endl;
	return os;
}
