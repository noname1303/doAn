#include "Flight.h"
Flight::Flight()
{
	// _maChuyenBay = "";
	_code = "";
	_noiDen = "";
	_noiDi = "";
	_ISFC = "";
	_price = 0;
}
Flight::Flight(const Flight &Flight)
{
	// _maChuyenBay = Flight._maChuyenBay;
	_noiDen = Flight._noiDen;
	_noiDi = Flight._noiDi;
	_code = Flight._code;
	_ISFC = Flight._ISFC;
	_price = Flight._price;
}
Flight::Flight(const string &name, const string &noiDen, const string &noiDi, const string &code, const string &ISFC, double price)
{
	// _maChuyenBay = name;
	_noiDen = noiDen;
	_noiDi = noiDi;
	_code = name;
	_ISFC = ISFC;
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
string Flight::GetISFC() const
{
	return _ISFC;
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
void Flight::SetISFC(const string &ISFC)
{
	if (CheckFC(ISFC))
		_ISFC = ISFC;
}
void Flight::SetPrice(double price)
{
	if (price > 0)
		_price = price;
}

bool Flight::CheckFC(const string &ISFC)
{
	if (IsEmpty(ISFC))
		return false;

	if (ISFC.length() != 9)
	{
		cerr << "\nMa ISFC gom 9 ki tu!";
		return false;
	}
	string check;
	check = check + ISFC[0] + ISFC[1] + ISFC[2];
	if (check != FLIGHT_CODE_9 && check != _FLIGHT_CODE_9)
	{
		cerr << "\nMa ISFC-9 bat dau bang VJA hoac VNA !";
		return false;
	}
	return true;
}
bool Flight::CheckFlightCode(const string &code)
{
	for (int i = 0; i < code.length(); ++i)
		if (code[i] > '9' || code[i] < '0')
		{
			cerr << "\nMa chuyen bay phai la nhung chu so 0-9 !";
			return false;
		}
	return true;
}
// bool Flight::IsVNFlight(const string &ISFC)
// {
// 	if (CheckFC(ISFC))
// 		if (ISFC.substr(3, 3) == ISFC_VN)
// 			return true;
// 	return false;
// }

string Flight::FormatISFC() const
{
	string res = _ISFC;
	res.insert(3, "-");
	return res;
}
void Flight::Input()
{
	while (1)
	{
		cout << "\nNhap ma chuyen bay: ";
		getline(cin, _code);
		if (!IsEmpty(_code))
			break;
		if (CheckFlightCode(_code))
			break;
	}
	// while (1)
	// {
	// 	cout << "\nMa hieu may bay: ";
	// 	getline(cin, _maChuyenBay);
	// 	if (!IsEmpty(_maChuyenBay))
	// 		break;
	// }
	while (1)
	{
		cout << "\nNhap noi den:";
		getline(cin, _noiDen);
		if (!IsEmpty(_noiDen))
			break;
	}
	while (1)
	{
		cout << "\nNhap noi di: ";
		getline(cin, _noiDi);
		if (!IsEmpty(_noiDi))
			break;
	}

	while (1)
	{
		cout << "\nNhap ISFC-9: ";
		getline(cin, _ISFC);
		if (CheckFC(_ISFC))
			break;
	}
	while (1)
	{
		cout << "\nNhap gia ve: ";
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
	cout << "\nMa Chuyen Bay: " << _code;
	cout << "\nNoi den: " << _noiDen;
	cout << "\nNoi di: " << _noiDi;
	// cout << "\nCode: " << _code;
	cout << "\nISFC: " << FormatISFC();
	cout << "\nGia ve: " << setprecision(10) << _price;
}

void Flight::InputFile(ifstream &input)
{
	// getline(input, _maChuyenBay);
	getline(input, _noiDen);
	getline(input, _noiDi);
	getline(input, _code);
	getline(input, _ISFC);
	input >> _price;
}
void Flight::OutputFile(ofstream &out)
{
	// out << _maChuyenBay << endl;
	out << _noiDen << endl;
	out << _noiDi << endl;
	out << _code << endl;
	out << _ISFC << endl;
	out << _price << endl;
}

Flight &Flight::operator=(const Flight &Flight)
{
	// _maChuyenBay = Flight._maChuyenBay;
	_noiDen = Flight._noiDen;
	_noiDi = Flight._noiDi;
	_code = Flight._code;
	_ISFC = Flight._ISFC;
	_price = Flight._price;
	return *this;
}

ostream &operator<<(ostream &os, const Flight &Flight)
{
	// os << Flight._maChuyenBay << endl;
	os << Flight._noiDen << endl;
	os << Flight._noiDi << endl;
	os << Flight._code << endl;
	os << Flight._ISFC << endl;
	os << Flight._price << endl;
	return os;
}
