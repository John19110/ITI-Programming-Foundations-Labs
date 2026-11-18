#include "Stack.h"

int Stack :: getActiveStacksCount(){
           return activeStacksCount;
}
Stack::Stack()
{
    activeStacksCount++;
    this->sizeArray=10;
    this->top=-1;
    this->Employees=new Employee[sizeArray]{};
    
}
Stack::Stack( const Stack & s)
{
    activeStacksCount++;
    this->Employees=new Employee[s.sizeArray];
    this->sizeArray=s.sizeArray;
    this->top=s.top;
    for(int i=0; i<=top; i++){
            this->Employees[i]=s.Employees[i];
    }

}
Stack::Stack(int sizeArray)
{
    activeStacksCount++;
    this->sizeArray=sizeArray;
    this->top=-1;
    this->Employees=new Employee[sizeArray];
    
}
void Stack:: push(Employee employee){

    if(top >= sizeArray -1){//5
        LOG("Stack is FUll");
        return ; 
   }
   top++;  
   Employees[top]=employee;
}
 int Stack::pop(Employee* employee){
    if(top == -1){
        return 0 ;
    }
       *employee= Employees[top--];

    

    return 1;

}
void Stack:: display(void){
   for(int i=top; i>=0; i--){
        LOG(Employees[i].name<<"--->");
   }
}
Stack & Stack:: operator=(const Stack & s){

        if (this == &s) {
        return *this;
    }


delete [] this->Employees;
Employees=new Employee[s.sizeArray];
this->sizeArray=s.sizeArray;
this->top=s.top;
for(int i=0; i<=top; i++){
        this->Employees[i]=s.Employees[i];
}
return *this;

}

Stack::~Stack()
{
    activeStacksCount--;
    delete []Employees;
}
