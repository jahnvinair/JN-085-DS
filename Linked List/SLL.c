#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* link;
};

struct Node* create_newNode(int data){
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->link=NULL;
	return  newnode;
}

void insert_beg(struct Node** head,int data){
	struct Node* newnode=create_newNode(data);
	newnode->link=*head;
	*head=newnode;
}

void insert_end(struct Node**  head,int data){
	struct Node* newnode=create_newNode(data);
	if (*head==NULL){
		*head=newnode;
	}
	else{
		struct Node* temp=*head;
		while (temp->link!=NULL){
			temp=temp->link;
		}
		temp->link=newnode;
	}
}

void insert_rand(struct Node** head,int data, int pos){
	if (pos<1){
		printf("Invalid command!");
		return;
	}
	else if (pos==1){
		insert_beg(head,data);
		return;
	}
	struct Node* newnode=create_newNode(data);
	struct Node* temp=*head;
	
	for (int i=1;i<pos-1 && temp!=NULL;i++){
		temp=temp->link;
	}
	
	if (temp==NULL){
		printf("Position exceeds legal length.\n");
	}
	else{
		newnode->link=temp->link;
		temp->link=newnode;
	}
}

void delete_first(struct Node** head){
	if (*head==NULL){
		printf("Empty list, delete not possible.");
		return;
	}
	else{
		struct Node* temp=*head;
		*head=temp->link;
		free(temp);
	}
}

void delete_last(struct Node** head){
	if (*head==NULL){
		printf("Empty list, delete not possible.");
		return;
	}
	if((*head)->link==NULL){
		free(*head);
		*head=NULL;
		return;
	}
	struct Node* temp=*head;
	while(temp->link->link!=NULL){
		temp=temp->link;
	}
	free(temp->link);
	temp->link=NULL;
}

void delete_rand(struct Node** head,int pos){
	if (*head==NULL){
		printf("Empty list, delete not possible.");
		return;
	}
	if (pos<1){
		printf("Invalid command!");
		return;
	}
	else if (pos==1){
		delete_first(head);
		return;
	}
	struct Node* temp=*head;
	struct Node* prev=NULL;
	
	for (int i=1;i<pos && temp!=NULL;i++){
		prev=temp;
		temp=temp->link;
	}
	
	if (temp==NULL){
		printf("Position exceeds legal length.\n");
	}
	else{
		prev->link=temp->link;
		free(temp);
	}
}

void reversal(struct Node** head){
	struct Node* prev=NULL;
	struct Node* current=*head;
	struct Node* next=NULL;
	
	while(current!=NULL){
		next=current->link;
		current->link=prev;
		prev=current;
		current=next;
	}
	*head=prev;
}

void display(struct Node* head){
	struct Node* temp=head;
	while (temp!=NULL){
		printf("%d ->",temp->data);
		temp=temp->link;
	}
	printf("NULL\n");
}


int main(){
	struct Node* head=NULL;
	int choice,num,position;
	
	while (1){	
		printf("MENU\n");
		printf("1. Insert at beginning \n2. Insert at end \n3. Insert at any position");
		printf("\n4. Delete at beginning \n5. Delete at end \n6. Delete at any position\n7.Reversal \n8.Quit");
		printf("\nEnter choice(1-8):");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter number to insert:");
				scanf("%d",&num);
				insert_beg(&head,num);
				display(head);
				break;
			
			case 2:
				printf("Enter number to insert:");
				scanf("%d",&num);
				insert_end(&head,num);
				display(head);
				break;
				
			case 3:
				printf("Enter number to insert:");
				scanf("%d",&num);
				printf("Enter position to enter in:");
				scanf("%d",&position);
				insert_rand(&head,num,position);
				display(head);
				break;
				
			case 4:
				delete_first(&head);
				display(head);
				break;
				
			case 5:
				delete_last(&head);
				display(head);
				break;
				
			case 6:
				printf("Enter position to delete from:");
				scanf("%d",&position);
				delete_rand(&head,position);
				display(head);
				break;
				
			case 7:
				reversal(&head);
				display(head);
				break;
				
			case 8:
				exit(0);
		}
	}
	//insertion
	/*insert_end(&head,2);
	insert_beg(&head,1);
	insert_end(&head,3);
	insert_rand(&head,20,3);
	insert_end(&head,15);
	insert_beg(&head,21);
	printf("List:");*/
	
	//display(head);
	
	//deletion
	/*delete_first(&head);
	delete_last(&head);
	delete_rand(&head,2);
	printf("List after deletion:");*/
	//display(head);
	
	return 0;
}
