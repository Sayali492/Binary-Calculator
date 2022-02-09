typedef struct node
{
          int data;
          int index;
          struct node *next;

} node;
typedef struct node *list;

typedef struct node_char
{
          char ch;
          int index;
          struct node_char *next;

} node_char;
typedef node_char *char_list;


typedef struct node1
{
          int index1;
          int sign;
          struct node1 *right;
          struct node *down;
          
} Node;
typedef Node *List;



void precedence(char_list L, list *array, int count_no);
Node *reverse_List(List L);
Node *init(char *str, int cnt, int total_cnt);
node *addition(list La, list Lb);
node *subtraction(list La, list Lb);
node *multiplication(list La, list Lb);
node *division(list La, list Lb);
node *modulo(list La, list Lb);
node *power(list La, list Lb);
node *evaluation(char *str, int cnt, int total_cnt, List L);
int find_error(char *str, int total_cnt);