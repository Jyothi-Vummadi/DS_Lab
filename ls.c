#include<stdio.h>
int ls(int a[],int n,int key);
int main(){
    int n,key,i,ans,a[20],pos=-1;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched: ");
    scanf("%d",&key);
    for(i=0;i<n;i++){
            if(a[i]==key){
                pos = i+1;
                break;
            }
    }
    printf("Element position : %d",pos);
}
