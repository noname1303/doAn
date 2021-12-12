#pragma once
#ifndef _AIRPORT_
#define _AIRPORT_
#include "Date.h"
#include "AirportSystem.h"
#include "Flight.h"
#include "Buyticket.h"
#include "Plane.h"
#include "Display.h"

class Airport
{
private:
	vector<AirportSystem *> _pl;
	vector<AirportSystem *> _fl;
	vector<AirportSystem *> _bt;

public:
	Airport();
	Airport(const Airport &pl, const Airport &fl, const Airport &bt);
	~Airport();

	AirportSystem *GetPlane(int pos) const;
	AirportSystem *GetFlight(int pos) const;
	AirportSystem *GetTicket(int pos) const;

	bool IsExist(int option, AirportSystem *as) const;
	void LoadDataFromFile(int option); // 0- may bay, 1-chuyen bay, 2-ve
	void OutputDataToFile(int option);
	void Add(int option);
	void Delete(int option);
	void Show(int option);
	int Search(int option, int type);
	void Edit(int option);
	void BuyTickets();
	void CancelTickets();
	void getDSMB();
	// void OverdueList();
};

#endif