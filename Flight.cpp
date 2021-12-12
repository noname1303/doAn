#include "Flight.h"
#include <iomanip>
#include "Airport.h"
Flight::Flight()
{
	_maChuyenBay = "";
	_noiDen = "";
	_noiDi = "";
	_ISFC = "";
	_price = 0;
}
Flight::Flight(const Flight &Flight)
{
	_maChuyenBay = Flight._maChuyenBay;
	_noiDen = Flight._noiDen;
	_noiDi = Flight._noiDi;
	_ISFC = Flight._ISFC;
	_price = Flight._price;
	_ngayKhoiHanh = Flight._ngayKhoiHanh;
}
Flight::Flight(const string &maChuyenBay, const string &noiDen, const string &noiDi, const string &ISFC, double price)
{
	_maChuyenBay = maChuyenBay;
	_noiDen = noiDen;
	_noiDi = noiDi;
	_ISFC = ISFC;
	_price = _price < 0 ? 0 : _price;
}
Flight::~Flight()
{
}
string Flight::GetKey()
{
	return _ISFC;
}

string Flight::GetNoiDen() const
{
	return _noiDen;
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
string Flight::GetMaHieu() const
{
	return _maHieu;
}
double Flight::GetPrice() const
{
	return _price;
}
void Flight::SetKey(const string &ma)
{
	_maHieu = ma;
}
void Flight::SetMaChuyenBay(const string &maChuyenBay)
{
	if (!IsEmpty(maChuyenBay))
		_maChuyenBay = maChuyenBay;
}
void Flight::SetMaHieu(const string &maHieu)
{
	if (!IsEmpty(maHieu))
		_maHieu = maHieu;
}
void Flight::SetNoiDen(const string &noiDen)
{
	if (!IsEmpty(noiDen))
		_noiDen = noiDen;
}
void Flight::SetNoiDi(const string &noiDi)
{
	if (!IsEmpty(noiDi))
		_noiDi = noiDi;
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

	// Airport ap;
	// int found = ap.Search(1, 1);
	// if (found == NOT_FOUND)
	// {
	// 	cout << "\n========= KHONG TIM THAY TRONG DANH SACH  ==========" << endl;
	// 	return;
	// }
	// else
	// 	_maHieu = ap.GetPlane(found)->GetKey();

	while (1)
	{
		cout << "\nNhap ma chuyen bay: ";
		getline(cin, _maChuyenBay);
		if (!IsEmpty(_maChuyenBay))
			break;
	}

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
		cout << "\nNgay mua (dd/mm/yyyy): ";
		cin >> _ngayKhoiHanh;
		if (_ngayKhoiHanh.validityCheck_Fix())
			break;
		cout << "\nNgay nhap khong hop le !";
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
	// NAM
	TextColor(SHOW_COLOR);
	cout << "  |   " << setw(9) << left << _maHieu
		 << "|        " << setw(11) << _maChuyenBay
		 << "|     "
		 << setw(12) << _noiDen
		 << "|     "
		 << setw(11) << _noiDi

		 << "|  "
		 << setw(12) << FormatISFC()
		 << "|     " << _price << "$";
}

void Flight::InputFile(ifstream &input)
{
	getline(input, _maHieu);
	getline(input, _maChuyenBay);
	getline(input, _noiDen);
	getline(input, _noiDi);
	getline(input, _ISFC);
	input >> _price;
	// input >> _ngayKhoiHanh;
	// input.clear();
}
void Flight::OutputFile(ofstream &out)
{
	out << _maHieu << endl;
	out << _maChuyenBay << endl;
	out << _noiDen << endl;
	out << _noiDi << endl;
	out << _ISFC << endl;
	out << _price << endl;
	// out << _ngayKhoiHanh;
	out.clear();
}

Flight &Flight::operator=(const Flight &Flight)
{
	_maChuyenBay = Flight._maChuyenBay;
	_noiDen = Flight._noiDen;
	_noiDi = Flight._noiDi;
	_ISFC = Flight._ISFC;
	_price = Flight._price;
	return *this;
}

ostream &operator<<(ostream &os, const Flight &Flight)
{
	os << Flight._maChuyenBay << endl;
	os << Flight._noiDen << endl;
	os << Flight._noiDi << endl;
	os << Flight._ISFC << endl;
	os << Flight._price << endl;
	// os << Flight._ngayKhoiHanh << endl;
	return os;
}
