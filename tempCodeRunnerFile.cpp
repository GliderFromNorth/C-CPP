#include<iostream>
#include<iomanip>
using namespace std;

/* 
Loops in C++
There are three types of loops : 1:For wloop 2: while loop 3: do while loop.

*********This Code is Written By @GliderfromNorth***************************
 */

int main(){
    int numberOfTimes, table ;
    cout<<"Enter Table Upto : "<<endl;
    cin>>numberOfTimes;
    cout<<"Enter Table of : "<<endl;
    cin>>table;
    cout<<"Iteration starts here....."<<endl;

    int i =1;
    do{
        cout<<table<<" x "<<setw(2)<<i<<" ="<<setw(4)<<(table*i)<<endl;
        i++;
    }while(i <= numberOfTimes);
    return 0;

}