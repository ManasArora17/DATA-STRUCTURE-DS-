#include<stdio.h>


int GCD(int a,int b){
    if(a==b){
        return a;
    }
    else{
        if(a>b){
            GCD(a-b,b);
        }
        else{
            GCD(a,b-a);
        }
    }
}
int main(){
    int a,b;
    printf("Enter the numbers: ");
    scanf("%d %d",&a,&b);
    int result= GCD(a,b);
    printf("%d\n",result);

}
