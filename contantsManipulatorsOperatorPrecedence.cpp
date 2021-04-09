#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    // int a = 46;
    // cout<<"The value of a is :"<<a<<endl;
    // a = 58;
    // cout<<"The value of a is :"<<a<<endl;

    // when we don't apply the constants the value of "a" will change in next procedure.
    // But when we apply contacts to a int "a", it won't let change the value.

    // const int a = 40;
    // cout<<"The value of a is : "<<a<<endl;
    // a = 56;
    // cout<<" It will show error"<<endl;

    // //**** Manipulators in C++ **********
    // int a =3, b = 27, c = 789;

    // cout<<"The value of a without Manipulator (setw) is :"<<a<<endl;
    // cout<<"The value of b without Manipulator (setw) is :"<<b<<endl;
    // cout<<"The value of c without Manipulator (setw) is :"<<c<<endl;

    // cout<<"The value of c with Manipulator (setw) is :"<<setw(4)<<a<<endl;
    // cout<<"The value of c with Manipulator (setw) is :"<<setw(4)<<b<<endl;
    // cout<<"The value of c with Manipulator (setw) is :"<<setw(4)<<c<<endl;

    // ******************* Operator Precedance ****************

    int a =  3, b =4;
    int c = a*5+b;
    cout<<c;
    return 0;
}