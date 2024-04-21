#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_unary_operator(char** formula_not_replaced){
  char* cp = NULL;
  cp = (char*)malloc(sizeof(char) * 4);
  if (cp == NULL) {
    printf("配列作成失敗\n");
  }
  strcpy_s(cp, 4, "ABC");
    
  *formula_not_replaced = cp;
}

int main(void){
  char* str=NULL;

  replace_unary_operator(&str);

  printf("str = %s\n", str);
  
  free(str);
}