#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "songnode.c"

struct song_library{
  struct song_node ** lib;
};

struct song_library * make_lib() {

  struct song_library * ret = malloc(sizeof(struct song_node[27][1]));

}

void insert_song(struct song_library * thing, struct song_node * thing2) {

  char * alphabet = "abcdefghijklmnopqrstuvwxyz/";
  char * songart = thing2->song_artist;
  char letter = songart[0];
  int count = 0;
  char firstletter;
  int found = 0;
  for (count; count < 26 && !found; count++) {
    firstletter = alphabet[count];
    if (firstletter == letter) {
      found = 1;
    }
  }
  if (found) {
    insert_order((thing->lib)[count], thing2);
  }
  else {
    insert_order((thing->lib)[26], thing2);
  }

}

// int main() {
//   return 0;
// }
