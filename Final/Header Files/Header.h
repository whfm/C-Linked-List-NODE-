#ifndef FINAL_H
#define FINAL_H

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
			while (getline(in_file, line))
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


int main_menu();

int menu_search();

int menu_sort();

int menu_delete();

#endif