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
  struct song_node *x = make("hazard duty pay","jpegmafia");

  insert_song(library, a);
  insert_song(library, b);
  insert_song(library, c);
  insert_song(library, d);
  insert_song(library, e);
  insert_song(library, f);
  insert_song(library, g);
  insert_song(library, h);
  insert_song(library, x);

  struct song_node * i = make("money machine","100 gecs");
  struct song_node * j = make("stupid horse","100 gecs");
  struct song_node * k = make("gosha", "$not");
  struct song_node * l = make("guilty conscience","070 shake");

  insert_song(library, i);
  insert_song(library, j);
  insert_song(library, k);
  insert_song(library, l);




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
  printf("Finding songs under Letter: misc\n");
  print_letter(library,'{');
  printf("-------------------------------------------\n");
  printf("Finding songs with Title: money machine and Artist: 100 gecs\n");
  print_struct(search_song(library, "money machine","100 gecs"));
  printf("\n");
  printf("-------------------------------------------\n");
  printf("Finding songs under Artist: 100 gecs\n");
  print_artist(library, "100 gecs");
  printf("\n");
  printf("-------------------------------------------\n");
  printf("Finding songs under Artist: AC/DC\n");
  print_artist(library, "ac/dc");
  printf("\n");
  printf("-------------------------------------------\n");
  printf("Finding 5 random songs\n");
  shuffle_songs(library);
  printf("\n");
  printf("-------------------------------------------\n");
  printf("Deleting a song\n");
  remove_song(library, e);
  printf("\n");
  printf("All of the library: \n");
  print_library(library);
  printf("-------------------------------------------\n");

  struct song_node * list = make("The World Stands Still", "Biley Renner");
  printf("\n");
  print_list(list);
  struct song_node * toadd;
  toadd = make("The End Comes Soon", "Biley Renner");
  list = insert_order(list, toadd);
  printf("\n");
  print_list(list);
  toadd = make("The Trilogy Ruptures", "Biley Benner");
  list = insert_order(list, toadd);
  printf("\n");
  print_list(list);
  toadd = make("The Trilogy Ruptures", "Biley Renner");
  list = insert_order(list, toadd);
  printf("\n");
  print_list(list);
  list = remove_node(list, "Biley Benner", "The Trilogy Ruptures");
  printf("\n");
  print_list(list);
  toadd = make("Hallelujah", "Daddoms Science");
  list = insert_front(list, toadd);
  printf("\n");
  print_list(list);

  // struct song_node * rando = find_randomsong(list);
  struct song_node * rando = find_song(list, "The End Comes Soon", "Biley Renner");
  printf("\n");
  print_struct(rando);
  printf("\n");
  rando = find_randomsong(list);
  printf("\n");
  print_struct(rando);
  printf("\n");

  printf("\n");

  // print_struct(search_song(library,"big ol fart","daddy"));

  print_library(library);

  return 0;
}
