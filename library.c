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

struct song_node ** make_lib() {

  struct song_node ** library = malloc(27 * sizeof(struct song_node));
  int i = 0;
  for (i; i < 27; i++) {
    library[i] = 0;
  }
  return library;

}

struct song_node ** insert_song(struct song_node ** main_lib, struct song_node * node) {

  char targetletter = (node->song_artist)[0];
  if (targetletter >= 97) {
    main_lib[targetletter-97] = insert_order(main_lib[targetletter-97], node);
  }
  else {
    main_lib[targetletter-65] = insert_order(main_lib[targetletter-65], node);
  }

}

// struct song_library * insert_song(struct song_library * main_lib, struct song_node * node) {
//
//   char * alphabet = "abcdefghijklmnopqrstuvwxyz/";
//   char targetletter = (node->song_artist)[0];
//   int count = 0;
//   char letter;
//   int found = 0;
//   for (count; count < 26 && !found; count++) {
//     letter = alphabet[count];
//     if (letter == targetletter) {
//       found = 1;
//       insert_order((main_lib->lib)[count], node);
//     }
//   }
//   if (!found) {
//     insert_order((main_lib->lib)[26], node);
//   }
//   return main_lib;
//
// }

struct song_node * search_song(struct song_node ** main_lib, char * song, char * artist) {

  char targetletter = artist[0];
  if (targetletter < 97) {
    targetletter += 32;
  }
  return find_song(main_lib[targetletter - 97], song, artist);

}

// struct song_node * search_song(struct song_library * library, char * song, char * artist){
//
//   char * alphabet = "abcdefghijklmnopqrstuvwxyz/";
//   int count;
//   for (count = 0; count < 26; count++){
//     if (artist[0] == alphabet[count]){
//       return find_song((library->lib)[count],song,artist);
//     }
//   }
//   return find_song((library->lib)[26],song,artist);
//
// }

struct song_node * search_artist(struct song_node ** main_lib, char * artist) {

  char targetletter = artist[0];
  if (targetletter < 97) {
    targetletter += 32;
  }
  return find_firstsong(main_lib[targetletter-97], artist);

}

// struct song_node * search_artist(struct song_library * library, char * artist){
//
//   char * alphabet = "abcdefghijklmnopqrstuvwxyz/";
//   int count;
//   for (count = 0; count < 26; count++){
//     if (artist[0] == alphabet[count]){
//       return find_firstsong((library->lib)[count],artist);
//     }
//   }
//   return find_firstsong((library->lib)[26],artist);
//
// }

void print_letter(struct song_node ** main_lib, char letter) {

  if (letter < 97) {
    letter += 32;
  }
  printf("letter %c: ", letter);
  print_list(main_lib[letter-97]);

}

// void print_letter(struct song_library * library, char let) {
//
//   char * alphabet = "abcdefghijklmnopqrstuvwxyz/";
//   int count = 0;
//   int found = 0;
//   struct song_node * correctlist;
//   for (count; count < 26 && !found; count++) {
//     if (alphabet[count] == let) {
//       correctlist = (library->lib)[count];
//       found = 1;
//     }
//   }
//   if (!found) {
//     correctlist = (library->lib)[26];
//   }
//   printf("letter: %c ", let);
//   print_list(correctlist);
//
// }

void print_artist(struct song_node ** main_lib, char * artist) {

  char targetletter = artist[0];
  if (targetletter < 97) {
    targetletter += 32;
  }
  struct song_node * correctlist = find_firstsong(main_lib[targetletter-97], artist);
  printf("%s songs: ", artist);
  while (correctlist) {
    print_struct(correctlist);
    correctlist = correctlist->next;
    correctlist = find_firstsong(main_lib[targetletter-97], artist);
  }
}

// void print_artist_from_songnode(struct song_node * front, char * songartist) {
//
//   if (!strcmp(front->song_artist, songartist)) {
//     print_struct(front);
//   }
//   while (front->next) {
//     front = front->next;
//     if (!strcmp(front->song_artist, songartist)) {
//       print_struct(front);
//     }
//   }
//   printf("\n");
//
// }
//
// void print_artist(struct song_library * library, char * songartist) {
//
//   char * alphabet = "abcdefghijklmnopqrstuvwxyz/";
//   int count = 0;
//   char targetletter = songartist[0];
//   int found = 0;
//   char letter;
//   struct song_node * correctlist;
//   for (count; count < 26 && !found; count++) {
//     if (alphabet[count] == targetletter) {
//       correctlist = ((library->lib)[count]);
//       found = 1;
//     }
//   }
//   if (!found) {
//     correctlist = ((library->lib)[26]);
//   }
//   printf("artist: %s ", songartist);
//   print_artist_from_songnode(correctlist, songartist);
//
// }

void print_library(struct song_node ** main_lib) {

  int count = 0;
  for (count; count < 27; count++) {
    if (main_lib[count]) {
      printf("letter %c: ", count + 97);
      print_list(main_lib[count]);
    }
  }

}

// void print_library(struct song_library * library) {
//
//   char * alphabet = "abcdefghijklmnopqrstuvwxyz/";
//   int count = 0;
//   for (count; count < 27; count++) {
//     printf("letter: %c ", alphabet[count]);
//     print_list((library->lib)[count]);
//   }
//
// }

void shuffle_songs(struct song_node ** main_lib) {

  srand(time(NULL));
  int count = 0;
  struct song_node * ret;
  for (count; count < 5; count++) {
    int rando = rand() % 27;
    ret = find_randomsong(main_lib[rando]);
    print_struct(ret);
  }

}

// void shuffle_songs(struct song_library * library) {
//
//   int count = 0;
//   for (count; count < 5; count++) {
//     int rand_num = rand() % 27;
//     printf("%d ", rand_num);
//     print_struct(find_randomsong((library->lib)[rand_num]));
//   }
//
// }

void remove_song(struct song_node ** main_lib, struct song_node * node) {

  char targetletter = (node->song_artist)[0];
  if (targetletter < 97) {
    targetletter += 32;
  }
  main_lib[targetletter-97] = remove_node(main_lib[targetletter-97], node->song_artist, node->song_name);

}

// struct song_library * remove_song(struct song_library * library, struct song_node * node) {
//
//   char * alphabet = "abcdefghijklmnopqrstuvwxyz/";
//   char targetletter = (node->song_artist)[0];
//   struct song_node * rightnode;
//   int count = 0;
//   char letter;
//   int found = 0;
//   for (count; count < 26 && !found; count++) {
//     letter = alphabet[count];
//     if (letter == targetletter) {
//       rightnode = (library->lib)[count];
//       found = 1;
//     }
//   }
//   if (!found) {
//     rightnode = (library->lib)[26];
//   }
//   remove_node(rightnode, node->song_artist, node->song_name);
//   return library;
//
// }

void clearall(struct song_node ** main_lib) {

  int count = 0;
  for (count; count < 27; count++) {
    free_list(main_lib[count]);
    main_lib[count] = NULL;
  }

}

// struct song_library * clearall(struct song_library * library) {
//
//   int count = 0;
//   for (count; count < 27; count++) {
//     free_list((library->lib)[count]);
//   }
//   return library;
//   // return (library->lib)[count];
//
// }

// int main() {
//   return 0;
// }
