#include<iostream>
using namespace std;

/* Pointer Arithmetic
 address new(p+i) =address current(p) +(i*size of data type )
*/
int main(){
    int marks[5]= {1, 56, 87, 44, 69,};
    int *p = marks;

    cout<<" The value of *p (means first pointer) is "<<*p<<endl;
    cout<<" The value of *p+1  is "<<*(p+1)<<endl;
    cout<<" The value of *p+2  is "<<*(p+2)<<endl;
    cout<<" The value of *p+3  is "<<*(p+3)<<endl;
    cout<<" The value of *p+4  is "<<*(p+4)<<endl;

    
    
    
    return 0;
}