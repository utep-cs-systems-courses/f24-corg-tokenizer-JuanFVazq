#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main(){ 
  char input[100];
  int num;
  char** tokens;
  List* history = init_history();
  printf("Welcome to the tokenizer: Please enter a String or enter '!' to view your previous String or 'e' to terminate \n");
  
  
  while(*input != 'e'){
    printf("$ ");
    fgets(input, sizeof(input), stdin);
    printf("\n");
    printf("Are you looping here?");
    if(*input == '!'){ 
	printf("History: \n");
	print_history(history);
     
	printf("Would you like to retrieve a specific string? Enter # \n $ ");
	scanf("%d", &num);
	char *temp = get_history(history,num);
	if(temp != NULL){
	  printf("Here you go! \n");
	  tokens = tokenize(temp);
	  print_tokens(tokens);
	  fgets(input, sizeof(input),stdin);
	} else {
	  printf("Not Valid \n ");
	}
    } else if(*input != 'e'){
        printf("Why are we going in here");
	printf("Here is the String Tokenized! \n");

	tokens = tokenize(input);

	print_tokens(tokens);
	add_history(history,input);
    }
  }
  free_tokens(tokens);
  free_history(history);
}
	   
