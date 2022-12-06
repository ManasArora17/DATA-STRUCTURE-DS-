#include<stdio.h>
#include<stdlib.h>
int palindrome(char *s,int a,int b){
    if(a==b) return 1;
    if(s[a]!=s[b]) return 0;
    if(a<b) return palindrome(s,a+1,b-1);
}
int len(char *s){
    int c=0;
    while(s[c]!='\0') c++;
    return c;
}
int main(){
    char *s;
    printf("Enter the string: ");
    s=malloc(1024*sizeof(char));
    scanf("%s",s);
    int b = len(s)-1,a=0;
    int result=palindrome(s,a,b);
    (result==1 || result==2)?printf("True"):printf("False");
}
