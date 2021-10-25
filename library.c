#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include <time.h>
#include "songnode.h"

struct song_node {
  char song_name[100];
  char song_artist[100];
  struct song_node * next;
};

struct song_node ** make_lib() {

  struct song_node ** library = malloc(27 * sizeof(struct song_node));
  int i = 0;
  for (i = 0; i < 27; i++) {
    library[i] = 0;
  }
  return library;

}

void insert_song(struct song_node ** main_lib, struct song_node * node) {

  char targetletter = (node->song_artist)[0];
  if (targetletter >= 97) {
    main_lib[targetletter-97] = insert_order(main_lib[targetletter-97], node);
  }
  else {
    main_lib[targetletter-65] = insert_order(main_lib[targetletter-65], node);
  }

}

struct song_node * search_song(struct song_node ** main_lib, char * song, char * artist) {

  char targetletter = artist[0];
  if (targetletter < 97) {
    targetletter += 32;
  }
  return find_song(main_lib[targetletter - 97], song, artist);

}

struct song_node * search_artist(struct song_node ** main_lib, char * artist) {

  char targetletter = artist[0];
  if (targetletter < 97) {
    targetletter += 32;
  }
  return find_firstsong(main_lib[targetletter-97], artist);

}

void print_letter(struct song_node ** main_lib, char letter) {

  if (letter < 97) {
    letter += 32;
  }
  printf("letter %c: ", letter);
  print_list(main_lib[letter-97]);

}

void print_artist(struct song_node ** main_lib, char * artist) {

  char targetletter = artist[0];
  if (targetletter < 97) {
    targetletter += 32;
  }
  struct song_node * correctlist = main_lib[targetletter-97];
  printf("%s songs: ", artist);
  if (!strcmp(correctlist->song_artist, artist)) {
    print_struct(correctlist);
  }
  while (correctlist->next) {
    correctlist = correctlist->next;
    if (!strcmp(correctlist->song_artist, artist)) {
      print_struct(correctlist);
    }
    // correctlist = find_firstsong(main_lib[targetletter-97], artist);
  }
}

void print_library(struct song_node ** main_lib) {

  int count = 0;
  for (count = 0; count < 27; count++) {
    if (main_lib[count]) {
      printf("letter %c: ", count + 97);
      print_list(main_lib[count]);
    }
  }
}

void shuffle_songs(struct song_node ** main_lib) {

  srand(time(NULL));
  int count = 0;
  struct song_node * ret;
  for (count = 0; count < 5; count++) {
    int rando = rand() % 27;
    if (main_lib[rando] == NULL) {
      count--;
    }
    else {
      ret = find_randomsong(main_lib[rando]);
      print_struct(ret);
    }
  }

}

void remove_song(struct song_node ** main_lib, struct song_node * node) {

  char targetletter = (node->song_artist)[0];
  if (targetletter < 97) {
    targetletter += 32;
  }
  main_lib[targetletter-97] = remove_node(main_lib[targetletter-97], node->song_artist, node->song_name);

}

void clearall(struct song_node ** main_lib) {

  int count = 0;
  for (count = 0; count < 27; count++) {
    free_list(main_lib[count]);
    main_lib[count] = NULL;
  }

}

// int main() {
//   return 0;
// }
