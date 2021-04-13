#include<iostream>
using namespace std;

int main(){
    int numberOfElements ;
    cout<<"Enter the Number of Elements :";cin>>numberOfElements;
    string inputChar [numberOfElements];
    cout<<"Enter the Elements :";
    for (int i =0; i<numberOfElements;i++){
        cin>>inputChar[i];
    }
    for (int i =0;i<numberOfElements;i++){
        cout<<inputChar[i]<<" ";
    }

    return 0;
}