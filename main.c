#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songnode.h"
#include "library.h"

int main(){
  struct song_node ** library = make_lib();

  struct song_node *a = make("alive","pearl jam");
  struct song_node *b = make("paranoid android", "radiohead");
  struct song_node *c = make("thunderstruck","ac/dc");
  struct song_node *d = make("even flow","pearl jam");
  struct song_node *e = make("yellow ledbetter","pearl jam");
  struct song_node *f = make("time", "pink floyd");
  struct song_node *g = make("street spirit (fade out)","radiohead");
  struct song_node *h = make("tempral", "rhino rexes");

  insert_song(library, a);
  insert_song(library, b);
  insert_song(library, c);
  insert_song(library, d);
  insert_song(library, e);
  insert_song(library, f);
  insert_song(library, g);
  insert_song(library, h);

  printf("\n");
  printf("-------------------------------------------\n");
  printf("All of the library: \n");
  print_library(library);
  printf("-------------------------------------------\n");
  printf("Finding song with Title: Alive and Artist: Pearl Jam\n");
  print_struct(search_song(library, "alive","pearl jam"));
  printf("\n");
  printf("-------------------------------------------\n");
  printf("Finding all songs by the Artist: Radio Head\n");
  print_artist(library, "radiohead");
  printf("\n");
  printf("-------------------------------------------\n");
  printf("Finding song with Artist: Pink Floyd\n");
  print_struct(search_artist(library,"pink floyd"));
  printf("\n");
  printf("-------------------------------------------\n");
  printf("Finding songs under Letter: R\n");
  print_letter(library, 'r');
  printf("-------------------------------------------\n");
  printf("Finding songs under Artist: AC/DC\n");
  print_artist(library, "ac/dc");
  printf("\n");
  printf("-------------------------------------------\n");
  // printf("Finding 5 random songs\n");
  // shuffle_songs(library);
  // printf("\n");
  // printf("-------------------------------------------\n");
  printf("Deleting a song\n");
  remove_song(library, e);
  printf("\n");
  printf("All of the library: \n");
  print_library(library);
  printf("-------------------------------------------\n");

  return 0;
}
