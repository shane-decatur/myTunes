struct song_node;

struct song_node * make(char * song, char * artist);

struct song_node * insert_front(struct song_node * front, struct song_node * node);

struct song_node * greater_song_node(struct song_node * node1, struct song_node * node2);

struct song_node * insert_order(struct song_node * front, struct song_node * node);

void print_struct(struct song_node * s);

void print_list(struct song_node *s);

struct song_node * find_song(struct song_node * front, char * song, char * artist);

struct song_node * find_firstsong(struct song_node * front, char * artist);

struct song_node * find_randomsong(struct song_node * front);

struct song_node * remove_node(struct song_node * front, char * songartist, char * songname);

struct song_node * free_list(struct song_node * exm);
