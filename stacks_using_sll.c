#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *top = NULL, *curr,*temp;
void push(int ele){
    curr = (struct node *)malloc(sizeof(struct node));
    curr -> data = ele;
    if(top == NULL){
        curr -> link = NULL;
    }
    else{
        curr -> link = top;
    }
    top = curr;
}
int pop(){
    int x;
    temp = top;
    if(top == NULL){
        return -1;
    }
    else{
        top = top -> link;
        x =  temp -> data;
        free(temp);
        return x;
    }
}
int peek(){
    if(top == NULL){
        return -1;
    }
    else{
        return top -> data;
    }
}
void display(){
    if(top == NULL){
        printf("Stack Underflow");
    }
    else{
        temp = top;
        while(temp!=NULL){
            printf("%d\n",temp -> data);
            temp = temp -> link;
        }
    }
}
int main(){
    int ch,ele;
    while(1){
        printf("\n1 : push\n2 : pop\n3 : peek\n4 : display\n5 : quit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : printf("Enter element to be pushed : ");
                     scanf("%d",&ele);
                     push(ele);
                     break;
            case 2 : ele = pop();
                     if(ele == -1){
                        printf("Stack Underflow");
                     }
                     else{
                         printf("Popped Element : %d",ele);
                     }
                     break;
            case 3 : ele = peek();
                     if(ele == -1){
                        printf("Stack Underflow");
                     }
                     else{
                        printf("Top Element : %d",ele);
                     }
                     break;
            case 4 : display();
                     break;
            case 5 : exit(0);
        }
    }
}

