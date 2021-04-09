#include<iostream>
// this program is written by #glidenfromnorth
using namespace std;

int glo = 49;

void sum(){
    int glo = 99;
    cout<<"\ntesting for global vs local\n";
    cout <<glo<<"\n";
}
int main (){

    int glo = 52;
    cout<<glo;
    glo = 88;


    sum();
    cout<<glo;
    cout<<"\nTesting Done!";

    return 0;

}