#ifndef STACK_H
#define STACK_H
#include "Employee.h"
#include <iostream>
#define LOG(str) std::cout<<str<<std::endl //Macors
class Stack
{

    public:
        Stack();
        Stack(int sizeArray);
        ~Stack();
        Stack(const Stack & s);
        void push(Employee data);
        int pop(Employee* employee);
        void display(void);
        Stack & operator=(const Stack & s);
        static int getactiveStacksCount();
    protected:


    private:
        int top;
        int sizeArray;
        Employee *Employees;
        // 1. Declare a static variable to count active stacks
        static int activeStacksCount;
};

#endif // STACK_H
