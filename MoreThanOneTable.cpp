#include<iostream>
#include<iomanip>
#include<iomanip>
using namespace std;

/* 
Loops in C++
There are three types of loops : 1:For wloop 2: while loop 3: do while loop.

setw() is also known as width os space multiplier. 

*********This Code is Written By @GliderfromNorth***************************
 */

int main(){
    for (int i =1; i<=10;i++){
        for (int j =1; j<=20;j++){
            cout<<setw(3)<<(i*j)<<" ";

        }
        cout<<"\n";
        
     }

    return 0;

}