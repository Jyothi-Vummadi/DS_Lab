#include<stdio.h>
int ls_recur(int a[],int n,int key,int l);
int main(){
    int n,i,key,pos;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched: ");
    scanf("%d",&key);
    pos = ls_recur(a,n,key,0);
    printf("Element position : %d",pos);
}
int ls_recur(int a[],int n,int key,int l){
    int i,pos;
    for(i=l;i<n;i++){
        if(a[i]==key){
            return i+1;
        }
        else{
            l = i+1;
            return ls_recur(a,n,key,l);
        }
    }
    return -1;
}
