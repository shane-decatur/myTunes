#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songnode.h"
#include "library.h"

int main(){
  struct song_library * library = make_lib();

  struct song_node *a = make("alive","pearl jam");
  struct song_node *b = make("paranoid android", "radiohead");
  struct song_node *c = make("thunderstruck","ac/dc");
  struct song_node *d = make("even flow","pearl jam");
  struct song_node *e = make("yellow ledbetter","pearl jam");
  struct song_node *f = make("time", "pink floyd");
  struct song_node *g = make("street spirit (fade out)","radiohead");
  //
  insert_song(library, b);
  insert_song(library, g);
  print_letter(library, 'r');
  // insert_song(library, b);
  // insert_song(library, c);
  // insert_song(library, d);
  // insert_song(library, e);
  // insert_song(library, f);
  // insert_song(library, g);

  return 0;
}
