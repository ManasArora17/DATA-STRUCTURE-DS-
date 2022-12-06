#include<stdio.h>
struct date{
    int day;
    int month;
    int year;
};
int main(){
    struct date d[2];
    for(int i=0;i<2;i++){
        printf("Enter the date-%d: ",i+1);
        scanf("%d",&d[i].day);
        scanf("%d",&d[i].month);
        scanf("%d",&d[i].year);
    }
    printf("____________________________");
    if(d[0].day==d[1].day && d[0].month==d[1].month && d[0].year==d[1].year){
        printf("\nDates are Equal");
    }
    else{
        printf("\nDates are Unequal");
    }
}
