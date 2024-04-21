#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATASET_NUMBER 128

// 配列を絶対値に関して昇順に並べ替える関数
void sort(double array[], int array_size)
{
  int i, j;
  double temp;

  for (i = 0; i < (array_size - 1); i++)
  {
    for (j = (array_size - 1); j < i; j--)
    {
      if (fabs(array[i - 1]) > fabs(array[i]))
      {
        temp = array[j - 1];
        array[j - 1] = array[j];
        array[j] = temp;
      }
    }
  }
}

// 配列の和を求めて返す関数
double sum_array_numbers(double array[], int array_size)
{
  int i;
  double result;

  for (i = 0; i < array_size; i++)
  {
    result += array[i];
  }

  return result;
}

int main(void)
{
  int array_size = 0;
  char buf[DATASET_NUMBER];
  int i = 0;
  int j;
  double temp;
  double result;

  // 入力される実数を格納する配列を用意
  double array[DATASET_NUMBER];

  // データセットファイルを開く
  FILE *fin = fopen("dataset.txt", "r");
  if (fin == NULL)
  {
    perror("fopen");
    return 1;
  }

  // データを取得し、配列に格納
  while (fgets(buf, sizeof(buf), fin) != NULL)
  {
    sscanf(buf, "%lf", &temp);
    array[i] = temp;
    i++;
    array_size++;
  }

  sort(array, array_size);
  result = sum_array_numbers(array, array_size);
  printf("%lf\n", result);

  return 0;
}