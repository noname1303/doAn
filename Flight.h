#pragma once
#ifndef _FLIGHT_
#define _FLIGHT_
#include "AirportSystem.h"
#include "Date.h"
#include "Display.h"
class Flight : public AirportSystem
{
private:
	string _maHieu;
	string _maChuyenBay;
	string _noiDen;
	string _noiDi;
	string _ISFC;
	Date _ngayKhoiHanh;
	double _price;

public:
	Flight();
	Flight(const Flight &);
	Flight(const string &maChuyenBay, const string &noiDen, const string &noiDi, const string &ISFC, double price);
	~Flight();

	string GetMaChuyenBay() const;
	string GetMaHieu() const;
	string GetNoiDen() const;
	string GetNoiDi() const;
	string GetISFC() const;
	double GetPrice() const;

	void SetMaChuyenBay(const string &title);
	void SetMaHieu(const string &title);
	void SetNoiDen(const string &noiDen);
	void SetNoiDi(const string &pub);
	void SetISFC(const string &ISFC);
	void SetPrice(double price);

	static bool CheckFC(const string &ISFC);
	string GetKey();
	void SetKey(const string &);
	void Input();
	void Output();
	string FormatISFC() const;

	void InputFile(ifstream &input);
	void OutputFile(ofstream &path);

	Flight &operator=(const Flight &Flight);
	friend ostream &operator<<(ostream &os, const Flight &Flight);
};
#endif
