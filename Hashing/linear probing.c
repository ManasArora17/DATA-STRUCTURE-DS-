#include<stdio.h>
int main(){
    char TB[11]={'A','B','C','D','E','F','G','H','I','J','K'};
    int loc[11]={7,4,3,1,4,3,8,10,9,8,10};
    int RTB[11]={0};
    for(int i=0;i<11;i++){
        if(RTB[loc[i]]==0){
            RTB[loc[i]]=TB[i];
        }
        else{
            int j=(i+1);
            while(1){
                if(RTB[j]==0){
                    RTB[j]=TB[i];
                    break;
                }
                j++;
                j=j%11;
            }
        }
    }
    for(int i=0;i<11;i++){
        if(RTB[i]==0) printf("%d ",0);
        else printf("%c ",RTB[i]);
    }
}
