#include<iostream>
using namespace std;

int main(){
    int marks[5] = {23,45,58,98};
    int mathmarks [6];
    mathmarks[0]=100;
    mathmarks[1]=900;
    mathmarks[2]=200;
    mathmarks[3]=300;
    mathmarks[4]=400;

    for(int i =0; i <= 4; i++){
        cout<<mathmarks[i]<<endl;
    }
    cout<<marks[0]<<endl;
    cout<<marks[1]<<endl;
    cout<<marks[2]<<endl;
    cout<<marks[3]<<endl;
    return 0;
}