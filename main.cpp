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
		Display display;
		display.MainLogin();
	}
	catch (const char *error) // chan bat và xử lí ngoại lệ
	{
		TextColor(4);
		cerr << "\n\t!== ERROR: " << error << " ==!" << endl;
		TextColor(7);
		system("pause");
		return -1;
	}
	//test
}
