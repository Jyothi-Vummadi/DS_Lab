#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int a[], int n){
	int i,j,x;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				x = a[j];
				a[j] = a[j+1];
				a[j+1] = x;
			}
		}
	}
}
void selection_sort(int a[],int n){
	int i,j,min,x;
	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min = j;
			}
		}
		x = a[min];
		a[min] = a[i];
		a[i] = x;
	}
}
void insertion_sort(int a[],int n){
	int i,j,key;
	for(i=1;i<n;i++){
		key = a[i];
		j = i-1;
		while(j>=0 && a[j]>key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}
void display(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
int main(){
	int n,i,ch;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
        printf("\n1 - Bubble Sort\n2 - Selection Sort\n3 - Insertion Sort\nEnter your choice: ");
	scanf("%d",&ch);
	printf("Elements in given order: ");
	display(a,n);
	printf("\nElements in sorted order: ");
	switch(ch){
		case 1: bubble_sort(a,n);
			display(a,n);
			break;
		case 2: selection_sort(a,n);
                        display(a,n);
                        break;
		case 3: insertion_sort(a,n);
                        display(a,n);
                        break;
	}
	printf("\n");
}
