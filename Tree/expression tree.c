#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACKSIZE 20
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};
struct Node* MakeNode(char x){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->left=NULL;
    p->right=NULL;
    p->data=x;
    p->next=NULL;
    return p;
}
void preorderTraversal(struct Node *T){
    if(T!=NULL){
        printf("%d",T->data);
        preorderTraversal(T->left);
        preorderTraversal(T->right);
    }
}
void inorderTraversal(struct Node *T){
    if(T!=NULL){
        inorderTraversal(T->left);
        printf("%d",T->data);
        inorderTraversal(T->right);
    }
}
void postorderTraversal(struct Node *T){
    if(T!=NULL){
        postorderTraversal(T->left);
        postorderTraversal(T->right);
        printf("%d",T->data);
    }
}
int prcd(char a, char b){
    if (a == '(') return 0;
    else if(b == '(') return 0;
    else if(b == ')') return 1;
    else{
        if(a == '^' || a == '*' || a == '/' || a == '%'){
            if(b == '^') return 0;
            else return 1;
        }
        else{
            if(b == '+' || b == '-') return 1;
            else return 0;
        }
    }
}


struct Stack_{
    struct Node* item[STACKSIZE];
    int TOP;
};
void Initialise(struct Stack_ *s){
    s->TOP=-1;
}
int IsEmpty(struct Stack_ *s){
    if (s->TOP==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void Push(struct Stack_ *s,struct Node* x){
    if(s->TOP==STACKSIZE-1){
        printf("stack overflow");
        exit(1);
    }
    s->TOP=s->TOP+1;
    s->item[s->TOP]=x;
}
struct Node* Pop(struct Node *T){
    if (isempty(s)){
        printf("stack underflow");
        exit(1);
    }
    struct Node* x=s->item[s->TOP];
    s->TOP=s->TOP-1;
    return x;
}
int StackTop(struct stack *s){
    int x=s->item[s->TOP];
    return x;
}
struct Node* BuildExpressionTree(char *expression,int n){
    Initialise(&character);
    Initialise(&symbol)
    while(i<n){
        char symb = expression[i];
        if(symb>='a'&&symb<='z'){
            struct Node* x = MakeNode(symb);
            Push(&character,x);
        }
        else(!(IsEmpty(&symbol)) && prcd(StackTop(&symbol),symb)){
            char op = Pop()
        }

}
int main(){
    struct Node *root = NULL;
    char E[100];
    printf("Enter the expression: ");
    gets(E);
    int n = strlen(E);
    BuildExpressionTree(E,n);
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");
    preorderTraversal(root);
    return 0;
}




