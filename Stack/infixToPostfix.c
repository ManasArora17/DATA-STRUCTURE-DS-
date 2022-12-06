#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0
struct stack{
    char item[STACKSIZE];
    int TOP;
};
struct stack s;
void initialise(){
    s.TOP=-1;
}

int isempty(){
    if (s.TOP==-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void push(char x){
    if(s.TOP==STACKSIZE-1){
        printf("stack overflow");
        exit(1);
    }
    s.TOP=s.TOP+1;
    s.item[s.TOP]=x;
}

char pop(){
    if (isempty(s)){
        printf("stack underflow");
        exit(1);
    }
    char x=s.item[s.TOP];
    s.TOP=s.TOP-1;
    return x;
}
char stacktop(){
    char x=s.item[s.TOP];
    return x;
}
prcd(char a,char b){
   if(a=='^' || a=='*' || a=='/' || a=='%'){
        if(b=='^'){
            return FALSE;
        }
        else{
            return TRUE;
        }
    }
    else{
        if(b=='+' || b=='-'){
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
}
void infixtopostfix(char infix[]){
    int i=0,p=0;
    char postfix[20];
    char x,symbol;
    initialise();
    while(infix[i]!='\0'){
        symbol=infix[i];
        i++;
        if((symbol>='a' && symbol<='z')||(symbol>='A' && symbol<='Z')||(symbol>='0' && symbol<='9')){
            postfix[p]=symbol;
            p++;
        }
        else{
            while(!isempty() && prcd(stacktop(),symbol)){
                  x=pop();
                  postfix[p]=x;
                  p++;
            }
            push(symbol);
        }
    }
    while(!isempty()){
        x=pop();
        postfix[p]=x;
        p++;
    }
    postfix[p]='\0';
    for(int i=0;postfix[i]!='\0';i++){
        if(postfix[i]!='(' && postfix[i]!=')')
            printf("%c",postfix[i]);
    }
}
int main(){
    char infix[20];
    gets(infix);
    infixtopostfix(infix);
}
