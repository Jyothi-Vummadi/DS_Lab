#include<stdio.h>
int bs_recur(int a[],int l,int h,int key);
int main(){
    int n,key,i,pos;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter Elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched: ");
    scanf("%d",&key);
    int l = 0,h = n-1;
    pos = bs_recur(a,l,h,key);
    printf("Element Position: %d",pos);
}
int bs_recur(int a[],int l,int h,int key){
    int m,i;
    for(i=l;i<h+1;i++){
        if(a[i]==key){
            return i+1;
        }
        else if(a[i] > key){
            h = i-1;
            return bs_recur(a,l,i-1,key);
        }
        else{
            l = i+1;
            return bs_recur(a,i+1,h,key);
        }
    }
    return -1;
}
