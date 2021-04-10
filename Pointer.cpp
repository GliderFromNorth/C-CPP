#include<iostream>
using namespace std;

int main(){
    // What is a pointer > A datatypes which hold address of other data types. 

    int a=3 ;
    // & address of operator
    int* b = &a;
    cout<<"The address of a is :"<<b<<endl;

    // *-> (value at) Dereference operator
    cout<<"The value at address b is :"<<*b<<endl;

    // Pointer to Pointer 

    int** c  = & b;
    cout<<"The address of b is c :"<<c;
    cout<<"The value of a stored in pointed b and pointer of b stored  in c is :"<<**c;
    
    return 0;
}