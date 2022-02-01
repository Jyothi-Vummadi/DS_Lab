#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *head=NULL,*curr,*temp,*temp1;
struct node *create(){
	int n;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	printf("Enter elements: ");
	while(n--){
		curr = (struct node *)malloc(sizeof(struct node));
		scanf("%d",&(curr->data));
		if(head==NULL){
			curr->link = curr;
			head = curr;
		}
		else{
			temp = head;
			while(temp->link!=head){
				temp = temp->link;
			}
			temp->link = curr;
			curr->link = head;
		}
	}
	return head;
}
struct node *insert_begin(int ele){
	curr = (struct node *)malloc(sizeof(struct node));
	curr->data = ele;
	temp = head;
	while(temp->link!=head){
		temp = temp->link;
	}
	temp->link = curr;
	curr->link = head;
	head = curr;
	return head;
}
struct node *insert_pos(int pos,int ele){
	int c = 1;
	curr = (struct node *)malloc(sizeof(struct node));
	curr->data = ele;
	temp = head;
	while(c<pos-1){
		temp = temp->link;
		c++;
	}
	curr->link = temp->link;
	temp->link = curr;
	return head;
}
struct node *insert_end(int ele){
	curr = (struct node *)malloc(sizeof(struct node));
	curr->data = ele;
	temp = head;
	while(temp->link!=head){
		temp = temp->link;
	}
	temp->link = curr;
	curr->link = head;
	return head;
}
struct node *delete_begin(struct node *head){
	temp = head;
	while(temp->link!=head){
		temp = temp->link;
	}
	temp1 = head;
	temp->link = temp1->link;
	head = temp1->link;
	printf("Deleted Element : %d\n",temp1->data);
	free(temp1);
	return head;
}
struct node *delete_pos(struct node *head,int pos){
    if (head == NULL){
        return head;
    }
    else
    {
        int c = 1;
        temp = head;
        while(c < pos) {
            temp1 = temp;
            temp = temp->link;
            c++;
        }
        temp1->link = temp->link;
	printf("Deleted Element : %d\n",temp->data);
        free(temp);
	return head;
    }
}
struct node *delete_end(struct node *head){
    if(head==NULL){
        return head;
    }
    else if (head ->link == head){
	printf("Deleted Element : %d\n",head->data);
        head = NULL;
        free(head);
    }
    else{
        temp = head;
        while(temp ->link!= head){
            temp1=temp;
            temp = temp->link;
        }
        temp1->link = temp -> link;
	printf("Deleted Element : %d\n",temp->data);
        free(temp);
	return head;
    }
}
void display(struct node *head){
     if (head == NULL){
        printf("\nList is empty");
     }
    else
    {
        temp = head;
        while(temp->link !=  head)
        {
            printf("%d->", temp->data);
            temp = temp->link;
        }
        printf("%d->", temp->data);
	printf("%d",head->data);
    }
}
int main(){
	int ch,ele,pos,c,key;
	while(1){
		printf("\n1 - Create\n2 - Insert at Beginning\n3 - Insert at Position\n4 - Insert at End\n5 - Delete at Beginning\n6 - Delete at position\n7 - Delete at End\n8 - Display\n9 - Exit\n");
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
			case 7: head = delete_end(head);
				display(head);
				printf("\n");
				break;
			case 8: display(head);
				printf("\n");
				break;
			case 9: exit(0);
				 break;
		}
	}
}
