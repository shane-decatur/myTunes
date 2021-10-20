#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node {
  char song_name[100];
  char song_artist[100];
  struct song_node * next;
};

void print_struct(struct song_node s){
  printf("%s by %s\n",s.song_name,s.song_artist);
}

void print_list(struct song_node *s){
  print_struct(*s);
  if (s->next != NULL){
    print_list(s->next);
  }
}

struct song_node * insert_front(struct song_node * front){

}
