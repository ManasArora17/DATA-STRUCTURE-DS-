#include<stdio.h>
struct complex{
    int realPart;
    int complexPart;
};
int main(){
    struct complex c[2];
    for(int i=0;i<2;i++){
        printf("Enter the complex number-%d: ",i+1);
        scanf("%d",&c[i].realPart);
        scanf("%d",&c[i].complexPart);
    }
    int a = c[0].realPart+c[1].realPart;
    int b = c[0].complexPart+c[1].complexPart;
    printf("Resultant Complex number: %d + i%d",a,b);
}
