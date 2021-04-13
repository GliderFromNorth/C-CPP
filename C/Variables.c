#include<stdio.h>
/*
variables: int a = 1; , char ch = 'd';  , float f = 7.7;
*/

int main(){
    int a = 3;
    float f = 7.7;
    char ch = 'h';
    printf("Variables in C");
    printf("\nThe Value of a is a; This is not print value of a.(%d is needed to print integers)");
    printf("\nThe Value of a is %d", a);
    printf("\nThe Value of f is %.3f", f);
    printf("\nThe Value of ch is %c", ch);

    return 0;
}