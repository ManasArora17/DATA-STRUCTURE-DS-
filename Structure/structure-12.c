#include<stdio.h>
struct worker{
    char *name;
    int salary;
    int working_hour;
};
void displayByWorking_hour(struct worker *w,int n){
    printf("\nName of workers whose salary increased by $50: \n");
    for(int i=0;i<n;i++){
        if(w[i].working_hour>10){
            printf("%s\t",w[i].name);
            printf("%d\n",w[i].salary+50);
        }
    }
}
int main(){
    struct worker *w;
    int n;
    printf("Enter the number of workers: ");
    scanf("%d",&n);
    w=malloc(n*sizeof(struct worker));
    printf("Enter the details of %d worker:\n",n);
    for(int i=0;i<n;i++){
        w[i].name = malloc(25*sizeof(char));
        scanf("%s",w[i].name);
        scanf("%d",&w[i].salary);
        scanf("%d",&w[i].working_hour);
    }
    printf("___________________________________________________________\n");
    displayByWorking_hour(w,n);
}


