#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "songnode.h"

struct song_node {
  char song_name[100];
  char song_artist[100];
  struct song_node * next;
};

struct song_library{
  struct song_node ** lib;
};

struct song_library * make_lib() {

  struct song_library * ret = malloc(sizeof(struct song_node[27][1]));
  return ret;

}

void insert_song(struct song_library * thing, struct song_node * thing2) {

  char * alphabet = "abcdefghijklmnopqrstuvwxyz/";
  char * songart = thing2->song_artist;
  char letter = songart[0];
  int count;
  char firstletter;
  int found = 0;
  for (count = 0; count < 26 && !found; count++) {
    firstletter = alphabet[count];
    if (firstletter == letter) {
      found = 1;
    }
  }
  if (found) {
    (thing->lib)[count] = insert_order((thing->lib)[count], thing2);
  }
  else {
    (thing->lib)[26] = insert_order((thing->lib)[26], thing2);
  }

}

struct song_node * search_song(struct song_library * library, char * song, char * artist){

  char * alphabet = "abcdefghijklmnopqrstuvwxyz/";
  int count;
  for (count = 0; count < 26; count++){
    if (artist[0] == alphabet[count]){
      return find_song((library->lib)[count],song,artist);
    }
  }
  return find_song((library->lib)[26],song,artist);

}

struct song_node * search_artist(struct song_library * library, char * artist){

  char * alphabet = "abcdefghijklmnopqrstuvwxyz/";
  int count;
  for (count = 0; count < 26; count++){
    if (artist[0] == alphabet[count]){
      return find_firstsong((library->lib)[count],artist);
    }
  }
  return find_firstsong((library->lib)[26],artist);

}

// int main() {
//   return 0;
// }
