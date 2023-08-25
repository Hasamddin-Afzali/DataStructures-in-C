	#include<stdio.h>
	#include<stdlib.h>
	//Create a Single linked list SSL
	struct node{
		int data;
		struct node * next;
	};
	
	//Add in front of a single linked list
	struct node *addFront(struct node *head, int key){
	    struct node *temp = (struct node*)malloc(sizeof(struct node));
	    temp->next = head;
		temp->data = key;
	    head=temp;
	    return head;
	}
	//Add in the last of single linked list
	struct node *addlast(struct node *head, int key){
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = key;
		temp->next = NULL;
		
		if(head == NULL){
			head=temp;
		}else{
			struct node * last = head;
			while(last->next != NULL){
				last = last->next;
			}last->next = temp;
		}
		return head;
	}
	//locate or search in single linked lists
	struct node *locate(struct node *head, int key){
		struct node *locate = NULL;
		while(head != NULL){
			if(head->data != key){
				head = head->next;
			}else{
				locate = head;
				break;
			}
		}
		return(locate);
	}
	
	struct node* copy(struct node* head) {
		struct node* kopya = NULL;
		if(head != NULL)
			do {
				concatenate(kopya, cons(head -> data));
				head = head -> next;
		} 	while(head != NULL);
		return kopya;
	}
	
	struct node *destroy(struct node *head) {
		if(head == NULL) {
		printf("Liste zaten bos\n");
		return;
		}
		struct node *temp2;
			while(head!= NULL) {
				temp2=head;
				head = head->next;
				free(temp2);
		}
		return head;
	}
	struct node *delete_node(struct node*head, int key){
		if(head == NULL){
			printf("Node is empty");
			return NULL;
		}
		struct node * temp = head;
		if(head->data == key){
			head = head->next;
			free(temp);
		}
		else{
			while(temp->next != NULL && temp->next->data != key)
				temp=temp->next;
				if(temp->next = NULL){
					struct node *deleted = temp->next;
					temp->next = deleted->next;
					free(deleted);
				}
			
		}
		return head;
	}
	void printlist(struct node * head){
		if(head == NULL){
			printf("This List is Empty");
		}else{
			while(head != NULL){
				printf("%d \t ", head->data);
				head = head->next;
			}
		}
	}
	
	void print_reverse(struct node*head){
		if(head==NULL)
			return;
			print_reverse( head->next);
			printf("%d -- T ", head->data);
	}
	
	int count(struct node*head){
		int counter = 0;
		while(head != NULL){
			counter++;
			head= head->next;
		}
		return counter;
	}
	struct node* sort(struct node* head) {
    struct node* current = head;
    struct node* index = NULL;
    int temp;

    if (head == NULL) {
        return head;
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    return head;
}

	
	main(){
		printf("----OPERATIONS IN SINGLE LINKED LISTS----\n\n\n\n");
		struct node* head = NULL;
		int data, choice; 
		
		while(1){
			printf("\n1 - To ADD in FRONT of SSL\n ");
			printf("\n2 - To ADD in the LAST of SLL\n ");
			printf("\n3 - To DELETE the node form SLL\n ");
			printf("\n4 - To COUNT the node in  SLL\n ");
			printf("\n5 - To PRINT the LIST of SLL\n ");
			printf("\n6 - To PRINT REVERSE the LIST of SLL\n ");
			printf("\n8 - To PRINT sorted of the LIST of SLL\n ");
			printf("\n10 - To  Exit \n");
			scanf("%d", &choice);
			switch(choice){
				case 1:
					printf("\nPlease Enter the value you want to add in the FRONT of SSL ");
					scanf("%d", &data);
					head = addfront(head, data);
					break;
				case 2:
					printf("\nPlease Enter the value you want to add in the LAST of SSL ");
					scanf("%d", &data);
					head = addlast(head, data);
					break;
				case 3:
					printf("\nPlease Enter the value you want to DELETE from SSL ");
					scanf("%d", &data);
					head = delete_node(head, data);
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
				case 7:
					printf("\n please Enter the value you want to SEARCH ");
					scanf("%d", &data);
					head = locate(head, data);
				case 8:
			        head = sort(head);
			        break;
				case 10:
					exit(1);
			}
		}
	}
