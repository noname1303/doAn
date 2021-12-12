#include <windows.h>
#include <iostream>
#include "Display.h"
#include "Login.h"
#include <ctime>
#include "Date.h"
#include "srilakshmikanthanp/Figlet.hpp"
using namespace std;

using namespace srilakshmikanthanp;
// khoi tao 3 file data neu chua ton tai
void createDataFile()
{
	ofstream dataFile;
	dataFile.open(FLIGHT_DATA_PATH, ios::app);
	dataFile.close();
	dataFile.open(PLANES_DATA_PATH, ios::app);
	dataFile.close();
	dataFile.open(TICKET_DATA_PATH, ios::app);
	dataFile.close();
	dataFile.open(USER_DATA_PATH, ios::app);
	dataFile.close();
	dataFile.open(PASSWORD_DATA_PATH, ios::app);
	dataFile.close();
}
// void loading()
// {
// 	char a = 179, b = 219;

// 	cout << "\t\t\t"
// 		 << "Dang tai...\n";
// 	cout << "\t\t\t";
// 	for (int i = 0; i < 20; ++i)
// 	{
// 		cout << a;
// 	}
// 	cout << "\r";
// 	cout << "\t\t\t";
// 	for (int i = 0; i < 20; ++i)
// 	{
// 		cout << b;
// 		Sleep(100);
// 	}
// 	cout << "\n";
// }

int main()
{

	// // loading();
	// Sleep(200);
	try /// dung de bat cac ngoai le
	{
		createDataFile();
		Display display;
		display.MainLogin();
	}
	catch (const char *error) // chan bat và xử lí ngoại lệ
	{
		TextColor(4);
		cerr << "\n\t ====ERROR: " << error << " ====" << endl;
		TextColor(7);
		system("pause");
		return -1;
	}
	// Date d;
	// cin >> d;
	// cout << d;
}
