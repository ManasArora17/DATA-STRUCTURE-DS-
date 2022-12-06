#include<stdio.h>
#include<stdlib.h>
#define size 100
#define TURE 1
#define FALSE 0
#include"mystack.h"
int main(){
    char s[20];
    int i=0;
    printf("Enter the String: ");
    gets(s);
    while(s[i]!='\0'){
        push(s[i]);
        i++;
    }
    while(!isempty()) printf("%c",pop());
}
