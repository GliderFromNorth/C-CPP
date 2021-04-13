#include<iostream>
using namespace std;
/*
FIbonacci Series
*/

int fib(int n){
    if (n<2) return 1;
    return fib(n-2)+ fib(n-1);
}

int main(){
    int a;
    cout<<"Enter the nth number for Fibonacchi :";cin>>a;
    cout<<"The Fibonacchi Series for nth term is : "<<fib(a)<<endl;
    
    return 0;
}