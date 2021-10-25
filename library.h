struct song_node;

struct song_node ** make_lib();

void insert_song(struct song_node ** main_lib, struct song_node * node);

struct song_node * search_song(struct song_node ** main_lib, char * song, char * artist);

struct song_node * search_artist(struct song_node ** main_lib, char * artist);

void print_letter(struct song_node ** main_lib, char letter);

void print_artist(struct song_node ** main_lib, char * artist);

void print_library(struct song_node ** main_lib);

void shuffle_songs(struct song_node ** main_lib);

void remove_song(struct song_node ** main_lib, struct song_node * node);

void clearall(struct song_node ** main_lib);
