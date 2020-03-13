#pragma once
#include "file.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;
struct list {
	string name,order;
	list* next;
};

class queue {
public:
	list* front; // head or first node 
	list* rear;

	queue() {
		this->front = NULL;
		this->rear = NULL;
	}

	void enqueue(string name,string order);
	void dequeue();
	void display();
//	void Delete(string del);
};

