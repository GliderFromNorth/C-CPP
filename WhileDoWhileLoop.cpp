#include<iostream>
using namespace std;

/* 
Loops in C++
There are three types of loops : 1:For wloop 2: while loop 3: do while loop.

*/

int main(){
    int numberOfTimes ;
    cout<<"For Loops Start Here"<<endl;
    cout<<"Enter the number of times you want to Iterate : "<<endl;
    cin>>numberOfTimes;
    cout<<"Iteration starts here....."<<endl;

    // for (int i = 0 ; i<= numberOfTimes; i++){
    //     cout<<i<<endl;

    // }
    // int i =0;
    // while( i <= numberOfTimes){
    //     cout<<i<<endl;
    //     i++;
    // }
    int i =1;
    do{
        cout<<i<<endl;
        i++;
    }while(i <= numberOfTimes);
    return 0;

}