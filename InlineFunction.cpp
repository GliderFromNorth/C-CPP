#include<iostream>
using namespace std;
/* 
Inline function
reduces code executiton time... 
too much inline code may result in too much cache memory if used in big function. 
If function is small its good to use inline. 
It is not recommended when recursion of static variable is used. 
*/

inline int product(int a,int b){
    return a*b;

}

int main(){
    //*********Inline Function*********
    int a=5, b= 6;
    cout<<"The product of A*b is : "<<product(a,b)<<endl;
    
    return 0;
}