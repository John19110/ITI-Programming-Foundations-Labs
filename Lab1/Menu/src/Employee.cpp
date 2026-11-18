#include "Employee.h"
#include <iostream>
#include"Stack.h"

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


  Stack Employees(count);

  for (int i = 0; i < count; i++) {
    cout << "\n========== Employee " << i + 1
         << " ==========\n";

        Employees.push(Employee::inputEmployee());

  }

  cout << "\n========== Employees Created ==========\n";

      Employees.display();

}

void Employee::addUntilFinished() {
  int capacity = 20;
  int count = 0;

    Stack* employees=new Stack(capacity);

  char choice = 'y';

  while (choice == 'y' || choice == 'Y') {
    if (count == capacity) {
      int newCapacity = capacity * 2;
      Stack* newEmployees = new Stack(newCapacity);

      delete employees;
      employees = newEmployees;
      capacity = newCapacity;
    }

    cout << "\n========== Employee " << count + 1<< " ==========\n";

    employees->push( Employee::inputEmployee());
    count++;

    cout << "\nAdd another employee? (y/n): ";
    cin >> choice;
  }

  cout << "\n========== Employees Created ==========\n";

      employees->display();


  delete employees;
}
