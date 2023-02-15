#include malloc.h
#include tokenizer.h

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
  char *c = str;
  while(non_space_char(c) != 0){
    *c++;
  }
  return (c + 1) ? (space_char(c) != 1) : 0;
}

char *word_terminator(char *word){
  char *c = word;
  while (space_char(c) != 1){
    *c++;
  }
  return *c;
}


char *copy_str(char *inStr, short len){
  int inIndex = 0;
  char *inCopy = malloc((len + 1) * sizeof(char)), c;
  
}

char **tokenize(char* str){

}

void print_tokens(char ** tokens){
  
}

void free_tokens(char **tokens){
  
}
