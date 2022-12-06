#include<stdio.h>
#include<string.h>
#define TURE 1
#define FALSE 0
#include"mystack.h"
int main(){
    char s1[20],s2[20];
    int i=0;
    printf("Enter the String: ");
    gets(s1);
    while(s1[i]!='\0'){
        push(s1[i]);
        i++;
    }
    int j=0;
    while(!isempty()){
        s2[j]=pop();
        j++;
    }
    if(strcmp(s1,s2)==0) printf("Palindrome String.");
    else printf("Not a Palindrome.");
}
