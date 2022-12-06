#include<stdio.h>
#include"LinkedList.h"
struct Node* binarySearch(struct Node **START,int key){
    struct Node *mid;
    if(START!=NULL){
        mid = middleElement(START);
        if(mid->info == key){
            return mid;
        }
        else if(mid->info > key){
            mid->Next = NULL;
            binarySearch(START,key);
        }
        else{
            (*START)= mid->Next;
            binarySearch(START,key);
        }
    }
    return NULL;
}
int main(){
    struct Node *START,*p;
    START = NULL;
    InsEnd(&START,1);
    InsEnd(&START,2);
    InsEnd(&START,3);
    InsEnd(&START,4);
    InsEnd(&START,5);
    Traverse(&START);
    p=binarySearch(&START,4);
    if(p!=NULL) printf("\nElement is present");
    else printf("\nElement is not present");
}
