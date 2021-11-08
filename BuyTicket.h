#pragma once
#ifndef _BUYTICKET_
#define _BUYTICKET_

#include "AirportSystem.h"
#include "Flight.h"
#include "Users.h"
#include "Date.h"
class BuyTicket : public AirportSystem
{
private:
	Users _users;
	vector<Flight> _Flight_list;
	Date _borrow_date;
	vector<Date> _Flight_return_date;
	vector<int> _returned;

public:
	BuyTicket();
	BuyTicket(const BuyTicket &bs);
	~BuyTicket();

	Users GetUsers() const;
	Date GetBorrowDate() const;
	vector<Date> GetFlightReturnDate() const;
	int GetReturned(int pos) const;
	vector<int> GetReturned() const;
	vector<Flight> GetFlightList() const;

	void SetUsers(const Users &r);
	void SetBorrowDate(Date date);
	void SetFlightReturnDate(int pos, Date date);
	void SetReturned(int pos, int returned);

	void Input();
	void Output();

	void InputFile(ifstream &input);
	void OutputFile(ofstream &path);
};
#endif
