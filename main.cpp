#include "Display.h"
#include "Login.h"
#include <iostream>
using namespace std;
#include "srilakshmikanthanp/Figlet.hpp"

using namespace srilakshmikanthanp;
//khoi tao 3 file data neu chua ton tai
void createDataFile()
{
	ofstream dataFile;
	dataFile.open(FLIGHT_DATA_PATH, ios::app);
	dataFile.close();
	dataFile.open(PLANES_DATA_PATH, ios::app);
	dataFile.close();
	dataFile.open(TICKET_DATA_PATH, ios::app);
	dataFile.close();
}

int main()
{
	try /// dung de bat cac ngoai le
	{
		createDataFile();

		Login app;
		int option;
		bool isLogin;
		system("cls");
		Figlet figlet(FigletFont::make("Fonts/Standard.flf"), Smushed::make());
		cout << figlet("Dang nhap / Dang ky");
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
	catch (const char *error) // chan bat và xử lí ngoại lệ
	{
		TextColor(4);
		cerr << "\n\t!== ERROR: " << error << " ==!" << endl;
		TextColor(7);
		system("pause");
		return -1;
	}
}
