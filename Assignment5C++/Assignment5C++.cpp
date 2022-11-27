// Assignment5C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "main.h"

using namespace std;

struct Item {
	string name;
	int id;
};


int main()
{
	header h;

	Item items[10];
	int itemcount = 0;
	int command = 0;
	while (command != 4) {
		command = h.Commands();
		if (command == 1) {
			cout << "You walk down the path" << endl;
		}
		else if (command == 2) {
			for (int i = 0; i < itemcount; i++) {
				cout << items[i].name << endl;
			}
		}
		else if (command == 3) {
			cout << "Which item would you like to drop?" << endl;
			string itemname;
			cin >> itemname;
			for (int i = 0; i < itemcount; i++) {
				if (items[i].name == itemname) {
					for (int j = i; j < itemcount; j++) {
						items[j] = items[j + 1];
					}
					itemcount--;
				}
			}
		}
		else if (command == 4) {
			cout << "You exit the program" << endl;
		}
		else {
			cout << "Invalid Command" << endl;
		}
	}
}
