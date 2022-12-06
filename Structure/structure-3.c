#include<stdio.h>
struct student{
    char *name;
    int roll_no;
    int section;
    char *address;
    float percentage;
    int mobile_no;
};
int main(){
    struct student s[5];
    for(int i=0;i<15;i++){
        s[i].name = malloc(1024*sizeof(char));
        scanf("%s",s[i].name);
        scanf("%d",&s[i].roll_no);
        scanf("%d",&s[i].section);
        s[i].address = malloc(1024*sizeof(char));
        scanf("%s",s[i].address);
        scanf("%f",&s[i].percentage);
        scanf("%d",&s[i].mobile_no);
    }
    for(int i=0;i<15;i++){
        printf("%s\t",s[i].name);
        printf("%d\t",s[i].roll_no);
        printf("%d\t",s[i].section);
        printf("%s\t",s[i].address);
        printf("%f\t",s[i].percentage);
        printf("%d\n",s[i].mobile_no);
    }
    return 0;
}
