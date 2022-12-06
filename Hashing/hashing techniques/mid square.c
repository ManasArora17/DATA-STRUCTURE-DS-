#include<stdio.h>
#include<math.h>
int digitCount(int n){
    int c=0;
    while(n!=0){
        n=n/10;
        c++;
    }
    return c;
}
int midSquare(int key,int TS){
    int a=digitCount(TS-1);
    int b=digitCount(key);
    int c=(2*b-a)/2;
    int x=(key*key)/pow(10,c);
    int l=x%(int)pow(10,a);
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
        printf("%d ---> %d\n",key[i],midSquare(key[i],TS));
    }
}
