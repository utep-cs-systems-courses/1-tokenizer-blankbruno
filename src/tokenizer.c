#include "tokenizer.h"
#include <stdlib.h>
#include <string.h>

int space_char(char c){
  if(c == '\t' || c == ' ' ){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if (space_char(c)){
    return 0;
  }
  return 1;
}

char *word_start(char *str){
  if(strlen(str) == 0){
    return 0;
  }
  
  while(str){
    if (non_space_char(*str) == 1){
      return str;
    }
    str++;
  }
    return 0;
}

char *word_terminator(char *word){
  while (word){
    if(space_char(*word) == 1){
      return word;
    }
    word++;
  }
  return 0;
}


char *copy_str(char *inStr, short len){
  int inIndex = 0;
  char *inCopy = malloc((len + 1) * sizeof(char)), c;
  do{
    c = *(inCopy + inIndex) = *(inStr + inIndex);
    inIndex++;
  } while (c);
  
  return inCopy;
}

int count_words(char *s){
  int word_count = 0;

  do{
    if((s = word_start(s))) word_count++;
  }while ((s = word_terminator(s)));
  
  return word_count;
}

char **tokenize(char* str){
  int vector_index = 0;
  char **token_vector = malloc(count_words(str) * sizeof(char*));
  do{
    char* start = word_start(str);
    char* end = word_terminator(start);
    char* copy = copy_str(str, end - start);
    token_vector[vector_index] = copy;
    vector_index++;
    str = end;
   } while(str);

  return token_vector;
}

void print_tokens(char ** tokens, int length){
  int i;
  for(i = 0; i < length; i++){
    printf("%s\n", tokens+i);
  }
}

void free_tokens(char **tokens){
  
}
