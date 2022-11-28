#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(nullptr));

    string filename_items = "wizard_all_items.txt";
    string filename_inventory = "wizard_inventory.txt";

    // read all items from file
    vector<string> items;
    ifstream input_file;
    ofstream inv;
    input_file.open(filename_items);
    try {
        if (input_file) {
            string line;
            while (getline(input_file, line)) {
                items.push_back(line);
            }
            input_file.close();
        }
        else
			throw "File not found:`" + filename_items + "`";
    }
	catch (const char* msg) {
        inv.open(filename_inventory);
        input_file.open(filename_inventory);
		cout << "Error: " << msg << endl;
		cout << "Exiting program" << endl;
		return 1;
    }

    // read current inventory from file
    vector<string> inventory;
    input_file.open(filename_inventory);
    try {
        if (input_file) {
            string line;
            while (getline(input_file, line)) {
                inventory.push_back(line);
            }
            input_file.close();
        }
        else {
            throw "Error: could not open file `" + filename_inventory + "`";
        }
    }
    catch( const char* msg) {
        cout << msg << endl << "Wizard is starting with no inventory" << endl;
		
		
    }
    cout << "The Wizard Inventory program\n\n";

    cout << "COMMAND MENU\n"
        << "walk - Walk down the path\n"
        << "show - Show all items\n"
        << "drop - Drop an item\n"
        << "exit - Exit program\n";
	

    string command = "";
    while (command != "exit") {
        // get command from user
        cout << endl;
        cout << "Command: ";
        cin >> command;

        if (command == "walk") {
            int index = rand() % items.size() - 1;
            ++index;
            string item = items[index];

            cout << "While walking down a path, you see " + item + ".\n";

            char choice;
            cout << "Do you want to grab it? (y/n): ";
            while (true)
            {
                cin >> choice;
                try {
                    if (cin.fail()) {
                        throw "error";
                    }
                    else
                        break;
                }
                catch (char* error) {
                    cout << error << endl;
                    break;
                }
            }

            if (choice == 'y') {
                if (inventory.size() >= 4) {
                    cout << "You can't carry any more items. "
                        << "Drop something first.\n";
                }
                else {
                    inventory.push_back(item);
                    cout << "You picked up " + item + ".\n";
                }
            }
        }
        else if (command == "show") {
            int num = 0;
            for (string item : inventory) {
                cout << ++num << ". " << item << endl;
            }
        }
        else if (command == "drop") {
            int number;
            cout << "Number: ";
            cin >> number;

            if (number < 1 || number > inventory.size()) {
                cout << "Invalid item number.\n";
            }
            else {
                int index = number - 1;
                string item = inventory[index];
                inventory.erase(inventory.begin() + index);
                cout << "You dropped " + item + ".\n";
            }
        }
        else if (command == "exit") {
            cout << "Bye!\n\n";
        }
        else {
            cout << "Invalid command. Try again.\n";
        }
        ofstream output_file;
        output_file.open(filename_inventory);
        try {
            if (output_file) {
                string line;
                for (string item : inventory) {
                    output_file << item << '\n';
                }
                output_file.close();
            }
            else
                throw "Could not find file: wizard_inventory.txt";

        }
        catch (const char* msg) {
            cout << msg << endl;
            cout << "Wizard is starting with no inventory";

        }
    }
}
//int main()
//{
//	header h;
//	ifstream file2;
//	ofstream inv;
//	
//	try {
//		file2.open("wizard_inventory.txt");
//		cout << "Inventory opened" << endl;
//		inv.open("wizard_inventory.txt");
//	}
//	catch() {
//		cout << "Could not find file: wizard_inventory.txt" << endl;
//		cout << "Wizard is starting with no inventory" << endl;
//		inv.open("wizard_inventory.txt");
//	}
//
//	ifstream file;
//	file.open("wizard_all_items.txt");
//	if (file) {
//		
//	}
//	else {
//		cout << "Could not find file: wizard_all_items" << endl;
//		cout << "Exiting program. Bye!";
//		return 0;
//	}
//	vector<Item> items(9);
//	vector<Item> inventory(9);
//	string line;
//	string name;
//	stringstream ss;
//	int i = 0;
//	while (getline(file, line)) {
//		int id = i;
//		items[i].name = line;
//		items[i].id = id;
//		i++;
//	}
//
//	int itemcount = 0;
//	int command = 0;
//	while (command != 4) {
//		command = h.Commands();
//		if (command == 1) {
//			srand(time(NULL));
//			int randNum = rand() % 8 + 1;
//			cout << "while walking down a path you see a " << items[randNum].name << endl;
//			cout << "Do you want to pick it up? (y/n)" << endl;
//			char choice;
//			cin >> choice;
//			switch (choice) {
//			case 'y':
//					inv << items[randNum].name << endl;
//					itemcount++;
//					cout << "You picked up the " << items[randNum].name << endl;
//					cout << "You now have " << itemcount << " items" << endl;
//					inventory.push_back(items[randNum]);
//					break;
//			}
//		}
//		else if (command == 2) {
//			for (int i = 0; i < itemcount; i++) {
//				cout << items[i].name << endl;
//			}
//		}
//		else if (command == 3) {
//			cout << "Which item would you like to drop?" << endl;
//			string itemname;
//			cin >> itemname;
//			for (int i = 0; i < itemcount; i++) {
//				if (items[i].name == itemname) {
//					for (int j = i; j < itemcount; j++) {
//						items[j] = items[j + 1];
//					}
//					itemcount--;
//				}
//			}
//		}
//		else if (command == 4) {
//			cout << "You exit the program" << endl;
//		}
//		else {
//			cout << "Invalid Command" << endl;
//		}
//	}
//}
