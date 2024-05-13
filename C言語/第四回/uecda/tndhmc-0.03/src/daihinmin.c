#include<stdio.h>
#include<string.h>
#include<strings.h>
#include"common.h"

// ペア情報テーブルの作成
void make_info_table(int info_table[8][15], int my_cards[8][15]){
  int i, j, k;

  clear_table(info_table);

  // ジョーカー無し階段情報の作成
  for(i=0; i<4; i++){
    for(j=13; j>0; j--){
      if(my_cards[i][j]==1){
        info_table[i][j]=info_table[i][j+1]+1;
      }
    }
  }
  
  // info_tableにあるすべての2を1にする
  // 階段出しは３枚からしか出せないため
  for(i=0; i<4; i++){
    for(j=0; j<15; j++){
      if(info_table[i][j]==2){
        info_table[i][j]=1;
      }
    }
  }

  // ジョーカーなしペア情報テーブルの作成
  for(i=1; i <= 13; i++){
    info_table[4][i] = my_cards[0][i] + my_cards[1][i]
                         + my_cards[2][i] + my_cards[3][i];
  }
}

int search_low_sequence(int dst_cards[8][15], int info_table[8][15]){
  /*
    info_tableから最弱の階段を検索し、提出カードを作成する関数
  */
  int i, j, k;
  int search_flag = 0;

  clear_table(dst_cards);

  // 最小の列(ナンバー1)から検索していく
  for(i=1; i<=13; i++){
    for(j=0; j<4; j++){
      if(info_table[j][i]>=3){
        search_flag = 1;
        break;
      }
    }
    if(search_flag==1) break;
  }

  if(i<=13){
    // info_tableが3だった位置から順に
    // dst_cardsのマスを1に修正する
    for(k=0; k<info_table[j][i]; k++){
      dst_cards[j][i+k]=1;
    }
    return 1;
  }else{
    return 0;
  }
}

int search_low_sequence_restrict(int dst_cards[8][15], int info_table[8][15], int pairs_number){
  /*
    info_tableから最弱の階段を検索し、提出カードを作成する関数
  */
  int i, j, k;
  int search_flag = 0;

  clear_table(dst_cards);

  // 最小の列(ナンバー1)から検索していく
  for(i=1; i<=13; i++){
    for(j=0; j<4; j++){
      // 指定枚数以上の場合に限定
      if(info_table[j][i] >= pairs_number){
        search_flag = 1;
        break;
      }
    }
    if(search_flag==1) break;
  }

  if(i<=13){
    // info_tableが指定枚数以上だった位置から順に
    // 指定枚数分dst_cardsのマスを1に修正する
    for(k=0; k < pairs_number; k++){
      dst_cards[j][i+k]=1;
    }
    return 1;
  }else{
    return 0;
  }
}

int search_low_pair(int dst_cards[8][15], int info_table[8][15], int my_cards[8][15]){
  /*
    最弱ペアを検索する関数
  */
  int i, j;

  clear_table(dst_cards);

  // ペア情報テーブルから、２枚以上存在する同ナンバーカードの
  // 列indexを取得する。
  for(i=1; i<=13; i++){
    if(info_table[4][i] >= 2)
      break;
  }

  // 列indexを用いて、提出カードの情報を、手持ちカード情報から
  // 提出カード情報にコピーする。
  if(i<=13){
    for(j=0; j<=3; j++){
      dst_cards[j][i] = my_cards[j][i];
    }
    return 1;
  }else{
    return 0;
  }
}

int search_low_pair_restrict(int dst_cards[8][15], int info_table[8][15], int my_cards[8][15], int pairs_number){
  /*
    指定された枚数の最弱ペアを検索し、提出カードを作成する関数
  */
  int i, j;

  clear_table(dst_cards);

  // ペア情報テーブルから、指定枚数以上存在する同ナンバーカードの
  // 列indexを取得する。
  for(i=1; i<=13; i++){
    if(info_table[4][i] >= pairs_number)
      break;
  }

  // 列indexを用いて、提出カードの情報を手持ちカード情報から
  // 提出カード情報に指定枚数分コピーする。
  if(i<=13){
    // コピー回数を記録する変数
    int copy_times = 0;
    for(j=0; j<=3; j++){
      if((my_cards[j][i] != 0) && (copy_times < pairs_number)){
        dst_cards[j][i] = my_cards[j][i];
        copy_times += 1;
      }else {
        dst_cards[j][i] = 0;
      }
    }
    return 1;
  }else{
    return 0;
  }
}

void search_low_card(int out_cards[8][15],int my_cards[8][15],int use_joker_flag){
  /*
    低い方から探して,最初に見つけたカードを一枚out_cardsにのせる。
    use_joker_flagが1のとき,カードが見つからなければ,jokerを一枚out_cardsにのせる。
  */
  int i,j,find_flag=0;

  clear_table(out_cards);                  //テーブルをクリア
  for(j=1;j<14&&find_flag==0;j++){        //低い方からさがし
    for(i=0;i<4&&find_flag==0;i++){
      if(my_cards[i][j]==1){              //カードを見つけたら               
        find_flag=1;                      //フラグを立て
        out_cards[i][j]=my_cards[i][j];   //out_cardsにのせ,ループを抜ける。
      }
    }
  }
  if(find_flag==0&&use_joker_flag==1){       //見つからなかったとき
    out_cards[0][14]=2;                  //ジョーカーをのせる
  }
}

/* waste OF search pairs */
void search_low_card_wosp(){
  /*
   ペアや階段を崩す
  */
}