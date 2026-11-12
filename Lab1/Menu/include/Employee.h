#ifndef Employee_H
#define Employee_H
#define MAX_EMPLOYEES  100
#include <string>
using namespace std;


class Employee
{
public:
  string name;
  int age;
  int salary;
  string department;

  Employee();
  Employee(string name, int age, int salary, string department);
  static Employee inputEmployee();
  static void addFixedNumber();
  static void addUntilFinished();
};
#endif
