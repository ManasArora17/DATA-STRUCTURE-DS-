#include<stdio.h>
struct height{
    int feet;
    int inch;
};
int main(){
    struct height h[2];
    for(int i=0;i<2;i++){
        printf("Enter height - %d: ",i+1);
        scanf("%d",&h[i].feet);
        scanf("%d",&h[i].inch);
    }
    int a=(h[0].inch+h[1].inch)/12;
    int b=(h[0].inch+h[1].inch)%12;
    int c=(h[0].feet+h[1].feet)+a;
    printf("Total height: %d %d",c,b);

}
