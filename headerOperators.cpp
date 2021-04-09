#include<iostream>
using namespace std;
/* There are two types of header File
1:System header files comes with compiler
2:User Defined Header file: written by user. */
int main(){
    cout<<"Operator in C++"<<endl;
    cout<<"Following are the types of operators"<<endl;

    // Arithmetic operators.
    int  b = 5,a=4;
    cout<<"The value of A+B is: "<<a+b<<endl;
    cout<<"The value of A-B is: "<<a-b<<endl;
    cout<<"The value of A*B is: "<<a*b<<endl;
    cout<<"The value of A/B is: "<<a/b<<endl;
    cout<<"The value of A%B is: "<<a%b<<endl;
    cout<<"The value of A++ is: "<<a++<<endl;
    cout<<"The value of A-- is: "<<a--<<endl;
    cout<<"The value of ++A is: "<<++a<<endl;
    cout<<"The value of --A is: "<<--a<<endl;

    // Assignment Operators
    // int a = 6;
    // char b = 'd';
    //Comparison Operators

cout<< "The Following are the Comparison Operators in C++"<<endl;
    cout<<"The value of a==b is "<<(a==b)<<endl;
    cout<<"The value of a!=b is "<<(a!=b)<<endl;
    cout<<"The value of a>b is "<<(a>b)<<endl;
    cout<<"The value of a<b is "<<(a<b)<<endl;
    cout<<"The value of a<=b is "<<(a<=b)<<endl;
    cout<<"The value of a>=b is "<<(a>=b)<<endl;



    return 0;
}