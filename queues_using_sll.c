#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *f = NULL,*r = NULL,*curr;
void enqueue(int ele){
	curr = (struct node *)malloc(sizeof(struct node));
	curr -> data = ele;
	curr -> link = NULL;
	if(f == NULL){
		f = r = curr;
	}
	else{
		r -> link = curr;
		r = curr;
	}
}
void dequeue(){
	if(f == NULL){
		printf("Queue Underflow");
	}
	else if(f == r){
		printf("Dequeued Element : %d\n",f -> data);
		f = r = NULL;
	}
	else{
		printf("Dequeued Element : %d\n",f -> data);
		f = f-> link;
	}
}
void display(){
	if(f == NULL){
		printf("Queue Underflow");
	}
	else{
		curr = f;
		while(curr!=NULL){
			printf("%d | ",curr->data);
			curr = curr -> link;
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
