#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ノードの構造体
typedef struct node
{
  char firstname[50];
  char lastname[50];
  struct node *next;
} node_type;

// ノードの初期化
void initialize(node_type **pp)
{
  *pp = NULL;
}

// 新しいノード構造体のためのメモリをヒープ領域に割り当てるための関数
node_type *new_node(char *firstname, char *lastname, node_type *next)
{
  node_type *temp = (node_type *)malloc(sizeof(node_type));
  if (temp == NULL)
    return NULL;
  strcpy(temp->firstname, firstname);
  strcpy(temp->lastname, lastname);
  temp->next = next;
  return temp;
}

// 要素がlastname の辞書順となるようにデータを挿入する関数
void insert_sorted_by_lastname(node_type **head, node_type *new_node)
{
  node_type **current = head;
  while (*current && strcmp((*current)->lastname, new_node->lastname) < 0)
    current = &((*current)->next);
  new_node->next = *current;
  *current = new_node;
}

// 要素がfirstname の辞書順となるようにデータを挿入する関数
void insert_sorted_by_firstname(node_type **head, node_type *new_node)
{
  node_type **current = head;
  while (*current && strcmp((*current)->firstname, new_node->firstname) < 0)
    current = &((*current)->next);
  new_node->next = *current;
  *current = new_node;
}

// 線形リストのノードの内容を表示する関数
void print_nodes(node_type *head)
{
  node_type *current = head;
  while (current != NULL)
  {
    printf("Firstname: %s, Lastname: %s\n", current->firstname, current->lastname);
    current = current->next;
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  node_type *head_lastname_sorted = NULL, *head_firstname_sorted = NULL;
  char buf[100], firstname[50], lastname[50];

  initialize(&head_lastname_sorted);
  initialize(&head_firstname_sorted);

  FILE *file = fopen("namelist.txt", "r");
  while (fgets(buf, sizeof(buf), file) != NULL)
  {
    if (sscanf(buf, "%49s %49s", firstname, lastname) == 2)
    {
      node_type *new_node_lastname = new_node(firstname, lastname, NULL);
      node_type *new_node_firstname = new_node(firstname, lastname, NULL);

      insert_sorted_by_lastname(&head_lastname_sorted, new_node_lastname);
      insert_sorted_by_firstname(&head_firstname_sorted, new_node_firstname);
    }
  }

  printf("======List sorted by lastname=====\n");
  print_nodes(head_lastname_sorted);

  printf("=====List sorted by firstname======\n");
  print_nodes(head_firstname_sorted);

  return 0;
}
