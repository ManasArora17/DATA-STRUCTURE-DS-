#include<stdio.h>
int digitCount(int n){
    int c=0;
    while(n!=0){
        n=n/10;
        c++;
    }
    return c;
}
int pow(int n,int a){
    if(a==1)
        return n;
    else
        return n*pow(n,a-1);
}
int folding(int key,int TS){
    int a=digitCount(TS-1);
    int c=pow(10,a);
    int sum=0;
    while(key!=0){
        int b=key%c;
        sum=sum+b;
        key=key/c;

    }
    int l=sum%c;
    l=l%TS;
    return l;
}
int main(){
    int TS;
    printf("Enter the table size: ");
    scanf("%d",&TS);
    int key[4]={1223,3886,2940,7662};
    printf("key       value\n");
    printf("-----------------\n");
    for(int i=0;i<4;i++){
        printf("%d ---> %d\n",key[i],folding(key[i],TS));
    }
}

