#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int f = -1,r = -1,queue[SIZE];
void enqueue(int ele){
	if(r == SIZE - 1){
		printf("Queue Overflow");
	}
	else{
		queue[++r] = ele;
	}
	if(f == -1){
		f = 0;
	}
}
void dequeue(){
	if(f == -1){
		printf("Queue Underflow");
	}
	else if(f == r){
		printf("Dequeued Element : %d\n",queue[f]);
		f = r = -1;
	}
	else{
		printf("Dequeued Element : %d\n",queue[f++]);
	}
}
void display(){
	int i;
	if(f == -1){
		printf("Queue Underflow");
	}
	else{
		for(i = f;i <= r;i++){
			printf("%d | ",queue[i]);
		}
	}
}
int main(){
	int ch,ele;
	while(1){
		printf("\n1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:printf("Element : ");
			       scanf("%d",&ele);
			       enqueue(ele);
			       display();
                               printf("\n");
			       break;
			case 2:dequeue();
			       display();
			       printf("\n");
			       break;
			case 3:display();
			       printf("\n");
			       break;
			case 4: exit(0);
		}
	}
}

