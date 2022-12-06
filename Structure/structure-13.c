#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct library{
    int accession_number;
    char name_of_author[25];
    int book_title[25];
    int flag;
};
void Input(struct library *ptr,int n){
    for(int i=0;i<n;i++){
        scanf("%d %s %s %d",&ptr[i].accession_number,&ptr[i].name_of_author,&ptr[i].book_title,&ptr[i].flag);
    }
}
void Output(struct library *ptr,int n){
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%s\t%d\n",ptr[i].accession_number,ptr[i].name_of_author,ptr[i].book_title,ptr[i].flag);
    }
}
void displayInfo(struct library *ptr,int n){
    char s[25];
    printf("Enter the Title of the book: ");
    scanf("%s",&s);
    int i=0;
    while(i<n){
        if(strcmp(s,ptr[i].book_title)==0){
            printf("%d\t%s\t%d\n",ptr[i].accession_number,ptr[i].name_of_author,ptr[i].flag);
        }
        i++;
    }

}
void addBook(struct library *ptr,int n){
    printf("Enter the information: \n");
    ptr = realloc(ptr,1*sizeof(struct library));
    scanf("%d %s %s %d",&ptr[n].accession_number,&ptr[n].name_of_author,&ptr[n].book_title,&ptr[n].flag);
}
void displayByAuthor(struct library *ptr,int n){
    char s[25];
    printf("Enter the Author Name: ");
    scanf("%s",&s);
    int i=0;
    while(i<n){
        if(strcmp(s,ptr[i].name_of_author)==0){
            printf("%d\t%s\t%d\n",ptr[i].accession_number,ptr[i].book_title,ptr[i].flag);
        }
        i++;
    }
}
void displayNumByTitle(struct library *ptr,int n){
    char s[25];
    printf("Enter the Title of the book: ");
    scanf("%s",&s);
    int i=0,c=0;
    while(i<n){
        if(strcmp(s,ptr[i].book_title)==0){
            c++;
        }
        i++;
    }
    printf("%d\n",c);
}

void issueBook(struct library *ptr,int n){
    char s[25];
    printf("Enter the Title of the book: ");
    scanf("%s",&s);
    int i=0;
    while(i<n){
        if(strcmp(s,ptr[i].book_title)==0){
            ptr[i].flag=1;
            break;
        }
        i++;
    }
    printf("Book Issued successfully.\n");

}
int main(){
    int n;
    struct library *p;
    printf("==========Library==========\n");
    printf("Enter the number of books: ");
    scanf("%d",&n);
    printf("Entry(accession number, name of author, book title and flag)\n");
    p = (struct library *)malloc(n*sizeof(struct library));
    Input(p,n);
    printf("________________________________________________\n");
    printf("Enter 1 To Display the information of Book\n");
    printf("Enter 2 To Add a new book\n");
    printf("Enter 3 To Display all the books in the library of a particular author.\n");
    printf("Enter 4 To Display number of books of particular title.\n");
    printf("Enter 5 To Display the information of all books in library.\n");
    printf("Enter 6 To issue a book:\n");
    printf("Enter 7 to Exit library\n");
    while(1){
        int option;
        printf("Enter your option: ");
        scanf("%d",&option);
        switch (option){
            case 1:
                displayInfo(p,n);
                break;
            case 2:
                addBook(p,n);
                n++;
                break;
            case 3:
                displayByAuthor(p,n);
                break;
            case 4:
                displayNumByTitle(p,n);
                break;
            case 5:
                Output(p,n);
                break;
            case 6:
                issueBook(p,n);
                break;
            case 7:
                exit(1);
            default: printf("Invalid Option.");
        }
    }
    return 0;
}
