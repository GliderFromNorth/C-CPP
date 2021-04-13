#include <bits/stdc++.h>
#include<iostream>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string numberToWord [9] = {"one","two","three","four","five","six","seven","eight","nine"};
    
    if (n>=0 && n<=9) cout<<numberToWord[n-1];
    else cout<<"Greater than 9";
    

    // Write Your Code Here

    return 0;
}
