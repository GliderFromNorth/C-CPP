#include<iostream>
using namespace std;

/*
Creating Function 
*/

int sum(int a , int b){
    int c = a+b;
    return c;
}

int main(){
    int a, b;
    cout<<"Please Enter First Number : ";cin>>a;
    cout<<"Please Enter First Number : ";cin>>b;
    cout<<"The Sum of Number "<<a<<" and "<<b<<" is : "<<sum(a,b);
    
    return 0;
}