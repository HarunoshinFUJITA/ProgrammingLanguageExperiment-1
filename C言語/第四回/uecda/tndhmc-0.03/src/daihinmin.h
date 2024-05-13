void search_low_card(int out_cards[8][15],int my_cards[8][15],int joker_flag);
void make_info_table(int info_table[8][15], int my_cards[8][15]);
int search_low_pair(int dst_cards[8][15], int info_table[8][15], int my_cards[8][15]);
int search_low_pair_restrict(int dst_cards[8][15], int info_table[8][15], int my_cards[8][15], int pairs_number);
int search_low_sequence(int dst_cards[8][15], int info_table[8][15]);
int search_low_sequence_restrict(int dst_cards[8][15], int info_table[8][15], int pairs_number);