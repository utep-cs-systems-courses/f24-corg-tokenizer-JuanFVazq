#ifndef _HISTORY_
#define _HISTORY_
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;



List* init_history(){
  List *list = (List*)malloc(sizeof(List));
  if(list != NULL){
    list ->root = NULL;
  }
  return list;
}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){
  Item *node = (Item*)malloc(sizeof(Item));
  int len = 0;
  while (str[len] != '\0'){
   len++;
  }
  node->str = copy_str(str,len);
  node->next = NULL;
  if (list->root == NULL)
    {
      list->root = node;
      node->id = 1;
    }
  else
    {
      Item *temp = list->root;
      int index = temp->id;
      while(temp->next != NULL)
	{
	  temp = temp->next;
	  index = temp->id;
	}
      temp->next = node;
      node->id = index + 1;
    }
}
   /* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){
  Item *i = list->root;

  while(i != NULL){
    if(i->id == id){
      return i->str;
    }
    i = i->next;
  }
  return NULL;
}

void print_history(List *list){
  Item *i = list->root;

  while(i != NULL){
    printf("%d: %s\n", i->id,i->str);
    i = i->next;
  }
}



void free_history(List *list){
  Item *i = list->root;
  Item *j;
  while(i != NULL){
    j = i;
    i = i->next;
    free(j->str);
    free(j);
  }


}


#endif
