struct song_node {

        char song_name[100];
        char song_artist[100];
        struct song_node * next;

};

struct song_node * insert_order(struct song_node * front,  struct song_node * node);

struct song_node * make(char * song, char * artist);

void print_struct(struct song_node s);

void print_list(struct song_node * start);

struct song_node * insert_front(struct song_node * exm, char * s, char * st);

struct song_node * free_list(struct song_node * exm);

struct song_node * remove_node(struct song_node *front, char * s);
