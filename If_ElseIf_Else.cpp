#include<iostream>
using namespace std;

/* ********* Basic control structures ************
1: Sequence structure
2: selection structure
3: Loop Structure
*/

//

int main(){
    int age ;
    cout<<"Basic Control Statements"<<endl;
    cout<<"Tell me your age : "<<endl;
    cin>>age;
    if ((age>18)&& (age>0)){
        cout<<"You can come to party"<<endl;
    }
    else if (age==18){
        cout<<"Even you are welcome to party."<<endl;
    }
    else if (age<1){
        cout<<"You din't Even born yet"<<endl;
    }
    else{
        cout<<"You can go watch pogo, not welcome to party."<<endl;
    }
    return 0;

}