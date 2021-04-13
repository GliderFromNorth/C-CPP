#include<iostream>
using namespace std;

/*
Creating Function Prototype
if you declare function sum() after main, it will result as error without function prototype.
with this feature, compiler is aware of the function going to use for main. introduced in cpp first.

syntax for function prototype.
type function-name(arguements);

*/


int sum(int a , int b);
void g();

int main(){
    int num1, num2;
    cout<<"Please Enter First Number : ";cin>>num1;
    cout<<"Please Enter First Number : ";cin>>num2;
    cout<<"The Sum of Number "<<num1<<" and "<<num2<<" is : "<<sum(num1, num2);
    g();
    
    return 0;
}
int sum(int a , int b){
    // a and b are formal parameters taking values from actual parameters num1 & num 2.
    int c = a+b;
    return c;
}

void g(){
    cout<<"\nThank you for using Responsibly, Good Bye!";
}