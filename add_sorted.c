#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

void add_sorted(Node* head, int value){
    Node* next_node  = NULL;
    Node* insert_node = find_gt(*head,value);
    if( insert_node == NULL){
        head = add_front(head,value);
    }
    else{
        next_node = insert_node->next;
        if(next_node == NULL || next_node->num != value){
            insert(insert_node,value);
        }
    }
    return head;
}
