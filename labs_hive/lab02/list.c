#include "list.h"

/* Add a node to the end of the linked list. Assume head_ptr is non-null. */
void append_node (node** head_ptr, int new_data) {
	/* First lets allocate memory for the new node and initialize its attributes */
	/* YOUR CODE HERE */
	node * new_node=(node *) malloc(sizeof(node));
	new_node->val=new_data;
	new_node->next=NULL;
	/* If the list is empty, set the new node to be the head and return */
	if (*head_ptr == NULL) {
		/* YOUR CODE HERE */
		*head_ptr=new_node;
		return;
	}
	node* curr = *head_ptr;
	while (curr->next!= NULL) {
		curr = curr->next;
	}
	/* Insert node at the end of the list */
	/* YOUR CODE HERE */
	curr->next=new_node;
}

/* Reverse a linked list in place (in other words, without creating a new list).
   Assume that head_ptr is non-null. */
void reverse_list (node** head_ptr) {
	node* prev = NULL;
	node* curr = *head_ptr;
	node* next = NULL;
	

	while (curr != NULL) {
		/* INSERT CODE HERE */
		next=curr->next;
		if(next==NULL)
		{
				
				curr->next=prev;
				*head_ptr = curr;
				return;
			
		}
	
		curr->next=prev;
			
		node * temp=next->next;
		prev=curr;
		curr=next;
		next=temp;
		
		
		
		
		
	}
	/* Set the new head to be what originally was the last node in the list */
	/* INSERT CODE HERE */
	
}
//void printList(node** list){
//	node * curr=*list;
//	
//	while(curr!=NULL){
//		printf("%d",curr->val);
//		if(curr->next!=NULL)
//			printf("->");
//		curr=curr->next;
//		
//	}
//	
//}
//
//int main(){
//	
//	node* head_ptr =NULL;
//	
//	append_node(&head_ptr,0);
//	append_node(&head_ptr,1);
//	append_node(&head_ptr,2);
//	append_node(&head_ptr,4);
//	printList(&head_ptr);
//	printf("\n");
//	reverse_list(&head_ptr);
//	printList(&head_ptr);
//	
//}



