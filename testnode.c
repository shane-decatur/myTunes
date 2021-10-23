#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songnode.h"

int main(){
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
}
