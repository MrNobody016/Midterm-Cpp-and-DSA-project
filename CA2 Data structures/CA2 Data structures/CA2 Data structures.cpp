#include<iostream>
#include <string>
using namespace std;

struct Employee
{
	int employeeID;
	string name;
	string position;
	double salary;
	Employee* next;
};

class employeedirectory
{
private:
	Employee* head; // pointer to the first employee in the directory
	Employee* current;// pointer to the current employee in the directory

public:
	employeedirectory() : head(nullptr) {}//constructour 

	~employeedirectory()
	{
		Employee* current = head;
		while (current != nullptr)
		{
			Employee* next = current->next;
			delete current;
			current = next;
		}
	}

	void addemployee(int employee_id, string employee_name, string employee_position, double employee_salary)
	{
		Employee* E1 = new Employee;//creating object of employee (E1)
		E1->employeeID = employee_id;
		E1->name = employee_name;
		E1->position = employee_position;
		E1->salary = employee_salary;
		E1->next = head;
		head = E1;//making new head of list

		cout << " " << endl;

	}

	void removeemployee(int employee_id)//function to remove employee
	{

		Employee* current = head;
		Employee* prev = nullptr;

		while (current != nullptr && current->employeeID != employee_id) {
			prev = current;
			current = current->next;
		}

		if (current == nullptr) {
			cout << "Employee with ID " << employee_id << " not found." << endl;
			return;
		}

		if (prev == nullptr) {
			head = current->next;
		}
		else {
			prev->next = current->next;
		}

		delete current;
		cout << "Employee removed successfully." << endl;

		cout << " " << endl;

	}

	void updatesalary(int employee_id, double newSalary)//function to update salary 
	{
		Employee* current = head;
		while (current != nullptr) {
			if (current->employeeID == employee_id) {
				current->salary = newSalary;
				cout << "Salary updated successfully." << endl;
				return;
			}
			current = current->next;
		}
		cout << "Employee with ID " << employee_id << " not found." << endl;

		cout << " " << endl;
	}

	void Displaydirectory() //function to print dierectory
	{
		if (head == nullptr) //if head do not point at any location then directory is empty
		{
			cout << "Directory is empty." << endl;
			return;
		}

		Employee* current = head;
		cout << "Employee Directory:" << endl;
		while (current != nullptr) {
			cout << "\nEmployee ID: " << current->employeeID << endl;
			cout << "Name: " << current->name << endl;
			cout << "Position: " << current->position << endl;
			cout << "Salary: Rs" << current->salary << endl;
			current = current->next;
		}

		cout << " " << endl;
	}
};

int main()
{
	employeedirectory directory;

	directory.addemployee(10, "Arnav Patil", "Designer", 80000);
	directory.addemployee(11, "Parth Patil", "Developer", 90000);
	directory.addemployee(12, "Dev Patel", "Manager", 100000);

	directory.Displaydirectory();

	directory.updatesalary(10, 85000);

	directory.updatesalary(12, 105000);

	directory.removeemployee(11);

	directory.Displaydirectory();

	return 0;
}