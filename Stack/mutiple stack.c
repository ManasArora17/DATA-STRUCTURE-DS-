#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

struct stack{
    int *item;
    int *TOP;
};
struct stack s;
void initialise(int n,int m,int i){
    static int j=0;
    if(i<m-1) s.TOP[j] = ((n/m)*i)-1;
    else s.TOP[m-1]=10;
    j++;
}

int isempty(int i){
    if (s.TOP[i]==-1){
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
int main(){
    int m,n;
    printf("Enter the size of stack: ");
    scanf("%d",&n)
    s.item = calloc(n,sizeof(int));
    printf("Enter the number of stack: ");
    scanf("%d",&m)
    s.TOP = calloc(m,sizeof(int));
}
