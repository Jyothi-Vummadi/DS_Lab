#include<stdio.h>
int bs(int a[],int key);
int main(){
    int n,key,i,pos = -1;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched: ");
    scanf("%d",&key);
    int l = 0,h=n-1,m;
    while(l<=h){
        m = (l+h)/2;
        if(a[m]==key){
            pos = m+1;
            break;
        }
        else if(a[m] > key){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    printf("Element position: %d",pos);
}
