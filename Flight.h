#pragma once
#ifndef _FLIGHT_
#define _FLIGHT_
#include "AirportSystem.h"

class Flight : public AirportSystem
{
private:
	string _maChuyenBay;
	string _noiDen;
	string _noiDi;
	string _code;
	string _ISFC;
	double _price;

public:
	Flight();
	Flight(const Flight &Flight);
	Flight(const string &name, const string &noiDen, const string &noiDi, const string &code, const string &ISFC, double price);
	~Flight();

	string GetMaChuyenBay() const;
	string GetNoiDen() const;
	string GetNoiDi() const;
	string GetCode() const;
	string GetISFC() const;
	double GetPrice() const;

	void SetTitle(const string &title);
	void SetAuthor(const string &noiDen);
	void SetPublisher(const string &pub);
	void SetCode(const string &code);
	void SetISFC(const string &ISFC);
	void SetPrice(double price);

	static bool CheckFC(const string &ISFC);
	static bool CheckFlightCode(const string &code);
	static bool IsVNFlight(const string &ISFC);

	void Input();
	void Output();
	string FormatISFC() const;

	void InputFile(ifstream &input);
	void OutputFile(ofstream &path);

	Flight &operator=(const Flight &Flight);
	friend ostream &operator<<(ostream &os, const Flight &Flight);
};
#endif
