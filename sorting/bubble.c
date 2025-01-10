#include<stdio.h>

int main(){
    int arr[5]={5,4,3,2,1};
    int first=1;
    for(int i=0 ; i<5 ; ++i){
        printf("PASS : (%d)\n" , i+1);
            for(int k=0 ; k<5 ; k++){
                printf(" %d ",arr[k]);
                }
           printf("\n");
        for(int j=0 ; j<5-i-1 ; ++j){
            first=0;
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            for(int k=0 ; k<5 ; k++){
                printf(" %d ",arr[k]);
                }
        
        printf("\n");
        } 
    }
    printf("RESULT : ");
    for(int i=0 ; i<5 ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}