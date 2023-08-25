#include <stdlib.h>
#include <stdio.h>


#define STACK_SIZE 10
typedef struct{
	int data[STACK_SIZE];
	int top;
}stack;

void initialize(stack * stk){
	stk->top = -1;
}
void push(stack *stk, int key){
	if(stk->top == STACK_SIZE -1){
		printf("Stack is Full ! \n");
		return;
	}else{
		stk->data[stk->top++] = key;
	}
}

void pop(stack * stk){
	if(stk->top == -1){
		printf("Stack os Empty ! \n");
		return 0;
	}else{
		return stk->data[stk->top--];
	}
}

int main(){
	
}
