#include "Header Files\Header.h"


int main_menu() {
	int menu = 0;
	do {
		system("cls");
		cout << "\n1. Add an employee";
		cout << "\n2. Remove employee";
		cout << "\n3. Search for an employee";
		cout << "\n4. Display all employees";
		cout << "\n5. Sort the employees";
		cout << "\n6. Write the employee data to the file";
		cout << "\n7. Load the employee data from the file";
		cout << "\n8. Exit the application";
		cout << "\n\nEnter your choice: ";
		cin >> menu;
	} while (menu > 8 || menu < 1);
	return menu;
}

int menu_search() {
	int menu = 0;
	do {
		system("cls");
		cout << "\n1. Search by ID";
		cout << "\n2. Search by SSN";
		cout << "\n3. Cancel and return to main menu";
		cout << "\n\nEnter your choice: ";
		cin >> menu;
	} while (menu > 3 || menu < 1);
	return menu;
}

int menu_sort() {
	int menu = 0;
	do {
		system("cls");
		cout << "\n1. Sort by ID";
		cout << "\n2. Sort by First Name";
		cout << "\n3. Cancel and return to main menu";
		cout << "\n\nEnter your choice: ";
		cin >> menu;
	} while (menu > 3 || menu < 1);
	return menu;
}

int menu_delete() {
	int menu = 0;
	do {
		system("cls");
		cout << "\n1. Delete first employee";
		cout << "\n2. Delete last employee";
		cout << "\n3. Cancel and return to main menu";
		cout << "\n\nEnter your choice: ";
		cin >> menu;
	} while (menu > 3 || menu < 1);
	return menu;
}