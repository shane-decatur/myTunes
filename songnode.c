#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node {
  char song_name[100];
  char song_artist[100];
  struct song_node * next;
};

struct song_node * make(char * song, char * artist){
  struct song_node * s = malloc(sizeof(struct song_node));
  strcpy(s->song_name,song);
  strcpy(s->song_artist,artist);
  return s;
}

struct song_node * insert_front(struct song_node * front, struct song_node * node) {

	node->next = front;
	return node;

}

struct song_node * greater_song_node(struct song_node * node1, struct song_node * node2) {

	int artists = strcmp(node1->song_artist, node2->song_artist);
	int songnames = strcmp(node1->song_name, node2->song_name);
	if (artists < 0) {
		return node2;
	}
	else if (artists > 0) {
		return node1;
	}
	else {
		if (songnames < 0) {
			return node2;
		}
		else {
			return node1;
		}
	}

}

struct song_node * insert_order(struct song_node * front, struct song_node * node) {

  if (!front) {
    return node;
  }
	struct song_node * ret = front;
	struct song_node * tempnext;
	if (greater_song_node(front, node) == front) {
		node->next = front;
		ret = node;
		return ret;
	}
	else {
		while(front->next) {
			tempnext = front->next;
			if (greater_song_node(tempnext, node) == tempnext) {
				front->next = node;
				node->next = tempnext;
				return ret;
			}
			else {
				front = front->next;
			}

		}
		front->next = node;
		return ret;
	}

}

void print_struct(struct song_node * s){
  if (!s) {}
  else {
    printf("{%s, %s}\t",s->song_artist,s->song_name);
  }
}

void print_list(struct song_node *s){
  print_struct(s);
  if (s->next != NULL){
    print_list(s->next);
  }
  else{
    printf("\n");
  }
}

struct song_node * find_song(struct song_node * front, char * song, char * artist){
  if (!strcmp(front->song_name,song) && !strcmp(front->song_artist,artist)){
    return front;
  }
  while (front->next){
    front = front->next;
    if (!strcmp(front->song_name,song) && !strcmp(front->song_artist,artist)){
      return front;
    }
  }
  return NULL;
}

struct song_node * find_firstsong(struct song_node * front, char * artist){
  if (!strcmp(front->song_artist,artist)){
    return front;
  }
  while (front->next){
    front = front->next;
    if (!strcmp(front->song_artist,artist)){
      return front;
    }
  }
  return NULL;
}

int size(struct song_node * front) {

  int ret = 1;
  while (front->next) {
    ret++;
    front = front->next;
  }
  return ret;

}

struct song_node * find_randomsong(struct song_node * front) {

  int max_size = size(front);
  int rand_num = rand() % max_size;
  while (rand_num) {
    front = front->next;
    rand_num--;
  }
  return front;

}

struct song_node * remove_node(struct song_node * front, char * songartist, char * songname) {

	struct song_node * ret = front;
	struct song_node * tempnext;
	if (!strcmp(front->song_name, songname) && !strcmp(front->song_artist, songartist)) {
		ret = front->next;
		return ret;
	}
	else {
		while (front->next) {
			tempnext = front->next;
			if (!strcmp(tempnext->song_name, songname) && !strcmp(tempnext->song_artist, songartist)) {
				front->next = tempnext->next;
				return ret;
			}
			else {
				front = front->next;
			}
		}
		return ret;
	}

}

struct song_node * free_list(struct song_node * exm) {

        struct song_node * ret = exm;
        if (exm == NULL) {
                printf("\n");
        }
        else {
                free(exm);
                free_list(exm->next);
        }
        return ret;

}

// int main(){
//   return 0;
// }
