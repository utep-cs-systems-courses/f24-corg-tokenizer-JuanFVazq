#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c)
{
  if((c == ' ') || (c == '\t'))
    {
      return 1;
    }
  else
    {
      return 0;
    }
  
}

/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */

int non_space_char(char c)
{
  if((c == ' ') || (c == '\t') || (c == '\0'))
    {
      return 0;
    }
  else
    {
      return 1;
    }
}
  

/* Returns a pointer to the first character of the next 

   space-separated token in zero-terminated str.  Return a zero pointer if 

   str does not contain any tokens. */

char *token_start(char *str)
{
  if(*str == '\0')
    {
      return 0;
    }
  while(space_char(*str))
    {
    str++;
  }
  return str;
}
/* Returns a pointer terminator char following *token */
char *token_terminator(char *token)
{
  while(non_space_char(*token)){
    token++;
  }
  return token;
}
/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
  int count = 0;
  while(*str != '\0'){
    count++;
    //printf("But here first");
    str = token_start(str);
    //printf("We get here");
    str = token_terminator(str);
    //printf("Just along for the ride");
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len)
{
  char *new = (char *)malloc(len+1);
  if(!new)
    {
      exit(0);
    }
  for(short i = 0; i < len; i++){
    new[i] = inStr[i];
  }
  new[len] = '\0';
  return new;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.
   
   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

*/

char **tokenize(char* str)
{
  //  printf("We get here");
  int count = count_tokens(str);
  //  printf("%d",count);
  //int count = 1;
  char **token = (char **)malloc((count+1)* sizeof(char *));
  
  if(!token){
    // exit(0);
  }

  char *start = token_start(str);

  for(int i = 0;start;i++){
    char *end = token_terminator(start);
    int length = end - start;
    token[i] = copy_str(start, length);
    start = token_start(end);
  }
  token[count] = NULL;
  
  return token;
}

 
    
    



/* Prints all tokens. */

void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i]){
    printf("%s\n", tokens[i]);
    i++;
  }
}
 


/* Frees all tokens and the vector containing themx. */

void free_tokens(char **tokens)
{
  for(int i = 0;tokens[i];i++){
    free(tokens[i]);
  }
  free(tokens);
}

  


