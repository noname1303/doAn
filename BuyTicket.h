#pragma once
#ifndef _BUYTICKET_
#define _BUYTICKET_
#include "AirportSystem.h"
#include "Airport.h"
#include "Date.h"
class BuyTicket : public AirportSystem
{
private:
	string _MaISFC;
	string _GioiTinh;
	string _Ten;
	string _MaKhachHang;
	string _ID;
	Date date;

public:
	BuyTicket();
	BuyTicket(const string &, const string &, const string &);
	~BuyTicket();
	string GetGioiTinh() const;
	string GetMaISFC() const;
	string GetName() const;
	string GetUserCode() const;
	string GetID() const;
	string GetKey();
	void SetGioiTinh(const string &);
	void SetMaISFC(const string &);
	void SetName(const string &);
	void SetUserCode(const string &);
	void SetID(const string &);
	void SetDate(Date date);
	void SetKey(const string &);
	static bool CheckUserCode(const string &);
	static bool CheckID(const string &);

	void Input();
	void Output();
	string FormatUserCode() const;

	void InputFile(ifstream &input);
	void OutputFile(ofstream &path);

	BuyTicket &operator=(const BuyTicket &BuyTicket);
	friend ostream &operator<<(ostream &os, const BuyTicket &BuyTicket);
};
#endif
