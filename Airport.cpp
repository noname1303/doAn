#include <iostream>
#include "Airport.h"
#include "BuyTicket.h"
using namespace std;
Airport::Airport()
{
}

// Airport::Airport(const Airport &aport)
// {
// 	_pl = aport._pl;
// }
Airport::Airport(const Airport &pl, const Airport &fl, const Airport &bt)
{
	_pl = pl._pl;
	_fl = fl._fl;
	_bt = bt._bt;
}

Airport::~Airport()
{
}

AirportSystem *Airport::GetPlane(int pos) const
{
	if (pos < 0 || pos >= _pl.size())
		throw "Vi tri truy cap khong hop le";
	return _pl[pos];
}
AirportSystem *Airport::GetFlight(int pos) const
{
	if (pos < 0 || pos >= _fl.size())
		throw "Vi tri truy cap khong hop le";
	return _fl[pos];
}
AirportSystem *Airport::GetTicket(int pos) const
{
	if (pos < 0 || pos >= _bt.size())
		throw "Vi tri truy cap khong hop le";
	return _bt[pos];
}
void Airport::getDSMB()
{
	for (int i = 0; i < _pl.size(); ++i)
	{
		// cout << _pl[i];
		cout << "Chuyen bay " << ((Flight *)_pl[i])->GetMaChuyenBay() << endl;
		cout << "May bay " << ((Plane *)_fl[i])->GetMaHieu() << endl;
	}
}
bool Airport::IsExist(int option, AirportSystem *as) const
{
	switch (option)
	{
	case 0:
	{
		for (int i = 0; i < _fl.size(); ++i)
			if (((Flight *)as)->GetISFC() == ((Flight *)_fl[i])->GetISFC())
				return true;
	}
	case 1:
	{
		for (int i = 0; i < _pl.size(); ++i)
			if (((Plane *)as)->GetCodeMB() == ((Plane *)_pl[i])->GetCodeMB())
				return true;
	}
	case 2:
	{
		for (int i = 0; i < _pl.size(); ++i)
			if (((Plane *)as)->GetMaHieu() == ((Plane *)_pl[i])->GetMaHieu())
				return true;
	}
	default:
	{
		break;
	}
	}
	return false;
}

void Airport::LoadDataFromFile(int option)
{
	ifstream input;
	switch (option)
	{
	case 0:
	{
		input.open(FLIGHT_DATA_PATH);
		if (input.fail())
			throw "loi doc file";
		while (1)
		{
			AirportSystem *fl = NULL;
			fl = new Flight;
			if (!fl)
				throw "Loi cap phat";
			fl->InputFile(input);
			if (input.eof())
				break;
			_fl.push_back(fl);
			input.ignore();
		}
		break;
	}
	case 1:
	{
		input.open(PLANES_DATA_PATH);
		if (input.fail())
			throw "loi doc file";
		while (1)
		{
			AirportSystem *as = NULL;
			as = new Plane;
			if (!as)
				throw "Loi cap phat";
			as->InputFile(input);
			if (input.eof())
				break;
			_pl.push_back(as);
			input.ignore();
		}
		break;
	}
	default:
	{
		input.open(TICKET_DATA_PATH);
		if (input.fail())
			throw "loi doc file";
		while (1)
		{
			AirportSystem *bt = NULL;
			bt = new BuyTicket;
			if (!bt)
				throw "Loi cap phat";
			bt->InputFile(input);
			if (input.eof())
				break;
			_bt.push_back(bt);
			input.ignore();
		}
		break;
	}
	}
	input.close();
}

void Airport::OutputDataToFile(int option)
{
	ofstream out;
	switch (option)
	{
	case 0:
	{
		out.open(FLIGHT_DATA_PATH, ios::out);
		if (out.fail())
			throw "Loi doc file";
		for (int i = 0; i < _fl.size(); ++i) // fix
			_fl[i]->OutputFile(out);
		break;
	}
	case 1:
	{
		out.open(PLANES_DATA_PATH, ios::out);
		if (out.fail())
			throw "Loi doc file";
		for (int i = 0; i < _pl.size(); ++i)
			_pl[i]->OutputFile(out);
		break;
	}
	default:
	{
		out.open(TICKET_DATA_PATH, ios::out);
		if (out.fail())
			throw "Loi doc file";
		for (int i = 0; i < _bt.size(); ++i)
			_bt[i]->OutputFile(out);
		break;
	}
	}
	// if (out.fail())
	// 	throw "Loi doc file";
	// for (int i = 0; i < _pl.size(); ++i)
	// 	_pl[i]->OutputFile(out);
	out.close();
}

