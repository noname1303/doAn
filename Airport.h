#pragma once
#ifndef _AIRPORT_
#define _AIRPORT_
#include "Date.h"
#include "AirportSystem.h"
#include "Book.h"
#include "BuyTicket.h"
#include "Users.h"
#include "Display.h"

class Airport
{
private:
	vector<AirportSystem *> _ls;

public:
	Airport();
	Airport(const Airport &aport);
	~Airport();

	AirportSystem *GetAirportSystem(int pos) const;

	bool IsExist(int option, AirportSystem *ls) const;
	void LoadDataFromFile(int option); //0- may bay, 1-chuyen bay, 2-ve
	void OutputDataToFile(int option);
	void Add(int option);
	void Delete(int option);
	void Show(int option);
	int Search(int option, int type);
	void Edit(int option);
	void MuaVe();
	void HuyVe();
	void OverdueList();
};

#endif