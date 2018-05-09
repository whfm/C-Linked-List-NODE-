#include "Header Files\Header.h"

using namespace std;


int main() {
	list obj;

	int choice = 0;
	string search;
	string cid;
	int value, dday, dmonth, dyear;
	string fname, lname, assn;


	do {
		/*Switch case for the main menu*/
		switch (main_menu()) {
			/*Case 1, enter a new employee*/
		case 1:
			system("cls");
			cout << "1 - Entering a new employee\n\n";
			cout << "Please enter the employee ID: ";
			cin >> value;
			cout << "Please enter the employee first name: ";
			cin.ignore();
			getline(cin, fname);
			cout << "Please enter the employee last name: ";
			getline(cin, lname);
			cout << "Please enter the employee social security number: ";
			getline(cin, assn);
			cout << "Please enter the employee social hired day: ";
			cin >> dday;
			cout << "Please enter the employee social hired month: ";
			cin >> dmonth;
			cout << "Please enter the employee social hired year: ";
			cin >> dyear;

			obj.createNode(value, fname, lname, assn, dday, dmonth, dyear);
			cout << "\nPress any key to go back to the main menu";
			system("pause>>null");
			break;
		case 2:
			/*Case 2, delete employee*/
			switch (menu_delete()) {
			case 1:
				obj.delete_first();
				cout << "\nThe first employee of the list was deleted!";
				break;
			case 2: 
				obj.delete_last();
				cout << "\nThe last employee of the list was deleted!";
				break;
			case 3:
				cout << "\nPress any key to go back to the main menu";
				system("Pause>>null");
				break;
			default:
				break;
			}

			system("Pause>>null");
			break;
		case 3: {
			/*Case 3, searching through the contact array*/
			switch (menu_search()) {
				case 1: {
					/*Search by contact id*/
					cout << "Enter the 'Employee ID' to search: ";
					cin >> cid;
					obj.search_int(cid);
					cout << "\nPress any key to go back to the main menu";
					system("Pause>>null");
					break;
				}
				case 2: {
					/*Search by first name*/
					cin.ignore();
					cout << "Enter the 'First Name' or 'Last Name' to search: ";
					getline(cin, search);
					obj.search_int(search);
					cout << "\nPress any key to go back to the main menu";
					system("Pause>>null");
					break;
				}
				case 3:
					cout << "\nPress any key to go back to the main menu";
					system("Pause>>null");
					break;
				default:
					break;
			}
			break;
		}
		case 4: {
			//Display all employees
			cout << "\nDisplaying all the employees: ";
			obj.display();
			cout << "\nPress any key to go back to the main menu";
			system("pause>>null");
			break;
		}
		case 5: {
			/*Sorting the contact array*/
			switch (menu_sort()) {
			case 1: {
				/*Sort employees by employee id*/
				cout << "\nEmployees sorted by ID";
				obj.sortID();
				cout << "\nPress any key to go back to the main menu";
				system("Pause>>null");
				break;
			}
			case 2: {
				/*Sort employee by employee first name*/
				cout << "\Employees sorted by First Name";
				obj.sortFname();
				cout << "\nPress any key to go back to the main menu";
				system("Pause>>null");
				break;
			}
			case 3:
				cout << "Press any key to go back to the main menu";
				system("Pause>>null");
				break;
			default:
				break;
			}
			break;
		}
		case 6:
			system("cls");
			cout << "\nThe employees.dat file was saved successfully!";
			obj.write_to_file("employees.dat");
			system("Pause>>null");
			break;
		case 7:
			system("cls");
			cout << "\nThe employees.dat file was loaded successfully!";
			obj.read_from_file("employees.dat",obj);
			system("Pause>>null");
			break;
		case 8:
			/*Closes the program*/
			choice = 8;
			break;
		default:
			break;
		}
	} while (choice != 8);



	system("pause");
	return 0;
}