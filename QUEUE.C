#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 10
struct node{
	int data;
	struct node *next;
};
typedef struct{
	int count;
	struct node *front;
	struct node *rear;
}queue;
void initialize(queue *q){
	q->count = 0;
	q->front=q->rear = NULL	;
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
		printf("Queue is Full ! \n");
	}else{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = key;
		temp->next = NULL;
		
		if(isempty(q)){
		q->front=q->rear = temp;
		}else{
			q->rear->next = temp;
			q->rear = temp;
		}
	}
	q->count++;
}
int dequeue(queue *q){
	if(isempty(q)){
		printf("Queue is Empty ! \n");
		return -100;
	}else{
		int key = q->front->data;
		struct node *temp = q->front;
		q->front = temp->next;
		free(temp);
		q->count--;
		return key;
	}
}

main(){
	queue q;
	initialize(&q);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);	
	/*printf("%d ", dequeue(&q));
	printf("%d ", dequeue(&q));
	printf("%d ", dequeue(&q));
	printf("%d ", dequeue(&q));
	printf("%d ", dequeue(&q));
	printf("%d ", dequeue(&q));
	*/
}











