#include <iostream>
#include "Stack.h"
#include "Stack.h"
using namespace std;

void viewStack(Stack & s){
    s.display();
}

Stack returnStack(){
    //Stack s(5);
    //return s;
    return Stack(5);
}


int Stack::activeStacksCount = 0;
int main()
{
  
    cout<<"============Stack s(5)========="<<endl;
    Stack s(5); // Constructor
        cout<<"====================="<<endl;
    s.push(10);
    s.push(20);
    cout<<"============Stack *sptr=new Stack();========="<<endl;
    Stack *sptr=new Stack();
        cout<<"====================="<<endl;
    cout<<"============Stack s2=s========="<<endl;

    Stack s2=s;//Copy Constructor
        cout<<"====================="<<endl;
    cout<<"============viewStack(s)========="<<endl;
    viewStack(s);
        cout<<"====================="<<endl;
    // By Value --> Call Copy Constructor + Destructor
    // By Re -->
    cout<<"============s=s2========="<<endl;
    s=s2; // Assigment Operator
        cout<<"====================="<<endl;
    cout<<"============s=returnStack()========="<<endl;
    s=returnStack();
    cout<<"====================="<<endl;

    cout<<"============ Stack s5=returnStack();========="<<endl;
    Stack s5=returnStack();
    cout<<"====================="<<endl;
    cout<<Stack::getactiveStacksCount();
    //Memory Leak if forget delete
    delete sptr;
    return 0;
}
