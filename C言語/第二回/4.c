#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int data_type;
typedef int frequency_type;
typedef struct node_tag{
  data_type data;
  frequency_type frequency;
  struct node_tag *left;
  struct node_tag *right;
} node_type;
node_type *root;

/**
 * @brief 入力された値を持つ2分探索木のノードを生成
 * 
 * @param number ノードの持つ値データ
 * @return node_type* 生成されたノードへのポインタ
 */
node_type *malloc_node(int number){
  node_type *add;

  add = (node_type*)malloc(sizeof(node_type));
  if(add == NULL){
    return NULL;
  }

  add->left = NULL;
  add->right = NULL;
  add->data = number;
  add->frequency = 1;
  
  return add;
}

/**
 * @brief 2分探索木に入力された値を持つノードを追加する関数
 * 
 * @param root 2分探索木の根へのポインタ
 * @param number 追加されるノードに持たせる値
 * @return node_type* 2分探索木の根へのポインタ
 */
node_type *add_node(node_type *root, int number){
  node_type *node;

  if(root == NULL){
    root = malloc_node(number);
    return root;
  }

  node = root;
  while(1){
    if(number < node->data){
      if(node->left == NULL){
        node->left = malloc_node(number);
        break;
      }else{
        node = node->left;
      }
    }else if (number > node->data){
      if(node->right == NULL){
        node->right = malloc_node(number);
        break;
      }else{
        node = node->right;
      }
    }else {
      node->frequency++;
      break;
    }
  }
  return root;
}

/**
 * @brief 中間順で木のデータをプリントする関数
 * 
 * @param root 2分探索木の根へのポインタ
 */
void print_tree(node_type *root){
  node_type *node;
  node = root;
  if(node != NULL){
    print_tree(node->left);
    for(int i = 1; i <= node->frequency; i++){
      printf("(%d)", node->data);
    }
    print_tree(node->right);
  }
}

https://qiita.com/maebaru/items/a47c2ef675a76e8816ab
node_type delete_node(node_type *root, data_type key){
  if(root == NULL) return NULL;

  if(key < root->data){
    root->left = self.delete_node(root->left, key)
  }else if(key > root->data){
    root->right = self.delete_node(root->right, key)
  }else {
    if(root->left == NULL && root->right == NULL){
      root = NULL
    }else if(root->left == NULL || root->right == NULL){
      root = root->left || root->right
    }
  }
}

/**
 * @brief 削除対象のノードと中間順配列で次にくるノードを入れ替えす関数
 * 
 * @param target_node 削除対象のノード
 */
void swap_node(node_type *target_node){
  data_type delete_value;
  node_type *swapping_node;
  swapping_node = target_node->right;
  while(swapping_node != NULL){
    swapping_node = swapping_node->left;
  }
  delete_value = target_node->data;
  target_node->data = swapping_node->data;
  target_node->frequency = swapping_node->frequency;
  swapping_node->data = delete_value;
}

int main(void){
  char buf[128];
  int temp;

  // 逐次入力された値を持つ2分探索木のノードを追加
  while (fgets(buf,sizeof(buf),stdin) != NULL) {
    sscanf(buf, "%d", &temp);
    root = add_node(root, temp);
  }

  print_tree(root);
  printf("\n");

  return 0;
}