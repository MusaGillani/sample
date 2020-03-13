#include "file.h"



void files::write(string name, string order)
{
	// creating and writing on file
	objWrite.open("orders.txt", ios::app);
	objWrite << "Name: " << name << endl;
	objWrite << "Order: " << order << endl;
	objWrite.close();

	system("pause");
}

void files::read()
{
	string name, line;

	objRead.open("orders.txt", ios::in);

	if (objRead.is_open()) {
		while (!objRead.eof()) {
			getline(objRead, line);
			cout << line << endl;
		}
	}
	else {
		cout << "file not found! " << endl;
	}

	objRead.close();
	system("pause");
}