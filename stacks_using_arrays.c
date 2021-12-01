#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int top = -1,stack[SIZE];
void push(int ele){
    if(top==SIZE-1){
        printf("Stack Overflow");
    }
    else{
        stack[++top] = ele;
    }
}
int pop(){
    if(top==-1){
        printf("Stack Underflow");
    }
    else{
        return stack[top];
    }
}
int peek(){
    if(top==-1){
        return -1;
    }
    else{
        return stack[top];
    }
}
void display(){
    if(top == -1){
        printf("Stack Underflow");
    }
    else{
        for(int i = top; i>=0;i--){
            printf("%d\n",stack[i]);
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
                     printf("Popped Element : %d",ele);
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
