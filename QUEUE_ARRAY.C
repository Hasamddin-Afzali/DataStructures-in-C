#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 10
typedef struct{
	int count, front, rear, data[QUEUE_SIZE];	
}queue;

void initialize(queue *q){
	q->count = 0;
	q->front = 0;
	q->rear = -1;
}
int isfull(queue *q){
	if(q->count == QUEUE_SIZE){
		return 1;
	}else{
		return 0;
	}
}
int isempty(queue *q){
	if(q->count == 0){
		return 1;
	}else{
		return 0;
	}
}

void enqueue(queue *q, int key){
	if(isfull(q)){
		printf("Queue is FULL ! \n");
	}else{
		q->rear++;
		q->count++;
		if(q->rear == QUEUE_SIZE){
			q->rear = 0;
			q->data[q->rear] = key;
		}
	}
}

int dequeue(queue *q){
	if(isempty(q)){
		printf("Queue is Empty");
		return -100;
	}else{
		int key = q->data[q->front];
		q->front++;
		q->count--;
		if(q->front == QUEUE_SIZE){
			q->front = 0;
			return key;
		}
	}
}
void print(queue *q){
	int i = q->front;
	do{
		printf("%d", q->data[i]);
		i++;
		if(i==QUEUE_SIZE)
			i=0;
	}while(i!=q->rear++);
}
main(){
	queue q;
	initialize(&q);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);
	enqueue(&q, 60);
	enqueue(&q, 70);
	enqueue(&q, 80);
	enqueue(&q, 90);
	enqueue(&q, 100);
	printf("%d", dequeue(&q));
	printf("%d", dequeue(&q));
	printf("%d", dequeue(&q));
	printf("%d", dequeue(&q));
	printf("%d", dequeue(&q));
	
	//print(&q);
	
	
}


















