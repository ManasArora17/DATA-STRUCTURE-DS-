#include<stdio.h>
#include<math.h>
int prime(int n){
    int e=0;
    for(int i=2;i<pow(n,0.5)+1;i++){
        if(n%i==0){
            e=1;
            break;
        }
    }
    if(e==0 && n!=1){
        return(n);
    }
    else{
        return 0;
    }
}
int nearestPrime(int n){
    while(1){
        n--;
        if(prime(n)){
            return(n);
        }
    }
}
int divisionHashing(int key,int TS){
    int np = nearestPrime(TS);
    int a = key%np;
    return a;
}
int main(){
    int *T,TS;
    printf("Enter the table size: ");
    scanf("%d",&TS);
    T = calloc(TS,sizeof(int));
    int key[4]={122353,3886317,2940405,7662334};
    printf("key         value\n");
    printf("-----------------\n");
    for(int i=0;i<4;i++){
        printf("%d ---> %d\n",key[i],divisionHashing(key[i],TS));
    }
    return 0;

}
