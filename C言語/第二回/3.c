#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief 入力されたトークンの優先順位を出力する関数
 * 
 * @param token：字句要素
 * @return int：優先順位
 */
int priority(char token){
  switch(token){
    case '=':
      return 0;
    case ')':
      return 1;
    case '+':
    case '-':
      return 2;
    case '*':
    case '/':
      return 3;
    case '(':
      return 4;
    default:
      return 5;
  }
}

/**
 * @brief 逆ポーランド記法のためのスタックを作成する
 *        ここでのスタックは、topからトークンをpopすることで逆ポーランド記法になる
 * 
 * @param str 解析対象文字列
 * @param stack 解析して作成されたスタック
 * @return int スタックのtopを指すインデックス
 */
int reverse_polish_notation(char *str, char *stack){
  int i = 0;
  int top = -1;
  for(i=0; str[i] != '\0'; i++){
    while((top >= 0) && 
          (stack[top] != '(') &&
          (priority(str[i]) <= priority(stack[top]))) {
      printf("%c", stack[top]);
      top--;
    }
    if(str[i] != ')'){
      top++;
      stack[top] = str[i];
    }else{
      top--;
    }
  }
  return top;
}

int main(void){
  // 文字列を入力し、strに保持
  char str[15];
  scanf("%s", str);

  // スタックの初期化
  char stack[15];

  int top = reverse_polish_notation(str, stack);
  
  while(top >= 0){
    printf("%c", stack[top]);
    top--;
  }
  printf("\n");
  return 0;
}