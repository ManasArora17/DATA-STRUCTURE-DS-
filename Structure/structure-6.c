#include<stdio.h>
struct time{
    int hour;
    int min;
    int sec;
};
int main(){
    struct time t[2];
    for(int i=0;i<2;i++){
        printf("Enter the time %d: ",i+1);
        scanf("%d",&t[i].hour);
        scanf("%d",&t[i].min);
        scanf("%d",&t[i].sec);
    }
    int a = (t[0].sec+t[1].sec)/60;
    int b = (t[0].sec+t[1].sec)%60;
    int c = (t[0].min+t[1].min)/60+a;
    int d = ((t[0].sec+t[1].sec)+a)%60;
    int e = (t[0].hour+t[1].hour)+c-a;
    printf("Total  time: %d %d %d",e,d,b);
}

