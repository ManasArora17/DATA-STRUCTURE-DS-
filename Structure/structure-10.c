#include<stdio.h>
struct customer{
    char *name;
    int account_no;
    int balance;
};
void displayByBalance(struct customer *c,int n,int balance){
    printf("\nName of customers having balance less than %d: \n",balance);
    for(int i=0;i<n;i++){
        if(c[i].balance<balance){
            printf("%s\n",c[i].name);
        }
    }
}
void displayIncrementBy100(struct customer *c,int n){
    printf("\nAccount Number which is incremented by $100: \n");
    for(int i=0;i<n;i++){
        if(c[i].balance>1000){
            printf("%d\t",c[i].account_no);
            printf("%d\n",c[i].balance+100);
        }
    }
}
int main(){
    struct customer *c;
    int n;
    printf("Enter the number of customers: ");
    scanf("%d",&n);
    c=malloc(n*sizeof(struct customer));
    printf("Enter the details of %d customer:\n",n);
    for(int i=0;i<n;i++){
        c[i].name = malloc(25*sizeof(char));
        scanf("%s",c[i].name);
        scanf("%d",&c[i].account_no);
        scanf("%d",&c[i].balance);
    }
    printf("___________________________________________________________\n");
    int balance;
    printf("Enter the Balance: ");
    scanf("%d",&balance);
    displayByBalance(c,n,balance);
    printf("________________________");
    displayIncrementBy100(c,n);
}


