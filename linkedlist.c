/* saulpanders
// linkedlist.c */

#include <stdio.h>
#include <stdlib.h>

 typedef struct node{
    int value;
    struct node * next;
} node_t;

void append (node_t * head, int element){
    node_t * current = head;
    while (current->next !=NULL){
        current= current->next; 
    }
    current->next=malloc(sizeof(node_t));
    current->next->value=element;
    current->next->next=NULL;
    
}

void listPrint (node_t * head){
    node_t * current=head->next;
    while (current!=NULL){
        printf("%d\n", current->value);
        current=current->next;
    }
}
void cleanList (node_t * head){
    
    while (head->next!=NULL){
        node_t * temp= head->next;
        head->next= head->next->next;
        free(temp);
    }
    free(head);
}
int main (){
    int listsize;
    printf("Enter how many values to input: " );
    scanf("%d", &listsize); 
    int i;
    int tempval;
    node_t * theHead=malloc(sizeof(node_t));
    for (i=0; i<listsize; i++){
     printf("Enter Value %d: ", i+1);
     scanf("%d", &tempval);
     append(theHead, tempval);      
    }
    listPrint(theHead);
    cleanList(theHead);
    return 0;
}
