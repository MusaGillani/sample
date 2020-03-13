#include "queue.h"

void queue::enqueue(string name,string order)
{
	list* ptr = new list; // new node 
	files f;
	ptr->name = name;
	ptr->order = order;
	ptr->next = NULL;
	if (front == NULL) {
		front = ptr;
		rear = front;
		f.write(front->name,front->order);
	}
	else {
		rear->next = ptr;
		rear = rear->next; // rear = ptr
		f.write(rear->name, rear->order);
	}
}

void queue::dequeue()
{
	list* temp = new list; string name, order; files f; fstream tempf;
	if (front == NULL) {
		cout << "There is no data present " << endl;
	}
	else if (front == rear) {
		temp = front;
		front = NULL;
		rear = front;
		cout << temp->name << " order delivered" << endl;
		delete(temp);
		
		tempf.open("temp.txt",ios::out); // creating temporary file
		tempf.close(); 
		remove("orders.txt"); // removing old file having single order 
		rename("temp.txt", "orders.txt"); // renaming temp file order having no orders , empty file
	}
	else
	{
		temp = front;
		front = front->next;
		cout << temp->name << " order delivered" << endl;
		delete(temp);

		tempf.open("temp.txt",ios::out);
		f.objRead.open("orders.txt", ios::in);
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				getline(f.objRead, name); // store first name
			}
			else if (i == 1) {
				getline(f.objRead, order); // store first names order
			}
		}
		string line;
		// f.objRead.open("order.txt");

		while (!f.objRead.eof()) {
			getline(f.objRead, line);

			if (line == name || line == order) {
				continue;
			}
			else {
				tempf << line << endl;
			}
		}

		tempf.close();
		f.objRead.close();

		remove("orders.txt");
		rename("temp.txt", "orders.txt");
	}
}

void queue::display()
{
	/*for (list* ptr = front; ptr != NULL; ptr = ptr->next) {
		cout << "customer name: " << ptr->name << endl;
		cout << "customer order: " << ptr->order << endl << endl;
	}*/

	files f;
	f.read();
}

/* void queue::Delete(string del)
{
	list* temp = new list;
	if (front == NULL) {
		cout << endl << "There is no data to delete! " << endl;
	}
	else if(front == rear){
		temp = front;
		front = NULL;
		rear = front;
		delete(temp);
	}
	else {
		temp = front;
		front = front->next;
	}
} */