void Airport::Show(int option)
{
	LoadDataFromFile(option);
	vector<AirportSystem *> tmp;

	if (option == 0)
		tmp = _fl;
	else if (option == 1)
		tmp = _pl;
	else
		tmp = _bt;
	for (int i = 0; i < tmp.size(); ++i)
	{
		TextColor(SHOW_COLOR);
		cout << "\n " << i + 1; // NAM
		TextColor(7);
		tmp[i]->Output();
	}
}

void Airport::Add(int option)
{
	LoadDataFromFile(option);
	ofstream output;
	switch (option)
	{
	case 0:
	{

		output.open(FLIGHT_DATA_PATH, ios::app);
		if (output.fail())
			throw "Loi doc file";
		AirportSystem *flight = new Flight;
		if (flight == NULL)
			throw "Khong the cap phat bo nho";
		int found = Search(1, 1);
		if (found == NOT_FOUND)
		{
			TextColor(12);
			cout << "\n========= KHONG TIM THAY TRONG DANH SACH  ==========" << endl;
			return;
		}
		string maChuyenBay = GetPlane(found)->GetKey();

		flight->Input();
		if (!IsExist(option, flight))
		{

			flight->SetKey(maChuyenBay);
			flight->OutputFile(output);
			output.close();
		}
		else
			cout << "\n bay da ton tai trong database !";

		break;
	}
	case 1:
	{
		output.open(PLANES_DATA_PATH, ios::app);
		if (output.fail())
			throw "Loi doc file";
		Plane *planes = new Plane;
		if (planes == NULL)
			throw "Khong the cap phat bo nho";

		fflush(stdin);
		planes->Input();
		if (!IsExist(option, planes) && !IsExist(option + 1, planes))
			planes->OutputFile(output);
		else
			cout << "\nMay bay da da ton tai  !";
		break;
	}
	case 2:
	{

		output.open(TICKET_DATA_PATH, ios::app);
		if (output.fail())
			throw "Loi doc file";
		BuyTicket *bt = new BuyTicket;
		if (bt == NULL)
			throw "Khong the cap phat bo nho";
		fflush(stdin);

		int found = Search(0, 1);
		if (found == NOT_FOUND)
		{
			TextColor(12);
			cout << "\n========= KHONG TIM THAY TRONG DANH SACH  ==========" << endl;
			return;
		}
		string MaISFC = GetFlight(found)->GetKey();
		bt->Input();
		for (int i = 0; i < _pl.size(); ++i)
			if (((BuyTicket *)bt)->GetUserCode() == ((BuyTicket *)_pl[i])->GetUserCode())
			{
				if (((BuyTicket *)bt)->GetUserCode() == ((BuyTicket *)_pl[i])->GetUserCode())
				{
					bt->SetKey(MaISFC);

					bt->OutputFile(output);
				}
				else
					cerr << "\n=== ERROR: Trung ID nhung khac thong tin ===" << endl;
				output.close();
				return;
			}
		if (!IsExist(option, bt))
		{
			bt->SetKey(MaISFC);

			bt->OutputFile(output);
		}
		else
			cout << "\nVe ton tai  !";
		break;
	}
	}
}
void Airport::Delete(int option)
{
	int found;
	char confirm[4];
	switch (option)
	{
	case 0:
	{
		found = Search(option, 0);
		if (found == NOT_FOUND)
		{
			TextColor(12);
			cout << "\n========= KHONG TIM THAY TRONG DANH SACH  ==========" << endl;
			return;
		}
		while (1)
		{
			cout << "\nNhan \"yes\" de xac nhan xoa chuyen bay may bay nay: ";
			cin >> confirm;

			if (strcmp(confirm, "yes") == 0)
			{

				_fl.erase(_fl.begin() + found);
				cout << "\n========= XOA THANH CONG ==========" << endl;
				break;
			}
			else
				return;
		}
	}
	break;
	case 1:
	{
		found = Search(option, 1);
		if (found == NOT_FOUND)
		{
			TextColor(12);
			cout << "\n========= KHONG TIM THAY TRONG DANH SACH  ==========" << endl;
			return;
		}
		while (1)
		{
			cout << "\nNhan \"yes\" de xac nhan xoa may bay nay: ";
			cin >> confirm;

			if (strcmp(confirm, "yes") == 0)
			{

				_pl.erase(_pl.begin() + found);
				cout << "\n========= XOA THANH CONG ==========" << endl;
				break;
			}
			else
				return;
		}
	}
	break;
	case 2:
	{
		found = Search(option, 0);
		if (found == NOT_FOUND)
		{
			TextColor(12);
			cout << "\n========= KHONG TIM THAY TRONG DANH SACH  ==========" << endl;
			return;
		}
		while (1)
		{
			cout << "\nNhan \"yes\" de xac nhan huy ve may bay nay: ";
			cin >> confirm;

			if (strcmp(confirm, "yes") == 0)
			{

				_bt.erase(_bt.begin() + found);
				cout << "\n========= XOA THANH CONG ==========" << endl;
				break;
			}
			else
				return;
		}
		break;
	}
	}
	OutputDataToFile(option);
}

