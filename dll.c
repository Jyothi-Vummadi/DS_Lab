#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head = NULL,*tail = NULL,*curr,*temp,*temp1;
struct node *create(){
	int n;
	printf("Enter no. of elements : ");
	scanf("%d",&n);
	while(n--){
		curr = (struct node *)malloc(sizeof(struct node));
		scanf("%d",&(curr -> data));
		curr -> next = NULL;
		curr -> prev = NULL;
		if(head == NULL){
			tail = head = curr;
		}
		else{
			temp = tail;
			temp -> next = curr;
			curr -> prev = temp;
			tail = curr;
		}
	}
	return head;
}
struct node *insert_begin(int ele){
	curr = (struct node *)malloc(sizeof(struct node));
	curr -> data = ele;
	curr -> prev = NULL;
	curr -> next = head;
	head -> prev = curr;
	head = curr;
	return head;
}
struct node *insert_pos(int pos,int ele){
	curr = (struct node *)malloc(sizeof(struct node));
	curr -> data = ele;
	int c = 1;
	temp = head;
	while(c<pos){
		temp1 = temp;
		temp = temp -> next;
		c++;
	}
	temp1 -> next = curr;
	curr -> prev = temp1;
	curr -> next = temp;
	temp -> prev = curr;
	return head;
}
struct node *insert_end(int ele){
        curr = (struct node *)malloc(sizeof(struct node));
        curr -> data = ele;
	curr -> next = NULL;
	curr -> prev = tail;
	tail -> next = curr;
	tail = curr;
	return head;
}
struct node *delete_begin(struct node *head){
	temp = head;
	head = head -> next;
	head -> prev = NULL;
	printf("Deleted Element : %d\n",temp -> data);
	free(temp);
	return head;
}
struct node *delete_pos(struct node *head,int pos){
	int c = 1;
	temp = head;
	while(c < pos){
		temp1 = temp;
		temp = temp -> next;
		c++;
	}
	temp1 -> next = temp -> next;
	temp -> next -> prev = temp1;
	printf("Deleted Element : %d\n",temp -> data);
	free(temp);
	return head;
}
struct node *delete_end(struct node *tail){
	temp = tail;
	tail = tail -> prev;
	tail -> next = NULL;
	printf("Deleted Element : %d\n",temp -> data);
	free(temp);
	return head;
}
void display(struct node *head){
	temp = head;
	while(temp!=NULL){
		printf("%d -> ",temp -> data);
		temp = temp -> next;
	}
}
void reverse_display(struct node *tail){
	temp = tail;
	while(temp!=NULL){
		printf("%d -> ",temp -> data);
		temp = temp -> prev;
	}
}
int main(){
	int ch,ele,pos,c,key;
	while(1){
		printf("\n1 - Create\n2 - Insert at Beginning\n3 - Insert at Position\n4 - Insert at End\n5 - Delete at Beginning\n6 - Delete at position\n7 - Delete at End\n8 - Display\n9 - Reverse Display\n10 - Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: head = create();
				display(head);
				printf("\n");
				break;
			case 2: printf("Enter element to be added: ");
			        scanf("%d",&ele);
				head = insert_begin(ele);
				display(head);
				printf("\n");
				break;
			case 3: printf("Enter element to be added: ");
                                scanf("%d",&ele);
				printf("Enter position: ");
				scanf("%d",&pos);
                                head = insert_pos(pos,ele);
				display(head);
				printf("\n");
                                break;
			case 4: printf("Enter element to be added: ");
                                scanf("%d",&ele);
                                head = insert_end(ele);
				display(head);
				printf("\n");
                                break;
			case 5: head = delete_begin(head);
				display(head);
				printf("\n");
				break;
			case 6: printf("Enter position: ");
				scanf("%d",&pos);
				head = delete_pos(head,pos);
				display(head);
				printf("\n");
				break;
			case 7: head = delete_end(tail);
				display(head);
				printf("\n");
				break;
			case 8: display(head);
				printf("\n");
				break;
			case 9: reverse_display(tail);
				printf("\n");
				break;
			case 10: exit(0);
				 break;
		}
	}
}
