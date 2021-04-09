#include<iostream>
using namespace std;

/* ********* Basic control structures ************
1: Sequence structure
2: selection structure  | if else if else Ladder || switch case||
3: Loop Structure
*/

// ************Switch case*************

int main(){
    int age;
    cout<<"Enter your age : "<<endl;
    cin>>age;

    switch (age)
    {
    case 18 :
        cout<<"You are "<<age<<" you are welcome to join our party."<<endl;
        break;
    case 22:
        cout<<"you are "<<age<<" you are welcome you Mumbai."<<endl;
        break;

    
    default:
        cout<<"Sorry, Only 18 and 22 are alllowed"<<endl;
        break;
    }

    
    return 0;

}