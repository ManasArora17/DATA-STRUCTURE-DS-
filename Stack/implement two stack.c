#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
struct twoStack{
    int size;
    int *item;
    int top1,top2;
};
struct twoStack s;
void initialise(int n){
    s.size=n;
    s.item  = calloc(n,sizeof(int));
    s.top1=-1;
    s.top2=n;
}
int isempty1(){
    if (s.top1==-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
int isempty2(){
    if (s.top2==s.size){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
void push1(int x){
    if(s.top1>s.top2){
        printf("stack overflow");
        exit(1);
    }
    s.top1=s.top1+1;
    s.item[s.top1]=x;
}
void push2(int x){
    if(s.top2<s.top1){
        printf("stack overflow");
        exit(1);
    }
    s.top2=s.top2-1;
    s.item[s.top2]=x;
}
int pop1(){
    if (isempty1()){
        printf("stack underflow");
        exit(1);
    }
    int x=s.item[s.top1];
    s.top1=s.top1-1;
    return x;
}
int pop2(){
    if (isempty2()){
        printf("stack underflow");
        exit(1);
    }
    int x=s.item[s.top2];
    s.top2=s.top2+1;
    return x;
}
int stacktop1(){
    int x=s.item[s.top1];
    return x;
}
int stacktop2(){
    int x=s.item[s.top2];
    return x;
}
int main(){
    initialise(10);
    push1(50);
    push1(100);
    printf("%d ",isempty2());
    printf("%d ",pop1());
    printf("%d ",pop2());
}
