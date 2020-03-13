#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class files{ 
public:
	fstream objWrite, objRead;

	void write(string name, string order);
	void read();
};

