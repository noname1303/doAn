#include "Flight.h"
Flight::Flight() {
	_title = "";
	_author = "";
	_publisher = "";
	_ISBN = "";
	_price = 0;
}
Flight::Flight(const Flight& Flight) {
	_title = Flight._title;
	_author = Flight._author;
	_publisher = Flight._publisher;
	_code = Flight._code;
	_ISBN = Flight._ISBN;
	_price = Flight._price;
}
Flight::Flight(const string& name, const string& author, const string& publisher, const string& code, const string& ISBN, double price) {
	_title = name;
	_author = author;
	_publisher = publisher;
	_code = code;
	_ISBN = ISBN;
	if (price < 0)
		_price = 0;
	else
		_price = price;
}
Flight::~Flight() {

}

string Flight::GetAuthor() const {
	return _author;
}
string Flight::GetCode() const {
	return _code;
}
string Flight::GetISBN() const {
	return _ISBN;
}
string Flight::GetPublisher() const {
	return _publisher;
}
string Flight::GetTitle() const {
	return _title;
}
double Flight::GetPrice() const {
	return _price;
}

void Flight::SetTitle(const string& title) {
	if (!IsEmpty(title))
		_title = title;
}
void Flight::SetAuthor(const string& author) {
	if (!IsEmpty(author))
		_author = author;
}
void Flight::SetPublisher(const string& pub) {
	if (!IsEmpty(pub)) 
		_publisher = pub;
}
void Flight::SetCode(const string& code) {
	if (CheckFlightCode(code))
		_code = code;
}
void Flight::SetISBN(const string& ISBN) {
	if (CheckISBN(ISBN))
		_ISBN = ISBN;
}
void Flight::SetPrice(double price) {
	if (price > 0)
		_price = price;
}

bool Flight::CheckISBN(const string& ISBN) {
	if (IsEmpty(ISBN))
		return false;

	if (ISBN.length() != 13) {
		cerr << "\nMa ISBN gom 13 chu so !";
		return false;
	}
	string check;
	check = check + ISBN[0] + ISBN[1] + ISBN[2];
	if (check != _EAN_13 && check != EAN_13) {
		cerr << "\nMa ISBN-13 bat dau bang 978 hoac 979 !";
		return false;
	}
	for (int i = 0; i < ISBN.length(); ++i)
		if (ISBN[i] > '9' || ISBN[i] < '0') {
			cerr << "\nMa ISBN phai la nhung chu so 0-9 !";
			return false;
		}
	return true;
}
bool Flight::CheckFlightCode(const string& code) {
	for (int i = 0; i < code.length(); ++i)
		if (code[i] > '9' || code[i] < '0') {
			cerr << "\nMa Sach phai la nhung chu so 0-9 !";
			return false;
		}
	return true;
}
bool Flight::IsVNFlight(const string& ISBN) {
	if (CheckISBN(ISBN)) 	
		if (ISBN.substr(3, 3) == ISBN_VN)
			return true;
	return false;
}

string Flight::FormatISBN() const {
	string res = _ISBN;
	res.insert(3, "-");
	return res;
}
void Flight::Input() {
	while (1) {
		cout << "\nMa hieu may bay: ";
		getline(cin, _title);
		if (!IsEmpty(_title))
			break;
	}
	while (1) {
		cout << "\nNhap loai may bay:";
		getline(cin, _author);
		if (!IsEmpty(_author))
			break;
	}
	while (1) {
		cout << "\nNhap so day: ";
		getline(cin, _publisher);
		if (!IsEmpty(_publisher))
			break;
	}
	while (1) {
		cout << "\nNhap so ghe: ";
		getline(cin, _code);
		if (!IsEmpty(_code))
			break;
		if (CheckFlightCode(_code))
			break;
	}
	while (1) {
		cout << "\nNhap ISBN-13: ";
		getline(cin, _ISBN);
		if (CheckISBN(_ISBN))
			break;
	}
	while(1){
		cout << "\nNhap gia sach: ";
		cin >> _price;
		if (cin.fail()) {
			cerr << "NaN - du lieu nhap phai la 1 so !";
			exit(0);
		}	
		if (_price > 0)
			break;
		cerr << "\nGia sach phai lon hon 0 !";		
	} 
}
void Flight::Output() {
	cout << "\nTen sach: " << _title;
	cout << "\nTac gia: " << _author;
	cout << "\nNXB: " << _publisher;
	cout << "\nMa sach: " << _code;
	cout << "\nISBN: " << FormatISBN();
	cout << "\nGia sach: " << setprecision(10) << _price;
}

void Flight::InputFile(ifstream& input) {
	getline(input, _title);
	getline(input, _author);
	getline(input, _publisher);
	getline(input, _code);
	getline(input, _ISBN);
	input >> _price;
}
void Flight::OutputFile(ofstream& out){
	out << _title << endl;
	out << _author << endl;
	out << _publisher << endl;
	out << _code << endl;
	out << _ISBN << endl;
	out << _price << endl;
}

Flight& Flight::operator= (const Flight& Flight) {
	_title = Flight._title;
	_author = Flight._author;
	_publisher = Flight._publisher;
	_code = Flight._code;
	_ISBN = Flight._ISBN;
	_price = Flight._price;
	return *this;
}

ostream& operator<< (ostream& os, const Flight& Flight) {
	os << Flight._title << endl;
	os << Flight._author << endl;
	os << Flight._publisher << endl;
	os << Flight._code << endl;
	os << Flight._ISBN << endl;
	os << Flight._price << endl;
	return os;
}