int Airport::Search(int option, int type)
{

	LoadDataFromFile(option);

	switch (option)
	{
	case 0:
	{
		switch (type)
		{
		case 0:
		{
			// search by title
			TextColor(13);
			vekhung(0, 2, 1, 25);
			gotoxy(2, 3);
			cout << "Nhap ma chuyen bay: " << setfill(' ');
			string maChuyenBay;
			fflush(stdin);
			getline(cin, maChuyenBay);
			for (int i = 0; i < _fl.size(); i++)
				if (ToLower(((Flight *)_fl[i])->GetMaChuyenBay()) == ToLower(maChuyenBay))
					return i;
			return NOT_FOUND;
		}

		case 1:
		{
			// search by ISFC
			string ISFC;
			fflush(stdin);
			while (1)
			{
				TextColor(13);
				vekhung(0, 2, 1, 27);
				gotoxy(2, 3);
				cout << "Nhap ma ISFC-9: " << setfill(' ');
				getline(cin, ISFC);
				if (Flight::CheckFC(ISFC))
					break;
			}
			for (int i = 0; i < _fl.size(); ++i)
				if (ToLower(((Flight *)_fl[i])->GetISFC()) == ToLower(ISFC))
					return i;
			return NOT_FOUND;
		}
		}
	}
	case 1:
	{
		switch (type)
		{
		case 0:
		{
			// search by name
			TextColor(13);
			vekhung(0, 2, 1, 30);
			gotoxy(2, 3);
			cout << "Nhap loai may bay: " << setfill(' ');
			string name;
			fflush(stdin);
			getline(cin, name);
			for (int i = 0; i < _pl.size(); ++i)
				if (ToLower(((Plane *)_pl[i])->GetLoaiMB()) == ToLower(name))
					return i;
			return NOT_FOUND;
		}
		case 1:
		{
			// search by ID
			TextColor(13);
			vekhung(0, 2, 1, 21);
			gotoxy(2, 3);
			cout << "Nhap ma hieu: " << setfill(' ');
			string maHieu;
			fflush(stdin);
			getline(cin, maHieu);
			for (int i = 0; i < _pl.size(); ++i)
				if (ToLower(((Plane *)_pl[i])->GetMaHieu()) == ToLower(maHieu))
					return i;
			return NOT_FOUND;
		}
		default:
			cout << "Vui long nhap lai";
			break;
		}
	}
	default:
	{
		TextColor(13);
		vekhung(0, 2, 1, 42);
		gotoxy(2, 3);
		cout << "Nhap CMND: " << setfill(' ');
		string cmnd;
		getline(cin, cmnd);
		for (int i = 0; i < _bt.size(); ++i)
		{
			string r_cmnd = ((BuyTicket *)_bt[i])->GetID();
			if (ToLower(r_cmnd) == ToLower(cmnd))
				return i;
		}
		return NOT_FOUND;
	}
	}
}
void Airport::Edit(int option)
{
	int found = Search(option, 0);
	if (found == NOT_FOUND)
	{
		TextColor(12);
		cout << "\n========= KHONG TIM THAY TRONG DANH SACH  ==========" << endl;
		return;
	}
	int type;
	switch (option)
	{
	case 0:
	{
		TextColor(SHOW_COLOR);
		cout << setw(61) << right << "========== TIM THAY ==========" << endl;
		cout << "  |   Ma hieu  |   Ma chuyen bay   |     Noi den     |     Noi di     |     IFSC     |     Gia ve" << endl;
		cout << "=======================================================================================================" << endl;
		_fl[found]->Output();
		TextColor(13);
		cout << "\n0-Sua Tat Ca, 1-Ma chuyen bay, 2-Noi Den, 3-Noi Di, 4-ISFC, >> ";
		cin >> type;
		if (cin.fail())
			throw "Du lieu nhap khong la so";
		fflush(stdin);
		TextColor(13);
		switch (type)
		{
		case 0:
		{
			cout << "\n\t===== Nhap thong tin can chinh sua =====" << endl;
			_fl[found]->Input();
			break;
		}
		case 1:
		{
			cout << "\n\t===== Nhap thong tin can chinh sua =====" << endl;
			cout << "Nhap ma chuyen bay: ";
			string MaChuyenBay;
			getline(cin, MaChuyenBay);
			((Flight *)_fl[found])->SetMaChuyenBay(MaChuyenBay);
			break;
		}
		case 2:
		{
			cout << "\n\t===== Nhap thong tin can chinh sua =====" << endl;
			cout << "Nhap noi den: ";
			string NoiDen;
			getline(cin, NoiDen);
			((Flight *)_fl[found])->SetNoiDen(NoiDen);
			break;
		}
		case 3:
		{
			cout << "\n\t===== Nhap thong tin can chinh sua =====" << endl;
			cout << "Nhap noi di: ";
			string NoiDi;
			getline(cin, NoiDi);
			((Flight *)_fl[found])->SetNoiDi(NoiDi);
			break;
		}

		case 4:
		{
			cout << "\n\t===== Nhap thong tin can chinh sua =====" << endl;
			string ISFC;
			while (1)
			{
				cout << "Nhap ISFC: ";
				getline(cin, ISFC);
				if (Flight::CheckFC(ISFC))
					break;
			}
			((Flight *)_fl[found])->SetISFC(ISFC);
			break;
		}
		default:
		{
			cout << "Vui long lua chon dung!!";
			break;
		}
		}
		break;
	}
	case 1:
	{
		TextColor(SHOW_COLOR);
		cout << setw(60) << right << "========== TIM THAY ==========" << endl;
		cout << "  |     Ma hieu     |     Loai     |     Code     |     So day     |     So ghe     |     So ve" << endl;
		cout << "===============================================================================================" << endl;
		_pl[found]->Output();
		TextColor(3);
		cout << "\n0-Sua Tat Ca, 1-Ma Hieu, 2-Loai, 3-Code MB, 4-So Day, 5-So Ghe >> ";
		cin >> type;
		if (cin.fail())
			throw "Du lieu nhap khong la so";
		fflush(stdin);
		TextColor(11);
		switch (type)
		{
		case 0:
		{
			cout << "\n\t===== Nhap thong tin can chinh sua =====" << endl;
			_pl[found]->Input();
			break;
		}
		case 1:
		{
			cout << "\n\t===== Nhap thong tin can chinh sua =====" << endl;
			cout << "Nhap ma hieu may bay: ";
			string name;
			getline(cin, name);
			((Plane *)_pl[found])->SetMaHieu(name);
			break;
		}
		case 2:
		{
			cout << "\n\t===== Nhap thong tin can chinh sua =====" << endl;
			cout << "Nhap loai may bay: ";
			string loai;
			getline(cin, loai);
			((Plane *)_pl[found])->SetLoaiMB(loai);
			break;
		}

		case 3:
		{
			cout << "\n\t===== Nhap thong tin can chinh sua =====" << endl;
			string Code;
			while (1)
			{
				cout << "Nhap loai may: ";
				getline(cin, Code);
				if (Plane::CheckCode(Code))
					break;
			}
			((Plane *)_pl[found])->SetCodeMB(Code);
			break;
		}
		}
		break;
	}
	}
	OutputDataToFile(option);
}

void Airport::BuyTickets()
{
	this->Add(2);
}
void Airport::CancelTickets()
{
	this->Delete(2);
}
