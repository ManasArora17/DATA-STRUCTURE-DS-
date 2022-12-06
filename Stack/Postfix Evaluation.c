#include<stdio.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0
#include"mystack.h"
int Evaluate(int a,int b,char op){
    switch(op){
        case '+': return a+b;
        case '*': return a*b;
        case '-': return a-b;
        case '/': return a/b;
    }
}
int main(){
    char PS[20],symb;
    int val,a,b,x,i=0;
    gets(PS);
    while(PS[i]!='\0'){
        symb=PS[i];
        if(symb>='0'&&symb<='9'){
            push(symb-48);
        }
        else{
            b= pop();
            a= pop();
            val =Evaluate(a,b,symb);
            push(val);
        }
        i++;
    }
    x=pop();
    printf("%d",x);
    return 0;
}
