// menu file

//#include "file.h" /*classes */
#include "queue.h" // classes
#include<iostream>
#include<string>
//#include<fstream>

using namespace std;


int main() {

	queue q; // object of class queue included in header file queue.h

	while (true) {
		// system("pause");
		system("CLS");
		cout << endl;
		cout << "1.Enter order " << endl;
		cout << "2.display orders " << endl;
		cout << "3.deliver order" << endl;
		cout << "4.exit " << endl << endl;

		cout << "option: "; int option; cin >> option;

		if (option == 1) {
			// enter order
			int order; string name;
			cout << "enter name:"; cin >> name;
			cout << "1.Pizza " << endl << "2.Zinger" << endl;
			cout << "order: "; cin >> order;
			switch (order)
			{
			case 1:
				cout << "Order received: Pizza! " << endl;
				q.enqueue(name, "Pizza");
				system("pause");
				break;
			case 2:
				cout << "Order received: Pizza! " << endl;
				q.enqueue(name, "Zinger");
				system("pause");
				break;
			}
		}
		else if (option == 2) {
			// display order from files
			q.display();
		}
		else if (option == 3) {
			// deliver order
			q.dequeue();
		}
		else if (option == 4) {
			// exit program
			break;
		}
		else {
			cout << "invalid option selected " << endl;
		}
	}

	// code to check file working
	/* files f; int op;
	cin >> op;
	if (op == 1) {
		f.write("musa", "pizza");
	}
	else if (op == 2) {
	f.read();
	}*/
// changes 
	return 0;
}
