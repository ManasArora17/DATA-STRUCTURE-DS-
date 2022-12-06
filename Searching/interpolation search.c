#include<stdio.h>
int interpolationSearch(int *arr,int low,int high,int key){
    int pos;
    if(low<=high && key>=arr[low] && key<=arr[high]){
        pos = low+((high-low)/(arr[high]-arr[low]))*(key-arr[low]);
        if(arr[pos]==key) return pos;
        if(arr[pos]<key) return interpolationSearch(arr,pos+1,high,key);
        if(arr[pos]>key) return interpolationSearch(arr,low,pos-1,key);
    }
}
int main(){
    int *arr,n,key;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the key: ");
    scanf("%d",&key);
    int result=interpolationSearch(arr,0,n-1,key);
    printf("index- %d",result);
}
