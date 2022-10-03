// list/list.c
//
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t* list_alloc() { 
  list_t* list = (list_t*)malloc(sizeof(list_t)); 
  list->head = NULL; 
  return list;
}

void list_print(list_t *l){
  node_t* curr = l->head;
  if (curr==NULL){
    printf("Empty!\n");
  }else{
    while(curr != NULL){
      printf("%d\n", curr->value);
      curr=curr->next;
  }
  }
}

void list_free(list_t *l){
  node_t *curr, *next;
  if (l->head != NULL){
    curr = l->head;
    while(curr != NULL){
      next = curr->next;
      node_free(curr);
      curr = next;
  }
  l->head = NULL;
  }

}

node_t *node_alloc(elem value){
  node_t *node = (node_t*)malloc(sizeof(node_t));
  node->value = value;
  node->next= NULL;
  return node;
}

void node_free(node_t *n){
  free(n);
}


int list_length(list_t *l){
  node_t *curr = l->head;
  int count = 0;
  while(curr != NULL){
    count ++;
    curr=curr->next;
  }
  return count;
}

void list_add_to_back(list_t *l, elem value){
  node_t* nNode = node_alloc(value);
  node_t* curr = l->head;
  if(l->head == NULL){
    l->head = nNode;
  }
  else{
    while(curr->next!=NULL){
      curr = curr->next;
    }
    curr->next = nNode;
  }
}

void list_add_to_front(list_t *l, elem value){
  node_t* nNode = node_alloc(value);
  if (l->head == NULL){
    l->head = nNode;
  }else{
    nNode->next = l->head;
    l->head = nNode;
  }
}

void list_add_at_index(list_t *l, elem value, int index){
  node_t* nNode = node_alloc(value);
  if(l->head == NULL){
    l->head = nNode;
  }else if(index == 0){
    nNode->next = l->head;
    l->head = nNode;
  }else{
    node_t* curr = l->head;
    while(--index){
      curr = curr->next;
    }
    nNode->next = curr->next;
    curr->next = nNode;
  }

}

elem list_remove_from_back(list_t *l){
  node_t* curr = l->head;
  if(curr == NULL){
    return -1; 
  }else{
    while(curr->next->next!=NULL){
      curr = curr->next;
    }
    node_free(curr->next);
    curr->next = NULL;

  }
  
}

elem list_remove_from_front(list_t *l){
  node_t* curr = l->head;
  if (l->head == NULL){
    return -1; 
  }else{
    node_free(curr);
    l->head = l->head->next;
  }
}

elem list_remove_at_index(list_t *l, int index){
  int i=0;
  node_t* curr = l->head;
  node_t* prev = curr;
  if(l->head == NULL){
    return -1;
  }else if(index == 0){
   list_remove_from_front(l);
  }else{
    while(curr != NULL){
      if (i==index){
        node_free(curr);
        prev->next = curr->next;
      }else{
        prev = curr;
        curr = curr->next;
      }
      i++;
    }
  }
}

//  giving back 1 0r 0 instead of a bool
bool list_is_in(list_t *l, elem value){
  node_t* curr = l->head;
  if (curr==NULL){
    printf("Empty!\n");
  }else{
    while(curr != NULL){
      if(curr->value == value){
        return true;
      }else{
        curr = curr->next;
      }
    }
    return false;
  }
}


elem list_get_elem_at(list_t *l, int index){
  if(l->head == NULL || index>list_length(l)){
    return -1;
  }else if(index == 0){
    return l->head->value;
  }else{
    node_t* curr = l->head;
    int i = 0;
    while(i < index){
    curr = curr->next;
    i++;
    }
    return curr->value;
  }
}



int list_get_index_of(list_t *l, elem value){
  if(l->head == NULL){
    return -1;
  }else{
    int index = 0;
    node_t* curr = l->head;
    while(curr != NULL){
      if (curr->value == value){
        return index;
      }
      else{
        curr = curr->next;
      }
      index++;
    }
    return -1;
  }
}
