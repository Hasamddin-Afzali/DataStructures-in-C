#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
	struct node* prev;
};
struct node* addfront(struct node *head, int key){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->next = head;
	temp->prev = NULL;
	if(head != NULL){
		head->prev = temp;
		head=temp;
		return head;
	}
}
struct node* addlast(struct node* head, int key){
	struct node * temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->next = NULL;
	if(head == NULL){
		temp->prev = NULL;
		head = temp;
	}else{
		struct node * last = head;
		while(last->next != NULL){
			last=last->next;
		}
		temp->prev = last;
		last->next = temp;
	}
	return head;
}
struct node * delete_node(struct node * head, int key){
	if(head == NULL){
		printf("The DOUBLE LINKED LIST is empty !");
		return NULL;
	}
	struct node * temp = head;
	if(head->data == key){
		head = head->next;
		head->prev = NULL;
	free(temp);
	}else{
		while(temp->data != key)
			temp = temp ->next;
			temp->prev->next = temp->next;
		if(temp->next != NULL)
			temp->next->prev = temp-> prev;
			free(temp);	
	}
	return head;
}
void printlist(struct node * head){
	if(head == NULL){
		printf("The list is EMPTY !");
	}else{
		while(head != NULL){
			printf("%d", head->data);
			head= head->next;
		}
	}
}
void print_reverse(struct node * head){
	if(head == NULL){
		return;
	}else{
		print_reverse(head->next);
		printf("%d", head->data);
	}
}
int count(struct node * head){
	int counter = 0;
		while(head != NULL){
			counter++;
			head = head->next;
		}
	return counter;
}
main(){
	printf("----OPERATIONS IN DOUBLE LINKED LISTS----\n\n\n\n");
	struct node * head = NULL;
	int data, choice;
	
	while(1){
		printf("\n1 - To ADD in FRONT of DLLL\n ");
		printf("\n2 - To ADD in the LAST of DLL\n ");
		printf("\n3 - To DELETE the node form DLL\n ");
		printf("\n4 - To COUNT the node in  DLL\n ");
		printf("\n5 - To PRINT the LIST of DLL\n ");
		printf("\n6 - To PRINT REVERSE the LIST of DLL\n ");
		printf("\n10 - To  Exit \n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("\nPlease Enter the value you want to add in the FRONT of DLL ");
				scanf("%d", &data);
				head = addfront(head, data);
				break;
			case 2:
				printf("\nPlease Enter the value you want to add in the LAST of DLL ");
				scanf("%d", &data);
				head = addlast(head, data);
				break;
			case 3:
				printf("\nPlease Enter the value you want to DELETE from SSL ");
				scanf("%d", &data);
				head = delete_node(head, data);
				//printf("%d", head->data, "This value DELETED");
				break;
			case 4:
				printf("%d", count(head));
				break;
			case 5:
				printlist(head);
				break;
			case 6:
				print_reverse(head);
				break;
			case 10:
				exit(1);
				
		}
	}
}
