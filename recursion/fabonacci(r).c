#include<stdio.h>
/*int DAT[101];
int fib(int n){
    if(n==1){
        DAT[n]=0;
    }
    else if(n==2){
        DAT[n] = 1;
    }
    else{
        if(DAT[n]==0){
            DAT[n] = fib(n-1)+fib(n-2);
        }
    }
    return DAT[n];
}*/
int fib(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
int main(){
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("%d ",fib(i));
    }

}
