#include<stdio.h>
void reverse(int n){
    if(n==0){
        return 0;
    }
    else{
        printf("%d",n%10);
        return reverse(n/10);
    }
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    reverse(n);
}
