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

struct song_node * make(char * song, char * artist){
  struct song_node * s = malloc(sizeof(struct song_node));
  strcpy(s->song_name,song);
  strcpy(s->song_artist,artist);
  return s;
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

struct song_node * remove_node(struct song_node * front, char * s) {

        struct song_node * ret = front;
        struct song_node * temp;
        struct song_node * temp2;
	char * p;
	p = front->song_name;
        if (!strcmp(p, s)) {
                temp = front->next;
                front->next = NULL;
                return temp;
        }
        while(front->next) {
                temp2 = front->next;
		p = front->song_name;
                if (!strcmp(p, s)) {
                        temp = front->next;
                        front->next = temp2->next;
                        free(temp);
                }
                else {
                        front = front->next;
                }

        }
        return ret;

}

int main(){
  return 0;
}
