struct song_library;

struct song_library * make_lib();

void insert_song(struct song_library * thing, struct song_node * thing2);

struct song_node * search_song(struct song_library * library, char * song, char * artist);

struct song_node * search_artist(struct song_library * library, char * artist);
