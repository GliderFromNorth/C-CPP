#include<iostream>
using namespace std;
/*
Default Arguements 
Default Arguement should be entered at last arguemnt in function after compulsary arguement. 
*/

inline float moneyReceived(int currentMoney, float  factor = 1.040){
    return currentMoney*factor;

}

int main(){
    int money= 100000;
    cout<<"Total amount you would receive for" <<money<< " after 1 year is :"<<moneyReceived(money);
    cout<<"\nFor VIP: Total amount you would receive for" <<money<< " after 1 year is :"<<moneyReceived(money,1.1);
    
    return 0;
}