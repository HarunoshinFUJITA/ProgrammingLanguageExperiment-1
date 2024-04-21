#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SUCCESS 1
#define FAILURE 0
#define DATASET_NUMBER 128

// データの型を定義
typedef double data_type;

// ノードの構造体
typedef struct node_tag
{
  data_type data;
  struct node_tag *next;
} node_type;

// ノードの初期化
void initialize(node_type **pp)
{
  *pp = NULL;
}

// 新しいノード構造体のためのメモリをヒープ領域に割り当てるための関数
node_type *new_node(data_type x, node_type *p)
{
  node_type *temp;

  temp = (node_type *)malloc(sizeof(node_type));

  if (temp == NULL)
    return NULL;
  else
  {
    temp->data = x;
    temp->next = p;
    return temp;
  }
}

// 線形リストの末尾にノードを挿入する関数
int insert_rear(data_type x, node_type **pp)
{
  node_type *temp;

  temp = new_node(x, NULL);
  if (temp == NULL)
    return FAILURE;
  while (*pp != NULL)
  {
    pp = &((*pp)->next);
  }
  *pp = temp;
  return SUCCESS;
}

// 線形リストのノードの内容を表示する関数
void print_nodes(node_type *p)
{
  if (p != NULL)
  {
    printf("%g ", p->data);
    print_nodes(p->next);
  }
  else
    printf("\n");
}

// 線形リストのノードの内容の和を取り、返す関数
double sum_nodes(node_type *p)
{
  double result;
  while (p != NULL)
  {
    result = result + p->data;
    p = p->next;
  }
  return result;
}

int main(int argc, char *argv[])
{
  char buf[DATASET_NUMBER];
  double result;
  node_type *head;
  data_type temp;
  initialize(&head);

  FILE *fin = fopen("dataset.txt", "r");
  if (fin == NULL)
  {
    perror("fopen");
    return 1;
  }

  while (fgets(buf, sizeof(buf), fin) != NULL)
  {
    sscanf(buf, "%lf", &temp);
    insert_rear(temp, &head);
  }

  print_nodes(head);
  result = sum_nodes(head);
  printf("%g\n", result);

  return 0;
}