#include<stdio.h>
#include<string.h>
#include"mystack.h"
int main(){
    char s[20];
    printf("Enter the Expression: ");
    gets(s);
    int i=0;
    initialise();
    while(s[i]!='\0'){
        if(s[i]=='(') push("(");
        else if(s[i]==')') pop();
        i++;
    }
    if(isempty()) printf("TRUE");
    else printf("FALSE");
    return 0;
}
