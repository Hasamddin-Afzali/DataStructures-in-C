#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 10

typedef struct{
	int data[STACK_SIZE];
	int top;
}stack;
void initialize(stack *stk){
	stk->top = -1;
}
void push(stack *stk, int key){
	if(stk->top != STACK_SIZE -1){
		stk->top++;
		stk->data[stk->top] = key;
	}else{
		printf("Stack is Full !");
	}
}
int pop(stack *stk){
	if(stk->top != -1){
		return stk->data[stk->top--];
	}else{
		printf("stack is empty");
		return 0;
	}
}

main(){
	stack s1;
	initialize(&s1);
	push(&s1, 40);
	push(&s1, 50);
	push(&s1, 60);
	push(&s1, 70);
	push(&s1, 80);
	push(&s1, 90);
	push(&s1, 100);
	
	printf("%d", pop(&s1) );
}

