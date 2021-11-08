#pragma once
#ifndef _BUYTICKET_
#define _BUYTICKET_

#include "AirportSystem.h"
#include "Book.h"
#include "Users.h"
#include "Date.h"
class BuyTicket : public AirportSystem
{
private:
	Users _users;
	vector<Book> _book_list;
	Date _borrow_date;
	vector<Date> _book_return_date;
	vector<int> _returned;

public:
	BuyTicket();
	BuyTicket(const BuyTicket &bs);
	~BuyTicket();

	Users GetUsers() const;
	Date GetBorrowDate() const;
	vector<Date> GetBookReturnDate() const;
	int GetReturned(int pos) const;
	vector<int> GetReturned() const;
	vector<Book> GetBookList() const;

	void SetUsers(const Users &r);
	void SetBorrowDate(Date date);
	void SetBookReturnDate(int pos, Date date);
	void SetReturned(int pos, int returned);

	void Input();
	void Output();

	void InputFile(ifstream &input);
	void OutputFile(ofstream &path);
};
#endif
