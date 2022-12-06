#include<stdio.h>
int DAT[101];
int fac(int n){
    if(n==0){
        DAT[n]= 0;
    }
    else{
        if():
            DAT[n]= n*fac(n-1);
        }
        else{
            return DAT[n];
        }
}

int main()
{
    int i,f,a;
    printf("Enter the number of terms: ");
    scanf("%d",&a);
    for(i=1;i<=a;i++)
    {
        f=fac(i);
        printf("  %d",f);
    }

}

