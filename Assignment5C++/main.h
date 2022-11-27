namespace std
{
	class header
	{
	public:
		int Commands() {
			cout << "COMMAND MENU " << endl;
			cout << "Walk - Walk down the path" << endl;
			cout << "Show - Show all items" << endl;
			cout << "Drop - Drop an Item" << endl;
			cout << "Exit - Exit Program" << endl;
			
			string command;
			cin >> command;
			if (command == "Walk") {
				return 1;
			}
			else if (command == "Show") {
				return 2;
			}
			else if (command == "Drop") {
				return 3;
			}
			else if (command == "Exit") {
				return 4;
			}
			else {
				cout << "Invalid Command" << endl;
				return 0;
			}
			
		}

	};
}