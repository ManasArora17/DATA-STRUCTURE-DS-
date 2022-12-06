#include<stdio.h>
void TOH(int n,char s,char m,char d){

    if(n==1){
        printf("Transfer the disk from %c to %c \n",s,d);
    }
    else{
        TOH(n-1,s,d,m);
        printf("Transfer the disk from %c to %c \n",s,d);
        TOH(n-1,m,s,d);
    }

}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    char s='S',m='M',d='D';
    TOH(n,s,m,d);
}
