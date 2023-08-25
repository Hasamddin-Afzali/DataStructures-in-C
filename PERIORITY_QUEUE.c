#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 10

struct priority_queue{
	int data[QUEUE_SIZE +1];
	int cnt;
};
typedef struct priority_queue pqueue;
void initialize(pqueue *p){
	p->cnt = 0;
}
void insert(pqueue *p, int key){
	if(p->cnt == QUEUE_SIZE)
		printf("Queue is Full !");
	else{
		p->cnt++;
		p->data[p->cnt] = key;
		int iter = p->cnt;
		while(iter != 1 && p->data[iter]< p->data[iter/2]){
			int temp = p->data[iter];
			p->data[iter] = p->data[iter/2];
			p->data[iter/2] = temp;
			iter = iter/2;
		}
	}
}

int dqueue(pqueue *p){
	if(p->cnt == 0){
		printf("Queue is Empty !");
		return	-100;
	}else{
		int x = p->data[1];
		p->data[1] = p->data[p->cnt];
		p->cnt--;
		int iter =1;
		while(2*iter<=p->cnt && (p->data[iter] > p->data[2*iter] || p->data[iter] > p->data[2*iter+1])){
			if(p->data[2*iter] > p->data[2*iter+1]){
				int temp = p->data[2*iter];
				p->data[2*iter] = p->data[iter];
				p->data[iter] = temp;
				//swap(&p->data[iter], &p->data[2*iter]);
				iter = 2*iter;
			}else{
				int temp = p->data[2*iter+1];
				p->data[2*iter] = p->data[iter];
				p->data[iter] = temp;
				//swap(&p->data[iter], &p->data[2*iter+1]);
				iter = 2*iter+1;
			}
		}
			return x;	
	}

}
void print_heap(pqueue *p){
	if(p->cnt == 0){
		printf("Queue is Empty !");
	}else{
		int i;
		for(i=1; i<=p->cnt; i++){
			printf("%6d", p->data[i]);
		}
	}
}

main(){
	
	pqueue p;
	initialize(&p);
	insert(&p, 50);
	insert(&p, 10);
	insert(&p, 25);
	insert(&p, 20);
	insert(&p, 60);
	
	print_heap(&p);
	printf("\n min= %d \n", dqueue(&p) );
	print_heap(&p);
}





















