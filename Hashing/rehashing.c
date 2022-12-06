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
    char TB[11]={'A','B','C','D','E','F','G','H','I','J','K'};
    int loc[11]={7,4,3,1,4,3,8,10,9,8,10};
    int RTB[11]={0};
    for(int i=0;i<11;i++){
        if(RTB[loc[i]]==0){
            RTB[loc[i]]=TB[i];
        }
        else{
            int j=i+folding(loc[i],11);
            int k=1;
            while(1){
                if(RTB[j]==0){
                    RTB[j]=TB[i];
                    break;
                }
                j=j+k*j;
                j=j%11;
                k++;
            }
        }
    }
    for(int i=0;i<11;i++){
        if(RTB[i]==0) printf("%d ",0);
        else printf("%c ",RTB[i]);
    }
}

