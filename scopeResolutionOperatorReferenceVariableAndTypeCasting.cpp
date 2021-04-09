#include<iostream>

using namespace std;
int c = 45;

int main(){
    // int a , b, c ;
    // cout<<"Enter the Value of a: "<<endl;
    // cin>>a;
    // cout<<"Enter the Value of b: "<<endl;
    // cin>>b;
    // c = a+b;
    // cout<<"The Results starts From here...."<<endl;
    // cout<<"The Sum of a+b is c : "<<c<<endl;
    // cout<<"The Value of Global c is : "<<::c<<endl;  // Scope Resolution Operator


    /* Function Overloading it is important to declare the type of literal */ 

    // *********** Float, Double, Long DOuble Literals *************

    // float d = 34.4F;
    // long double e = 34.4L;
    // cout<<"The value of d is : "<<d<<endl<<"The value of e is :"<<e<<endl;

    // cout<<"The size of 34.5 :"<<sizeof(34.5)<<endl;
    // cout<<"The size of 34.5f : "<<sizeof(34.5f)<<endl;
    // cout<<"The size of 34.5l :"<<sizeof(34.5l)<<endl;

    
    // *********** Reference variable *************
    // Saurav ---- >Lollee--------> Jha2 ------> GliderFromNorth

    float x = 69;
    float & y=x;
    cout<<x<<endl;
    cout<<y<<endl;

        // *********** Type Casting *************

    int a = 45;
    float b = 45.5;
    cout<<"The Expression is :"<<(float)a<<endl;
    cout<<"The Expression is :"<<float(a)<<endl;

    cout<<"The Expression is :"<<int(b)<<endl;    
    cout<<"The Expression is :"<<(float)b<<endl;    




}