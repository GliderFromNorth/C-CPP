#include<iostream>
using namespace std;
/*
Recursion is a function which call self, until false.
Factorial is a good example of Recursion.

*/

int factorial(int n){
    if (n<=1) return 1;
    return n * factorial(n-1);
}

int main(){
    int a;
    cout<<"Enter a Number for factorial :";cin>>a;
    cout<<"The factorial of "<<a<< " is "<<factorial(a)<<endl;
    
    return 0;
}