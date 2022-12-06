#include<stdio.h>
struct student{
    int roll_no;
    char *name;
    int age;
    int phy_marks;
    int chem_marks;
    int math_marks;
};
int main(){
    struct student s[5];
    for(int i=0;i<5;i++){
        scanf("%d",&s[i].roll_no);
        s[i].name = malloc(1024*sizeof(int));
        scanf("%s",s[i].name);
        scanf("%d",&s[i].age);
        scanf("%d",&s[i].phy_marks);
        scanf("%d",&s[i].chem_marks);
        scanf("%d",&s[i].math_marks);
    }
    for(int i=0;i<5;i++){
        printf("%d\t",s[i].roll_no);
        printf("%s\t",s[i].name);
        printf("%d\t",s[i].age);
        printf("%d\t",s[i].phy_marks);
        printf("%d\t",s[i].chem_marks);
        printf("%d\t",s[i].math_marks);
    }
}

