#include "Display.h"
#include "Login.h"
#include <iostream>
using namespace std;
//khoi tao 3 file data neu chua ton tai
void createDataFile()
{
	ofstream dataFile;
	dataFile.open(BOOKS_DATA_PATH, ios::app);
	dataFile.close();
	dataFile.open(READERS_DATA_PATH, ios::app);
	dataFile.close();
	dataFile.open(BORROWEDSLIP_DATA_PATH, ios::app);
	dataFile.close();
}

int main()
{
	try
	{
		createDataFile();

		Login app;
		int option;
		bool isLogin;
		system("cls");
		cout << "Nhap lua chon" << endl;
		cout << "1.Dang ky" << endl;
		cout << "2.Dang nhap" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
		{
			app.dangKi();
			break;
		}

		case 2:
		{
			isLogin = app.dangNhap();
			break;
		}
		}
		TextColor(7);
		system("pause");
		return 0;
	}
	catch (const char *error)
	{
		TextColor(4);
		cerr << "\n\t!== ERROR: " << error << " ==!" << endl;
		TextColor(7);
		system("pause");
		return -1;
	}
}