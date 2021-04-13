#include<iostream>
using namespace std;

/*
Function Overloading
Promotion compatable.
*/
int sum(int a , int b){
    cout<<" using two Arguments"<<endl;
    return a+b;
}
int sum(int a , int b, int c){
    cout<<" using three Arguments"<<endl;
    return a+b+c;
}
int main(){
    cout<<"The sum is "<<sum(6,9)<<endl;
    cout<<"The sum is "<<sum(6,9,9)<<endl;
    
    return 0;
}