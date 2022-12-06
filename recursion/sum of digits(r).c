#include<stdio.h>
int sum(int n){
    int s=0;
    if(n==0){
        return 0;
    }
    else{
        s=s+(n%10);
        return s+sum(n/10);
    }
}
int main(){
    int n;
    printf("Enter the the number: ");
    scanf("%d",&n);
    int result=sum(n);
    printf("%d",result);
}
