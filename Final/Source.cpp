#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

struct Employee
{
	int id;
	string fn;
	string ln;
	string ssn;
	Date hdate;
};

struct Node {
	Employee data;
	Node *next;
};

class list
{
private:
	Node * head, *tail;
public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	void createNode(int value, string fname, string lname, string assn, int dday, int dmonth, int dyear)
	{
		Node *temp = new Node;
		temp->data.id = value;
		temp->data.fn = fname;
		temp->data.ln = lname;
		temp->data.ssn = assn;
		temp->data.hdate.day = dday;
		temp->data.hdate.month = dmonth;
		temp->data.hdate.year = dyear;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void display()
	{
		Node *temp = new Node;
		temp = head;
		while (temp != NULL)
		{
			cout << "\n----------------\n";
			cout << "Employee ID: " << temp->data.id << "\n";
			cout << "First Name: " << temp->data.fn << "\n";
			cout << "Last Name: " << temp->data.ln << "\n";
			cout << "SSN: " << temp->data.ssn << "\n";
			cout << "Hired date: " << temp->data.hdate.day << "/" << temp->data.hdate.month << "/" << temp->data.hdate.year;
			temp = temp->next;
		}
	}
	void insert_start(int value, string fname, string lname, string assn, int dday, int dmonth, int dyear)
	{
		Node *temp = new Node;
		temp->data.id = value;
		temp->data.fn = fname;
		temp->data.ln = lname;
		temp->data.ssn = assn;
		temp->data.hdate.day = dday;
		temp->data.hdate.month = dmonth;
		temp->data.hdate.year = dyear;
		temp->next = head;
		head = temp;
	}
	void insert_position(int pos, int value, string fname, string lname, string assn, int dday, int dmonth, int dyear)
	{
		Node *pre = new Node;
		Node *cur = new Node;
		Node *temp = new Node;
		cur = head;
		for (int i = 1; i<pos; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		temp->data.id = value;
		temp->data.fn = fname;
		temp->data.ln = lname;
		temp->data.ssn = assn;
		temp->data.hdate.day = dday;
		temp->data.hdate.month = dmonth;
		temp->data.hdate.year = dyear;
		pre->next = temp;
		temp->next = cur;
	}
	void delete_first()
	{
		Node *temp = new Node;
		temp = head;
		head = head->next;
		delete temp;
	}
	void delete_last()
	{
		Node *current = new Node;
		Node *previous = new Node;
		current = head;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = NULL;
		delete current;
	}
	void delete_position(int pos)
	{
		Node *current = new Node;
		Node *previous = new Node;
		current = head;
		for (int i = 1; i<pos; i++)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
	}
	void search_int(int value) {
		Node *temp = new Node;
		temp = head;
		bool found = false;
		while (temp != NULL)
		{
			if (temp->data.id == value) {
				cout << "\nThe employee with the ID : " << temp->data.id << " was found! \n";
				cout << "Employee ID: " << temp->data.id << "\n";
				cout << "First Name: " << temp->data.fn << "\n";
				cout << "Last Name: " << temp->data.ln << "\n";
				cout << "SSN: " << temp->data.ssn << "\n";
				cout << "Hired date: " << temp->data.hdate.day << "/" << temp->data.hdate.month << "/" << temp->data.hdate.year;
			}
			temp = temp->next;
		}
		if (!found) {
			cout << "\nThe search returned no values";
		}
	}
	void search_int(string value) {
		Node *temp = new Node;
		temp = head;
		bool found = false;
		while (temp != NULL)
		{
			if (temp->data.ssn == value) {
				cout << "\nThe employee with the SSN : " << temp->data.ssn << " was found! \n";
				cout << "Employee ID: " << temp->data.id << "\n";
				cout << "First Name: " << temp->data.fn << "\n";
				cout << "Last Name: " << temp->data.ln << "\n";
				cout << "SSN: " << temp->data.ssn << "\n";
				cout << "Hired date: " << temp->data.hdate.day << "/" << temp->data.hdate.month << "/" << temp->data.hdate.year;
			}
			temp = temp->next;
		}
		if (!found) {
			cout << "\nThe search returned no values";
		}
	}

	void search_name(string value) {
		Node *temp = new Node;
		temp = head;
		while (temp != NULL)
		{
			if (temp->data.fn == value || temp->data.ln == value) {
				cout << "\nThe student with ID " << value << " was found!\n";
				cout << temp->data.id << "\n";
				cout << temp->data.fn << "\n";
				cout << temp->data.ln << "\n";
			}
			temp = temp->next;
		}
	}
	void sortID() {
		for (Node *idx = head; idx != NULL; idx = idx->next)
		{
			for (Node *jdx = head; jdx != idx; jdx = jdx->next)
			{
				if (idx->data.id <= jdx->data.id)
				{
					Employee temp = idx->data;
					idx->data = jdx->data;
					jdx->data = temp;
				}
			}
		}
	}
	void sortFname() {
		for (Node *idx = head; idx != NULL; idx = idx->next)
		{
			for (Node *jdx = head; jdx != idx; jdx = jdx->next)
			{
				if (idx->data.fn <= jdx->data.fn)
				{
					Employee temp = idx->data;
					idx->data = jdx->data;
					jdx->data = temp;
				}
			}
		}
	}
	void write_to_file(const char * file_name)
	{
		ofstream ofs;
		ofs.open(file_name, ofstream::out | ofstream::trunc);
		ofs.close();

		ofstream out_file(file_name, ios::out | ios::app); //out: writting mode
		for (Node *jdx = head; jdx != NULL; jdx = jdx->next)
		{			
			if (jdx != tail) { out_file << jdx->data.id << "|" << jdx->data.fn << "|" << jdx->data.ln << "|" << jdx->data.ssn << "|" << jdx->data.hdate.day << "|" << jdx->data.hdate.month << "|" << jdx->data.hdate.year << "|" << endl; }
			else { out_file << jdx->data.id << "|" << jdx->data.fn << "|" << jdx->data.ln << "|" << jdx->data.ssn << "|" << jdx->data.hdate.day << "|" << jdx->data.hdate.month << "|" << jdx->data.hdate.year << "|"; }
		}
		out_file.close();
	}
	void read_from_file(const char * file_name, list &obj)
	{
		ifstream in_file(file_name); 
		string line;
		int xvalue, xday, xmonth, xyear;
		string xfname, xlname, xssn;

		if (in_file.good()) {
			getline(in_file, line, '|');
			xvalue = stoi(line);
			getline(in_file, xfname, '|');
			getline(in_file, xlname, '|');
			getline(in_file, xssn, '|');
			getline(in_file, line, '|');
			xday = stoi(line);
			getline(in_file, line, '|');
			xmonth = stoi(line);
			getline(in_file, line, '|');
			xyear = stoi(line);
			obj.createNode(xvalue, xfname, xlname, xssn, xday, xmonth, xyear);
			while (getline(in_file,line))
			{
				getline(in_file, line, '|');
				xvalue = stoi(line);
				getline(in_file, xfname, '|');
				getline(in_file, xlname, '|');
				getline(in_file, xssn, '|');
				getline(in_file, line, '|');
				xday = stoi(line);
				getline(in_file, line, '|');
				xmonth = stoi(line);
				getline(in_file, line, '|');
				xyear = stoi(line);
				obj.createNode(xvalue, xfname, xlname, xssn, xday, xmonth, xyear);
			}			
			in_file.close();
		}
	}
};


int main_menu() {
	int menu = 0;
	do {
		system("cls");
		cout << "\n1. Add an emloyee";
		cout << "\n2. Remove emloyee";
		cout << "\n3. Search for an emloyee";
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