void init_list(list *L);
void append(list *L, int d);
void insert_begin(list *L, int d, int place);
node *delete_a_node(list *L, int d, int pos);
node_char *delete_a_charnode(char_list *L, char d, int pos);
node *reverse_list(list *L);
int compare_lists(list La, list Lb);
node *remove_trailing_zeroes(list *L);
int display_num_int(list L);
void display_num(list L);
void display_New_List(List L);