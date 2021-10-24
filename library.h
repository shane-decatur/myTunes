struct song_node;

struct song_library;

struct song_library * make_lib();

struct song_library * insert_song(struct song_library * main_lib, struct song_node * node);

struct song_node * search_song(struct song_library * library, char * song, char * artist);

struct song_node * search_artist(struct song_library * library, char * artist);

void print_letter(struct song_library * library, char let);
