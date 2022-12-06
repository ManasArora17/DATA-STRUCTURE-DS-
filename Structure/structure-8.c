#include<stdio.h>
struct complex{
    int realPart;
    int imaginaryPart;
};
int main(){
    struct complex c[2];
    for(int i=0;i<2;i++){
        printf("Enter the complex number-%d: ",i+1);
        scanf("%d",&c[i].realPart);
        scanf("%d",&c[i].imaginaryPart);
    }
    int a = c[0].realPart+c[1].realPart;
    int b = c[0].imaginaryPart+c[1].imaginaryPart;
    printf("Add two complex number: %d + i%d\n",a,b);
    int c1 = c[0].realPart-c[1].realPart;
    int d = c[0].imaginaryPart-c[1].imaginaryPart;
    printf("Subtract two complex number: %d + i(%d)\n",c1,d);
    int e = (c[0].realPart*c[1].realPart)-(c[0].imaginaryPart*c[1].imaginaryPart);
    int f = (c[0].realPart*c[1].imaginaryPart)+(c[0].imaginaryPart*c[1].realPart);
    printf("multiply two complex number: %d + i(%d)",e,f);
}
