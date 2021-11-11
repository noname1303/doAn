#pragma once
#ifndef _BUYTICKET_
#define _BUYTICKET_

#include "AirportSystem.h"
#include "Flight.h"
#include "Plane.h"
#include "Date.h"
class BuyTicket : public AirportSystem
{
private:
	Plane _planes;
	vector<Flight> _Flight_list;
	Date _borrow_date;
	vector<Date> _Flight_return_date;
	vector<int> _returned;

public:
	BuyTicket();
	BuyTicket(const BuyTicket &bt);
	~BuyTicket();

	Plane GetPlane() const;
	Date GetBorrowDate() const;
	vector<Date> GetFlightReturnDate() const;
	int GetReturned(int pos) const;
	vector<int> GetReturned() const;
	vector<Flight> GetFlightList() const;

	void SetPlane(const Plane &r);
	void SetBorrowDate(Date date);
	void SetFlightReturnDate(int pos, Date date);
	void SetReturned(int pos, int returned);

	void Input();
	void Output();

	void InputFile(ifstream &input);
	void OutputFile(ofstream &path);
};
#endif
