#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee() {
  this->name = "";
  this->age = 0;
  this->salary = 0;
  this->department = "";
}

Employee::Employee(string name, int age, int salary, string department) {
  this->name = name;
  this->age = age;
  this->salary = salary;
  this->department = department;
}

Employee Employee::inputEmployee() {
  string name;
  string department;
  int age;
  int salary;

  cout << "Enter Employee Name: ";
  cin >> name;

  cout << "Enter Employee Age: ";
  cin >> age;

  cout << "Enter Employee Salary: ";
  cin >> salary;

  cout << "Enter Employee Department: ";
  cin >> department;

  return Employee(name, age, salary, department);
}

void Employee::addFixedNumber() {
  int count;

  cout << "How many employees do you want to add? ";
  cin >> count;

  Employee employees[MAX_EMPLOYEES];

  for (int i = 0; i < count; i++) {
    cout << "\n========== Employee " << i + 1
         << " ==========\n";

    employees[i] = Employee::inputEmployee();
  }

  cout << "\n========== Employees Created ==========\n";

  for (int i = 0; i < count; i++) {
    cout << "\nEmployee " << i + 1 << '\n';
    cout << "Name: " << employees[i].name << '\n';
    cout << "Age: " << employees[i].age << '\n';
    cout << "Salary: " << employees[i].salary << '\n';
    cout << "Department: " << employees[i].department << '\n';
  }
}

void Employee::addUntilFinished() {
  int capacity = 20;
  int count = 0;

  Employee* employees = new Employee[capacity];

  char choice = 'y';

  while (choice == 'y' || choice == 'Y') {
    if (count == capacity) {
      int newCapacity = capacity * 2;
      Employee* newEmployees = new Employee[newCapacity];

      for (int i = 0; i < count; i++) {
        newEmployees[i] = employees[i];
      }

      delete[] employees;
      employees = newEmployees;
      capacity = newCapacity;
    }

    cout << "\n========== Employee " << count + 1
         << " ==========\n";

    employees[count] = Employee::inputEmployee();
    count++;

    cout << "\nAdd another employee? (y/n): ";
    cin >> choice;
  }

  cout << "\n========== Employees Created ==========\n";

  for (int i = 0; i < count; i++) {
    cout << "\nEmployee " << i + 1 << '\n';
    cout << "Name: " << employees[i].name << '\n';
    cout << "Age: " << employees[i].age << '\n';
    cout << "Salary: " << employees[i].salary << '\n';
    cout << "Department: " << employees[i].department << '\n';
  }

  delete[] employees;
}
