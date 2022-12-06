#include<stdio.h>
#include"LinkedList.h"
#include<string.h>
#include<math.h>
void ReverseInplace(struct Node **START){
    struct Node *C,*P,*N;
    C = *START;
    P = NULL;
    N = C->Next;
    while(C!=NULL){
        C->Next = P;
        P = C;
        C = N;
        if(N!=NULL) N = N->Next;
    }
    *START = P;
}
int Addition(struct Node **START1,struct Node **START2){
    struct Node *p,*q,*START3;
    START3=NULL;
    ReverseInplace(START1);
    ReverseInplace(START2);
    p=*START1;
    q=*START2;
    int carry = 0,total,sum;
    while(p!=NULL & q!=NULL){
        total = p->info + q->info + carry;
        sum = total%10000;
        carry = total/10000;
        p=p->Next;
        q=q->Next;
        InsBeg(&START3,sum);
    }
    while(p!=NULL){
        total = p->info + carry;
        sum = total%10000;
        carry = total/10000;
        p=p->Next;
        InsBeg(&START3,sum);
    }
    while(q!=NULL){
        total = q->info + carry;
        sum = total%10000;
        carry = total/10000;
        q=q->Next;
        InsBeg(&START3,sum);
    }
    if(carry>0){
        InsBeg(&START3,sum);
    }
    ReverseInplace(&START3);
    Traverse(&START3);
}
int* SliceLongNumber(char *number){
    int a=strlen(number);
    int b=(a/4);
    int r=(a%4);
    if(r!=0) b=b+1;
    int *num1;
    num1 = calloc(b,sizeof(int));
    int i=0,c=0,j=0,d=0;
    int pow[4]={1,10,100,1000};
    while(i<a){
        d=d+(number[i]-48)*pow[3-c];
        c++;
        if(c==4){
            num1[j]=d;
            j++;
            d=0;
            c=0;
        }
        i++;
    }
    int t;
    if(r!=0){
        t=0;
        for(int i=0;i<r;i++){
            t=t+(number[(a-1)-i]-48)*pow[i];
        }
        num1[j]=t;
    }
    return num1;
}
int NewLen(char *number){
    int a=strlen(number);
    int b=a/4;
    if(a%4!=0) b=b+1;
    return b;
}
int main(){
    struct Node *START1,*START2;
    START1  = NULL;
    START2 = NULL;
    char number1[100];
    char number2[100];
    printf("Enter the number-1: ");
    gets(number1);
    printf("Enter the number-2: ");
    gets(number2);
    strrev(number1);
    strrev(number2);
    int *num1 = SliceLongNumber(number1);
    int *num2 = SliceLongNumber(number2);
    for(int i=0;i<NewLen(number1);i++){
        InsEnd(&START1,num1[i]);
    }
    for(int i=0;i<NewLen(number2);i++){
        InsEnd(&START2,num2[i]);
    }
    Traverse(&START1);
    printf("\n");
    Traverse(&START2);
    printf("\n");
    Addition(&START1,&START2);
}
