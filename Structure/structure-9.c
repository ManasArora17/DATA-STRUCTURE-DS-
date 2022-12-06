#include<stdio.h>
struct student{
    int roll_no;
    char *name;
    int age;
    char *address;
};
void displayByAge(struct student *s,int n,int age){
    printf("\nName of Students having age %d: \n",age);
    for(int i=0;i<n;i++){
        if(s[i].age==age){
            printf("%s\n",s[i].name);
        }
    }
}
void displayEvenRoll_no(struct student *s,int n){
    printf("\nName of Students having even roll_no: \n");
    for(int i=0;i<n;i++){
        if(s[i].roll_no%2==0){
            printf("%s\n",s[i].name);
        }
    }
}
void displayByRoll_no(struct student *s,int n,int roll_no){
    printf("\nDetail of Student: \n");
    for(int i=0;i<n;i++){
        if(s[i].roll_no==roll_no){
            printf("%s\t",s[i].name);
            printf("%d\t",s[i].age);
            printf("%s\n",s[i].address);
            break;
        }
    }
}
int main(){
    struct student *s;
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    s=malloc(n*sizeof(struct student));
    printf("Enter the details of %d student:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i].roll_no);
        s[i].name = malloc(25*sizeof(char));
        scanf("%s",s[i].name);
        scanf("%d",&s[i].age);
        s[i].address=malloc(100*sizeof(char));
        scanf("%s",s[i].address);
    }
    printf("___________________________________________________________\n");
    int age;
    printf("Enter the Age: ");
    scanf("%d",&age);
    displayByAge(s,n,age);
    printf("________________________");
    displayEvenRoll_no(s,n);
    printf("________________________");
    int roll_no;
    printf("\nEnter the Roll_no: ");
    scanf("%d",&roll_no);
    displayByRoll_no(s,n,roll_no);
    return 0;
}

