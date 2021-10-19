struct song_node {

        char song_name[100];
        char song_artist[100];
        struct song_node * next;

};

struct song_node * insert_order(char * name, char * artist);


