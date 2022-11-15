#include<stdio.h>
#include<stdlib.h>
#define size 100
#define TURE 1
#define FALSE 0
struct stack{
    int item[size];
    int top;
};
struct stack s;
void initialize(){
    s.top=-1;
}
int IsEmpty(){
    if(s.top==-1) return 1;
    else return 0;
}
int stacktop(){
    return s.item[s.top];
}
void push(int x){
    if(s.top==size-1){
        printf("OVER FLOW");
        exit(1);
    }
    else{
        s.top=s.top+1;
        s.item[s.top]=x;
    }
}
int pop(){
    if(s.top==-1){
        printf("UNDER FLOW");
        exit(1);
    }
    else{
        int x = s.item[s.top];
        s.top=s.top-1;
        return x;
    }
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",n);
    while(n!=0){
        push(n%10);
        n=n/10;
    }
    while()


}
