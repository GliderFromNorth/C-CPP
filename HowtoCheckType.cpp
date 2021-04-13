#include<iostream>
#include<typeinfo>
using namespace std;

int main(){
    char a[] = "dfdsfffff";
    cout<<typeid(a).name();
    
    return 0;
}