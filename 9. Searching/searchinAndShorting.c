// Online C compiler to run C program online
#include <stdio.h>
void ShortTheArr(int arr[], int size){
    for(int i=0;i<size-1;i++){
        int shorted=0;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                shorted=1;
            }
        }
        if(shorted==0){
            printf("Array got shorted : ");
            break;
        }
    }
    
}

int searchInTheArr(int arr[],int left,int right,int target){
    while(left<=right){
        int mid= left+(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }
        //target is greater than mid it means no need to check in the left side of mid (eliminate)
        else if(target>arr[mid]){
            left=mid+1;
        }
        //target is lesser than mid so needs to eliminate the elemnets accordingly
        else{
            right=mid-1;
        }
    }
}

printTheArr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int array[]={10,15,9,2,0,8,3};
    int size=sizeof(array)/sizeof(array[0]);
    ShortTheArr(array,size);
    printTheArr(array,size);
    int val=searchInTheArr(array,0,size-1,10);
    printf("Target found at index : %d",val);
    
}