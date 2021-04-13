#include<iostream>
using namespace std;

int sum(int a , int b){
    int c = a+b;
    return c;
}
//  This will not swap....
void swap (int x , int y ){
    int temp = x;
    x = y;
    y = temp;
}
// Swap using pointer // Call by reference 
void swapPointer (int* x , int* y ){
    int temp = *x;
    *x = *y;
    *y = temp;
}
// Call by reference usinf reference variable 
void swapReferenceVar (int &x , int &y ){
    int temp = x;
    x = y;
    y = temp;
}
int main(){
    int a = 4, b =5;
    //cout<<"The sum of 4 and 5 is : "<<sum(4,5);
    cout<<"The Value of a is " <<a<< " and the Value of b is "<<b<<endl;
    //swap(a,b);
    //swapPointer(&a,&b);
    swapReferenceVar(a,b);
    cout<<"The Value of a is " <<a<< " and the Value of b is "<<b<<endl;
    
    return 0;
}