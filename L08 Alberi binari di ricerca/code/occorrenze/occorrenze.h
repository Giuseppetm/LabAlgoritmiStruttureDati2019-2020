struct node{
    Item item;
    struct node *l, *r;
};

typedef struct node *Node;

//bistree_code.pdf
Bit_node bist_search( Bit_node p, Key k );
int bist_searchparent ( Bit_node r, Key k, Bit_node *parent , Bit_node *p );
void bist_insert ( Bit_node *r, Item item );

// Funzioni generali
