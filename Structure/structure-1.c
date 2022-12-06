#include<stdio.h>
struct student{
    char *name;
    int roll_no;
    int *marks;
};
int main(){
    struct student s;
    s.name=malloc(1024*sizeof(char));
    scanf("%s",s.name);
    scanf("%d",&s.roll_no);
    s.marks=malloc(1024*sizeof(int));
    for(int i=0;i<6;i++){
        scanf("%d",&s.marks[i]);
    }
    for(int i=0;i<2;i++){
        int min=s.marks[i];
        int k = i;
        for(int j=i;j<6;j++){
            if(min>s.marks[j]){
                k=j;
                min = s.marks[j];
            }
        }
        int t = s.marks[i];
        s.marks[i] = s.marks[k];
        s.marks[k] = t;
    }
    printf("\n");
    float sum=0;
    for(int i=2;i<6;i++){
        sum = sum+s.marks[i];
    }
    float p = sum/4;
    printf("Name of the student: %s\n",s.name);
    printf("Roll No.: %d\n",s.roll_no);
    printf("Percentage of best 4 subject: %0.2f\n",p);
    if(p>=95){
        printf("Status: Eligible");
    }
    else{
        printf("Status: Not Eligible");
    }
}
